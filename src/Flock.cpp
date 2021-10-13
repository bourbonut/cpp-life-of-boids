#include "Flock.hpp"
#include "Bird.hpp"
#include "myMath/Vec2.hpp"
#include "myMath/utils.hpp"
// #include "myMath/utils.hpp"

#include <array>
#include <vector>
#include <random>


Flock::Flock(int popSize) : m_popSize{ popSize } {
	std::vector<Bird> m_birdsVec(m_popSize);
	std::vector<Vec2> m_nextPos(m_popSize);
	this->createPopulation();
};

Flock::Flock() {
	//m_popSize = RANDOM SINON createPopulation va pas marcher
	std::vector<Bird> m_birdsVec(0);
	std::vector<Vec2> m_nextPos(0);

};

int Flock::getPopSize() const {
	return m_birdsVec.size();
}


void Flock::createPopulation() {
	//m_birdsVec.reserve(m_popSize + 100); // Should we do that?
	for (int i = 0; i < m_popSize; ++i)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> rand100(0, 100);
		std::uniform_int_distribution<std::mt19937::result_type> rand2(0, 2);
		//Vec2 position = Vec2(5, 10);  //random(0, 100);
		Vec2 position = Vec2(rand100(rng), rand100(rng));  //random(0, 100);
		Vec2 velocity = Vec2(rand2(rng), rand2(rng));  //random(0, 5);
		//Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
		m_birdsVec.emplace_back(Bird(position, velocity));
		// m_nextPos[i] = position;
	}
};
//here when this will be called by line 21, m_popsize will be 0 so it won't iterate, and reserve here is in the iteration !
//void Flock::createPopulation() {
//	for (int i = 0; i < m_popSize; ++i)
//	{
//		Vec2 position = Vec2(5, 10);  //random(0, 100);
//		Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
//		m_birdsVec[i] = Bird(position, velocity);
//		m_birdsVec.reserve(m_popSize + 100); // Should we do that?
//		// m_nextPos[i] = position;
//	}
//};

void Flock::calculatePositions() {
	for (Bird bird : m_birdsVec)
	{   // To add user interaction, we can include here an if statement according to the bird 
		// position and use a function similar to updateVelocity. Or, we can add the user 
		// interaction (like a new bird) directly to computeNeighbors function.
		const std::vector<Bird> neighbors = this->computeNeighbors(bird, 0,0); //TODO : CHANGE THIS CALL
		bird.updateVelocity(neighbors);
		bird.computePosition();
	}
};

void Flock::updatePositions() {
	for (Bird bird : m_birdsVec)
	{
		bird.updatePosition();  // replace for a range function
	}

};

//why double && ? and m_popSize is juste m_birdsVec.size(), so no need ?
void Flock::addAgent() {
	Vec2&& position = Vec2(5, 10);  //random(0, 100);
	Vec2&& velocity = Vec2(-2, 1);  //random(0, 5);
	m_birdsVec.emplace_back(position, velocity); // emplace_back more efficient than push_back
	// m_nextPos.push_back(position);
	m_popSize += 1;
};

//see if we need a const &b or not ?
void Flock::addAgent(Bird b) {
	m_birdsVec.emplace_back(b);
}

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
	int i = 0;
	for (Bird b : m_birdsVec) {
		std::cout << ++i << " : Pos(" << b.getPosition().x << ", " << b.getPosition().y << ")  //  Vel(" << b.getVelocity().x << ", " << b.getVelocity().y << ")" << std::endl;
	}
}

Bird Flock::getAgent(int index) const {
	return this->m_birdsVec.at(index);
}