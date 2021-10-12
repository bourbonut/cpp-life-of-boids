#include "Flock.hpp"
#include "Bird.hpp"
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"

#include <array>
#include <vector>


Flock::Flock(int m_popSize) {
	std::vector<Bird> m_birdsVec(m_popSize);
	std::vector<Vec2> m_nextPos(m_popSize);

	createPopulation();
};

void Flock::createPopulation() {
	for (int i = 0; i < m_popSize; ++i)
	{
		Vec2 position = Vec2(5, 10);  //random(0, 100);
		Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
		Bird bird = Bird(position, velocity);
		m_birdsVec[i] = bird;
		// m_nextPos[i] = position;
	}
};

void Flock::calculatePositions() {
	for (Bird bird : m_birdsVec)
	{   // To add user interaction, we can include here an if statement according to the bird 
		// position and use a function similar to updateVelocity. Or, we can add the user 
		// interaction (like a new bird) directly to computeNeighbors function.
		const std::vector<Bird> neighbors = bird.computeNeighbors();
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
	Vec2 position = Vec2(5, 10);  //random(0, 100);
	Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
	Bird bird = Bird(position, velocity);
	m_birdsVec.push_back(bird);
	// m_nextPos.push_back(position);
	m_popSize += 1;
};