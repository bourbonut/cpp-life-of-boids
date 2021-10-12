#include "Flock.hpp"
#include "Bird.hpp"
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"

#include <array>
#include <vector>


Flock::Flock(int popSize) {
	std::vector<Bird> m_birdsVec(m_popSize);
	std::vector<Vec2> m_nextPos(m_popSize);
	m_popSize = m_popSize;
	this->createPopulation();
};

Flock::Flock() {
	//m_popSize
	std::vector<Bird> m_birdsVec(0);
	std::vector<Vec2> m_nextPos(0);

	this->createPopulation();
};

void Flock::createPopulation() {
	for (int i = 0; i < m_popSize; ++i)
	{
		Vec2 position = Vec2(5, 10);  //random(0, 100);
		Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
		m_birdsVec[i] = Bird(position, velocity);
		m_birdsVec.reserve(m_popSize + 100); // Should we do that?
		// m_nextPos[i] = position;
	}
};

void Flock::calculatePositions() {
	for (Bird bird : m_birdsVec)
	{   // To add user interaction, we can include here an if statement according to the bird 
		// position and use a function similar to updateVelocity. Or, we can add the user 
		// interaction (like a new bird) directly to computeNeighbors function.
		const std::vector<Bird> neighbors = this->computeNeighbors(bird);
		bird.updateVelocity(neighbors);
		bird.computePosition();
	}
};

void Flock::updatePositions(){
	for (Bird bird : m_birdsVec)
	{
		bird.updatePosition();
	}
};

void Flock::addAgent() {
	Vec2 &&position = Vec2(5, 10);  //random(0, 100);
	Vec2 &&velocity = Vec2(-2, 1);  //random(0, 5);
	m_birdsVec.emplace_back(position, velocity); // emplace_back more efficient than push_back
	// m_nextPos.push_back(position);
	m_popSize += 1;
};

void Flock::destroyAgent(Vec2 position) {
	auto garbageBirdsVec = std::remove_if(m_birdsVec.begin(), m_birdsVec.end(),
										  [pos = position](Bird bird) { 
											// If distance < 1, destroy bird 
										   return (bird.getPosition() - pos).norm() < 1; });
	m_birdsVec.erase(garbageBirdsVec);
};