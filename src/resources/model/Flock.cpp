#include "Flock.hpp"
#include "Bird.hpp"
#include "Eagle.hpp"
#include "../../lib/myMath/utils.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myLaws/Law.hpp"
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <tuple>

Flock::Flock(std::vector<Agent*> population) : m_agents(population) {};

int Flock::getPopSize() const {
	return m_agents.size();
};

Flock::Flock() {};

void Flock::addAgent(Agent *a) {
	m_agents.push_back(a);
};

void Flock::destroyAgent(const Vec2& position, const int& destroyRadius) {
	auto garbageAgents = std::remove_if(m_agents.begin(), m_agents.end(),
		[pos = position, destroyRadius](Agent* a) {
			// If distance < 1, destroy bird
			bool destroyBool = ((*a).getPosition() - pos).norm() < destroyRadius;
			if (destroyBool) { delete a; };

			return destroyBool; });

	m_agents.erase(garbageAgents, m_agents.end());

};

void Flock::destroyLastAgent() {
	Agent *ptr = getAgent(getPopSize() - 1);
	delete ptr;
	m_agents.pop_back();
};

std::tuple<std::vector<Agent*>, std::vector<Agent*>> Flock::computeNeighbors(
			const Agent& agent){//, const float &range, const float &angle) {

	std::vector<Agent*> neighbors;
	std::vector<Agent*> neighborsPredators;
	neighbors.reserve(m_agents.size()); 

	//Like this one bird is going to be its own potential neighbor
	for (Agent* potentialNeighbor : m_agents) {
		if (!(degrees((agent.getPosition() - (*potentialNeighbor).getPosition()).angle()) > agent.getViewAngle() / 2) && !(agent._id == (*potentialNeighbor)._id))
		{
			double distWithPotNeighb = distance(agent.getPosition(), (*potentialNeighbor).getPosition());
			double a = abs(distWithPotNeighb);
			if (abs(distWithPotNeighb) <= abs(agent.getRange())) { 
				if (dynamic_cast<Bird*> (potentialNeighbor) != nullptr) {
					neighbors.push_back(potentialNeighbor);
				}
				else if (dynamic_cast<Eagle*> (potentialNeighbor) != nullptr) {
					neighborsPredators.push_back(potentialNeighbor);
				}
			}	
		}
	}
	return std::make_tuple( neighbors, neighborsPredators );
};

void Flock::print() {
	std::cout << "Printing Flock :\n";
	int i = 0;
	for (Agent *b : m_agents) {
		std::cout << ++i << " : Pos(" << (*b).getPosition().x << ", " << (*b).getPosition().y << ")  //  Vel(" << (*b).getVelocity().x << ", " << (*b).getVelocity().y << ")" << std::endl;
	}
};

Agent* Flock::getAgent(int index) {
	return m_agents.at(index);
};

