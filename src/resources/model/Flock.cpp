#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>
#include <omp.h>

#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Bird.hpp"
#include "Eagle.hpp"
#include "Flock.hpp"
#define CRITICAL_FLOCK_SIZE 2500  // at this point, we start to have fps issues
using pairNP = std::pair<std::vector<Agent *>, std::vector<Agent *>>;
using pair = std::pair<Vec2, Agent *>;
using dict = std::unordered_map<int, std::vector<pair>>;

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
  if (size > 700) {
    std::cout << "Size of flock over 700, using the optimized version of compute neighbors.\nIf "
                 "you want to use predators, you might prefer generating a small flock (size under "
                 "700). Optimized version is in beta."
              << std::endl;
  }
  if (size > CRITICAL_FLOCK_SIZE) {
    std::cout << "\nWARNING : Flock size is over " << CRITICAL_FLOCK_SIZE
              << ", the program might have frame rate issues." << std::endl;
  }
};

int Flock::getPopSize() const { return (int)m_agents.size(); };

Flock::Flock(){};

void Flock::addAgent(Agent *a) { m_agents.emplace_back(a); };

void Flock::addBornAgent(Agent *agent) { m_bornAgents.push_back(agent); }

Agent *Flock::getAgent(int index) { return m_agents.at(index); };

void Flock::print() {
  std::cout << "Printing Flock :\n";
  int i = 0;
  for (Agent *b : m_agents) {
    std::cout << ++i << " : Pos(" << (*b).getPosition().x << ", " << (*b).getPosition().y
              << ") 	//  Vel(" << (*b).getVelocity().x << ", " << (*b).getVelocity().y << ")"
              << std::endl;
  }
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
  auto garbageAgents = std::remove_if(m_agents.begin(), m_agents.end(), [](Agent *a) {
    bool destroyBool = ((*a).getDestruction());
    if (destroyBool) {
      delete a;
    };
    return destroyBool;
  });
  m_agents.erase(garbageAgents, m_agents.end());
  for (Agent *a : m_bornAgents) {
    m_agents.push_back(a);
  }
  m_bornAgents.clear();
};

void Flock::destroyLastAgent() {
  Agent *ptr = getAgent(getPopSize() - 1);
  delete ptr;
  m_agents.pop_back();
};

pairNP Flock::computeNeighbors(const Agent &agent, const float &width, const float &height) {
  Vec2 pos = agent.getPosition();
	Vec2 vel = agent.getVelocity();
  double velNorm = vel.norm();
  double range = agent.getRange();
  float viewAngle = std::cos(radians(agent.getViewAngle()) * 0.5);
  Vec2 normalized_pos = pos + Vec2(width, height);
  int i = (int)(normalized_pos.x / 50);
  int j = (int)(normalized_pos.y / 50);
  std::vector<pair> potentialNeighbors;
  std::vector<pair> *ptr;
  for(int i_ = i - 1; i_ <= i + 1; i_ ++){
    for(int j_ = j - 1; j_ <= j + 1; j_ ++){
      ptr = &m_grid[i_ * i_ + j_];
      potentialNeighbors.insert(potentialNeighbors.begin(), (*ptr).begin(), (*ptr).end());
    }
  }

  std::vector<Agent *> neighbors;
  std::vector<Agent *> neighborsPredators;
  neighbors.reserve(potentialNeighbors.size());
  for (pair data : potentialNeighbors) {
    Vec2 neighbor = std::get<0>(data);
    Vec2 diff = neighbor - pos;
    double norm = diff.norm();
		if(norm <= range && vel.dot(diff) / (velNorm * norm)  > viewAngle){
      Agent *potentialNeighbor = std::get<1>(data);
      if (dynamic_cast<Bird *>(potentialNeighbor) != nullptr) {
        neighbors.push_back(potentialNeighbor);
      } else if (dynamic_cast<Eagle *>(potentialNeighbor) != nullptr) {
        neighborsPredators.push_back(potentialNeighbor);
      }
    }
  }
  return std::make_pair(neighbors, neighborsPredators);
}

pairNP Flock::computeNeighborsOrigin(const Agent &agent) {
  std::vector<Agent *> neighbors;
  std::vector<Agent *> neighborsPredators;
  neighbors.reserve(m_agents.size());

  // Like this one bird is going to be its own potential neighbor
  for (Agent *potentialNeighbor : m_agents) {
    if (!(degrees((agent.getPosition() - (*potentialNeighbor).getPosition()).angle()) > agent.getViewAngle() / 2) && !(agent._id == (*potentialNeighbor)._id)) {
      double distWithPotNeighb = distance(agent.getPosition(), (*potentialNeighbor).getPosition());
      if (fabs(distWithPotNeighb) <= (float)abs(agent.getRange())) {
        if (dynamic_cast<Bird *>(potentialNeighbor) != nullptr) {
          neighbors.push_back(potentialNeighbor);
        } else if (dynamic_cast<Eagle *>(potentialNeighbor) != nullptr) {
          neighborsPredators.push_back(potentialNeighbor);
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
    int i = (int)(normalized_pos.x / 50);
    int j = (int)(normalized_pos.y / 50);
    m_grid[i * i + j].push_back(std::make_pair(pos, a));
  }
}

void Flock::updateAgents(const bool &run_boids, const float &width, const float &height) {
  if (run_boids) {
    this->updateGrid(width, height);
    #pragma omp parallel for
    for (Agent *bird : m_agents) {
      (*bird).computeLaws(this->getNeighbors(*bird, width, height));
      (*bird).prepareMove();
    }
    #pragma omp parallel for
    for (Agent *bird : m_agents) {
      (*bird).keepPositionInScreen(width, height);
      (*bird).move();
    }
    m_grid.clear();
  }
}
