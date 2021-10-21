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

	for (int i = 0; i < popSize; ++i) { //this doesn't work with ptr
		m_agents.emplace_back(new Bird{});
	}
};

Flock::Flock() {
	//m_popSize = RANDOM SINON createPopulation va pas marcher
	std::vector<Bird> m_agents(0);

};

int Flock::getPopSize() const {
	return m_agents.size();
};


//void Flock::createPopulation() {
//	m_birdsVec.reserve(1000000); // Should we do that?
//	std::random_device dev;  // After we have to replace this lines for a vec2.random
//	for (int i = 0; i < m_birdsVec.size(); ++i)
//	{
//		std::mt19937 rng(dev());
//		std::uniform_int_distribution<std::mt19937::result_type> rand600(0, 600);
//		std::uniform_int_distribution<std::mt19937::result_type> rand2(0, 2);
//		//Vec2 position = Vec2(5, 10);  //random(0, 100);
//		Vec2 position = Vec2(rand600(rng), rand600(rng));  //random(0, 100);
//		Vec2 velocity = Vec2(rand2(rng), rand2(rng));  //random(0, 5);
//		//Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
//		m_birdsVec.emplace_back(Bird(position, velocity));
//	}
//};


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

