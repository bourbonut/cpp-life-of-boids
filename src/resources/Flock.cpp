#include "Flock.hpp"
#include "Bird.hpp"
#include "../lib/myMath/Vec2.hpp"
#include "../lib/myMath/utils.hpp"
#include "../lib/myLaws/Law.hpp"
#include <array>
#include <random>
#include <vector>


Flock::Flock(int popSize) : m_birdsVec{popSize}{ // need to instanciate the vector like this otherwise it won't work ???

	//std::vector<Bird> m_birdsVec(popSize);
	for (int i = 0; i < popSize; ++i)
	{
		m_birdsVec[i] = Bird{};
	}
	//std::cout << "popSize : " << m_birdsVec.size() << "\n";
};

Flock::Flock() {
	//m_popSize = RANDOM SINON createPopulation va pas marcher
	std::vector<Bird> m_birdsVec(0);
};

int Flock::getPopSize() const {
	return m_birdsVec.size();
};


void Flock::createPopulation() {
	m_birdsVec.reserve(1000000); // Should we do that?
	std::random_device dev;  // After we have to replace this lines for a vec2.random
	for (int i = 0; i < m_birdsVec.size(); ++i)
	{
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> rand600(0, 600);
		std::uniform_int_distribution<std::mt19937::result_type> rand2(0, 2);
		//Vec2 position = Vec2(5, 10);  //random(0, 100);
		Vec2 position = Vec2(rand600(rng), rand600(rng));  //random(0, 100);
		Vec2 velocity = Vec2(rand2(rng), rand2(rng));  //random(0, 5);
		//Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
		m_birdsVec.emplace_back(Bird(position, velocity));
	}
};

void Flock::calculatePositions() {
	for (auto & bird : m_birdsVec)
	{ 
		const std::vector<Bird> neighbors = this->computeNeighbors(bird, 0,0); //TODO : CHANGE THIS CALL
		bird.updateVelocity(neighbors);
		bird.computePosition();
	}
};

void Flock::updatePositions() {
	for (auto & bird : m_birdsVec)
	{
		bird.updatePosition();  // replace for a range function
	}

};

//why double && ? and m_popSize is juste m_birdsVec.size(), so no need ?
void Flock::addAgent() {
	Vec2 position = Vec2(500, 500);  //random(0, 100);
	Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
	m_birdsVec.emplace_back(position, velocity); // emplace_back more efficient than push_back
};

//see if we need a const &b or not ?
void Flock::addAgent(Bird b) {
	m_birdsVec.emplace_back(b);
};

void Flock::destroyAgent(Vec2 position) {
	auto garbageBirdsVec = std::remove_if(m_birdsVec.begin(), m_birdsVec.end(),
		[pos = position](Bird bird) {
			// If distance < 1, destroy bird 
			return (bird.getPosition() - pos).norm() < 1; });
	m_birdsVec.erase(garbageBirdsVec);
};

std::vector<Bird> Flock::computeNeighbors(const Bird& bird, const float &range, const float &angle) {
	std::vector<Bird> neighbors;
	neighbors.reserve(m_birdsVec.size()); //CHANGE THIS TO SMTHING LIKE popSize*2 OR SMTHNG

	//float angle = myBird.getViewAngle();
	//float Neighbor.radius = myBird.getRadius();

	//Like this one bird is going to be its own potential neighbor
	for (Bird potentialNeighbor : m_birdsVec){
		if (distance(bird.getPosition(), potentialNeighbor.getPosition()) <= range) { //only range because was scared of angle
			neighbors.emplace_back(potentialNeighbor);
		}
	}
	//	if distance(Vec2 Birds, Vec2 Bird[i]) <= Neighbor.radius && degrees(mybird.getVelocity().angle(neighbor)) <= angle{
	//		{

	//		birds.push_back(Bird{j});



	//	}

	//	}
	return neighbors;
};

void Flock::moveAgents() {
	//TODO :
};

void Flock::print() {
	std::cout << "Printing Flock :\n";
	int i = 0;
	for (Bird b : m_birdsVec) {
		std::cout << ++i << " : Pos(" << b.getPosition().x << ", " << b.getPosition().y << ")  //  Vel(" << b.getVelocity().x << ", " << b.getVelocity().y << ")" << std::endl;
	}
};

Bird Flock::getAgent(int index) {
	return this->m_birdsVec.at(index);
};

