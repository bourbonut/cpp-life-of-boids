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
		m_birdsVec[i] = bird;  // Does it modify the class attribute?
								// We should be able to add elements to m_birds_vec. Does a "vector" allows that?
	}
};

void Flock::addAgent() {
	Vec2 position = Vec2(5, 10);  //random(0, 100);
	Vec2 velocity = Vec2(-2, 1);  //random(0, 5);
	Bird bird = Bird(position, velocity);
	m_birdsVec.push_back(bird);
};