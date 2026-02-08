#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>
#include <omp.h>
#include "tbb/parallel_for.h"
#include "tbb/task_arena.h"

#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Bird.hpp"
#include "Eagle.hpp"
#include "Flock.hpp"

using pair = std::pair<Vec2, Agent *>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;
using dict = std::unordered_map<std::pair<int, int>, std::vector<pair>, pairhash>;

Flock::Flock(std::vector<Agent *> population) : m_agents(population) {
  int size = (int)m_agents.size();
  if (size > 700) {
    getNeighbors = [this](const Agent &agent, const float &width, const float &height) {
      return this->computeNeighbors(agent, width, height);
    };
  } else {
    getNeighbors = [this](const Agent &agent, const float &, const float &) {
      return this->computeNeighborsOrigin(agent);
    };
  }
};

std::string Flock::string() const {
  std::string string = "Flock(\n";
  for (Agent *agent : m_agents) string += "\tAgent(" + (*agent).string() + ")\n";
  return string + ")";
};

void Flock::setAgentsToBeDestroyed(const Vec2 &position, const int &destroyRadius) {
  for (auto &bird : m_agents) {
    bool destroyBool = ((*bird).getPosition() - position).norm() < destroyRadius;
    if (destroyBool) {
      (*bird).setDestruction();
    };
  }
}

void Flock::removeEatenBirds() {
  auto garbageAgents = std::remove_if(
    m_agents.begin(),
    m_agents.end(),
    [](Agent *a) {
      bool destroyBool = ((*a).getDestruction());
      if (destroyBool) {
        delete a;
      }
      return destroyBool;
    }
  );
  m_agents.erase(garbageAgents, m_agents.end());
  
  for (Agent *a : m_bornAgents) {
    m_agents.push_back(a);
  }
  m_bornAgents.clear();
  
  {
    std::unique_lock<std::shared_mutex> lock(m_gridMutex);
    m_grid.clear();
  }
};

void Flock::destroyLastAgent() {
  delete m_agents.back();
  m_agents.pop_back();
};

const pairNP Flock::computeNeighbors(const Agent &agent, const float &width, const float &height) {
  Vec2 pos = agent.getPosition();
	Vec2 vel = agent.getVelocity();
  double velNorm = vel.norm();
  double range = agent.getRange();
  float viewAngle = std::cos(radians(agent.getViewAngle()) * 0.5) * velNorm;
  Vec2 normalized_pos = pos + Vec2(width, height);
  int i = (int)(normalized_pos.x / m_precision);
  int j = (int)(normalized_pos.y / m_precision);

  std::vector<pair> neighbors;
  std::vector<pair> neighborsPredators;

  {
    std::shared_lock<std::shared_mutex> lock(m_gridMutex);
    for(int i_ = i - 1; i_ <= i + 1; i_ ++){
      for(int j_ = j - 1; j_ <= j + 1; j_ ++){
        for (const pair& data : m_grid[std::make_pair(i_, j_)]) {
          const Vec2 neighbor = std::get<0>(data);
          const Vec2 diff = neighbor - pos;
          const double norm = diff.norm();
          if(norm <= range && vel.dot(diff) / norm  > viewAngle){
            Agent *potentialNeighbor = std::get<1>(data);
            if (dynamic_cast<Bird *>(potentialNeighbor) != nullptr) {
              neighbors.push_back(data);
            } else if (dynamic_cast<Eagle *>(potentialNeighbor) != nullptr) {
              neighborsPredators.push_back(data);
            }
          }
        }
      }
    }
  }

  return std::make_pair(neighbors, neighborsPredators);
}

pairNP Flock::computeNeighborsOrigin(const Agent &agent) {
  std::vector<pair> neighbors;
  std::vector<pair> neighborsPredators;
  neighbors.reserve(m_agents.size());

  // Like this one bird is going to be its own potential neighbor
  for (Agent *potentialNeighbor : m_agents) {
    if (!(degrees((agent.getPosition() - (*potentialNeighbor).getPosition()).angle()) > agent.getViewAngle() / 2) && !(agent._id == (*potentialNeighbor)._id)) {
      double distWithPotNeighb = distance(agent.getPosition(), (*potentialNeighbor).getPosition());
      if (fabs(distWithPotNeighb) <= (float)abs(agent.getRange())) {
        if (dynamic_cast<Bird *>(potentialNeighbor) != nullptr) {
          neighbors.push_back(std::make_pair((*potentialNeighbor).getPosition(), potentialNeighbor));
        } else if (dynamic_cast<Eagle *>(potentialNeighbor) != nullptr) {
          neighborsPredators.push_back(std::make_pair((*potentialNeighbor).getPosition(), potentialNeighbor));
        }
      }
    }
  }
  return std::make_pair(neighbors, neighborsPredators);
};

void Flock::updateGrid(const float &width, const float &height) {
  Vec2 v = Vec2(width, height);
  for (Agent *a : m_agents) {
    Vec2 pos = (*a).getPosition();
    Vec2 normalized_pos = pos + v;
    int i = (int)(normalized_pos.x / m_precision);
    int j = (int)(normalized_pos.y / m_precision);
    m_grid[std::make_pair(i, j)].push_back(std::make_pair(pos, a));
  }
}

void Flock::updateAgents(const bool &run_boids, const float &width, const float &height) {
  if (run_boids) {
    {
      std::unique_lock<std::shared_mutex> lock(m_gridMutex);
      this->updateGrid(width, height);
    }
    
    #pragma omp parallel for
    for (Agent *bird : m_agents) {
      (*bird).computeLaws(this->getNeighbors(*bird, width, height));
    }
    
    // {
    //   std::unique_lock<std::shared_mutex> lock(m_gridMutex);
    //   m_grid.clear();
    // }
    
    for (Agent *bird : m_agents) {
      (*bird).prepareMove();
      (*bird).keepPositionInScreen(width, height);
      (*bird).move();
    }
  }
}

void Flock::experiment(const bool &run_boids, const float &width, const float &height, const int& nb_threads, const bool& thread_switch) {
  if (run_boids) {
    this->updateGrid(width, height);
    if(thread_switch){
      tbb::task_arena arena(nb_threads);
      arena.execute([&]{tbb::parallel_for(
        size_t(0),
        m_agents.size(),
        [&](size_t i){
          (*(m_agents[i])).computeLaws(this->getNeighbors(*(m_agents[i]), width, height));
        }
      );});
      arena.execute([&]{tbb::parallel_for(
        size_t(0),
        m_agents.size(),
        [&](size_t i){
          (*m_agents[i]).prepareMove();
          (*m_agents[i]).keepPositionInScreen(width, height);
          (*m_agents[i]).move();
        }
      );});
    } else {
      omp_set_num_threads(nb_threads);
      #pragma omp parallel for
      for (Agent *bird : m_agents) {
        (*bird).computeLaws(this->getNeighbors(*bird, width, height));
      }
      // #pragma omp parallel for
      for (Agent *bird : m_agents) {
        (*bird).prepareMove();
        (*bird).keepPositionInScreen(width, height);
        (*bird).move();
      }
    }
    m_grid.clear();
  }
}


std::ostream& operator<<(std::ostream& os, const Flock& obj)
{
    return os << obj.string();
}
