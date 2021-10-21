#include "Flock.hpp"
#include "Bird.hpp"
#include "../../lib/myMath/utils.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myLaws/Law.hpp"
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>


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


Flock::Flock(int popSize) {

	//for (int i = 0; i < popSize; ++i) { //this doesn't work with ptr
	//	m_agents.emplace_back(new Bird{});
	//}
};

Flock::Flock() {
	//m_popSize = RANDOM SINON createPopulation va pas marcher
	//std::vector<Bird> m_agents(0);

};

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

//void Flock::destroyAgent(Vec2 position) {
//	auto garbageBirdsVec = std::remove_if(m_birdsVec.begin(), m_birdsVec.end(),
//		[pos = position](Bird bird) {
//			// If distance < 1, destroy bird 
//			return (bird.getPosition() - pos).norm() < 1; });
//	m_birdsVec.erase(garbageBirdsVec);
//};

std::vector<Agent*> Flock::computeNeighbors(const Agent& agent){//, const float &range, const float &angle) {

	std::vector<Agent*> neighbors;
	neighbors.reserve(m_agents.size()); //CHANGE THIS TO SMTHING LIKE popSize*2 OR SMTHNG

	//Like this one bird is going to be its own potential neighbor
	for (Agent* potentialNeighbor : m_agents) {
		if (!(degrees((agent.getPosition() - (*potentialNeighbor).getPosition()).angle()) > agent.getViewAngle() / 2) && !(agent._id == (*potentialNeighbor)._id)) //!(potentialNeighbor.getPosition() == bird.getPosition()) && 
		{
			double distWithPotNeighb = distance(agent.getPosition(), (*potentialNeighbor).getPosition());
			double a = abs(distWithPotNeighb);
			if (abs(distWithPotNeighb) <= abs(agent.getRange())) { //only range because was scared of angle
				neighbors.push_back(potentialNeighbor);
			}
		}
	}
	return neighbors;
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

