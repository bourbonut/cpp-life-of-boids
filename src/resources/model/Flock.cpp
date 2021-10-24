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


//Flock::Flock(int popSize) : m_birdsVec(popSize){ // need to instanciate the vector like this otherwise it won't work ???
//
//	//std::vector<Bird> m_birdsVec(popSize);
//	for (int i = 0; i < popSize; ++i)
//	{
//		m_birdsVec[i] = Bird{};
//	}
//	//std::cout << "popSize : " << m_birdsVec.size() << "\n";
//};

Flock::Flock(std::vector<Agent*> population) : m_agents(population) {};


int Flock::getPopSize() const {
	return m_agents.size();
};


//void Flock::addAgent() {
//	Vec2 position = Vec2(500, 500);  
//	Vec2 velocity = Vec2(-2, 1); 
//
//	m_agents.emplace_back(position, velocity);
//};

//void Flock::addAgent(float xpos, float ypos) {
//	Vec2&& position = Vec2(xpos, ypos); 
//	Vec2&& velocity = Vec2(-2, 1); 
//	m_agents.emplace_back(position, velocity); 
//};

//see if we need a const &b or not ?
void Flock::addAgent(Agent *a) {
	m_agents.push_back(a);
};

void Flock::destroyAgent(Vec2 position) {
	auto garbageAgents = std::remove_if(m_agents.begin(), m_agents.end(),
		[pos = position](Agent *a) {
			// If distance < 1, destroy bird
			bool destroyBool = ((*a).getPosition() - pos).norm() < 1;
			if (destroyBool) { delete a; };

			return destroyBool; });

	m_agents.erase(garbageAgents, m_agents.end());

};

void Flock::destroyLastAgent() {
	//std::cout << "called destroyLastAgent function" << std::endl;
	Agent *ptr = getAgent(getPopSize() - 1);
	//std::cout << "ptr defined" << std::endl;
	delete ptr;
	//std::cout << "ptr deleted" << std::endl;
	m_agents.pop_back();
	//std::cout << "finished destroyLastAgent function" << std::endl;
};

std::tuple<std::vector<Agent*>, std::vector<Agent*>> Flock::computeNeighbors(
			const Agent& agent){//, const float &range, const float &angle) {

	std::vector<Agent*> neighbors;
	std::vector<Agent*> neighborsPredators;
	neighbors.reserve(m_agents.size()); //CHANGE THIS TO SMTHING LIKE popSize*2 OR SMTHNG

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

//Agent* Flock::computeNearestNeighbors(const Agent& agent, const std::vector<Agent*> neighbors) {}

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

