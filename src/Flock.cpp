#include "Flock.hpp"
#include "Bird.hpp"

#include <array>
#include <vector>

using vec2 = std::array<float, 2>;

Flock::Flock(int m_popSize) {
	std::vector<Bird> m_birdsVec(m_popSize);
	std::vector<vec2> m_nextPos(m_popSize);

	create_population();
};

void Flock::create_population() {
	for (int i = 0; i < m_popSize; ++i)
	{
		vec2 position = vec2(5, 10);  //random(0, 100);
		vec2 velocity = vec2(-2, 1);  //random(0, 5);
		Bird bird = Bird(position, velocity);
		m_birdsVec[i] = bird;  // Does it modify the class attribute?
								// We should be able to add elements to m_birds_vec. Does a "vector" allows that?
	}
};

void Flock::add_agent() {
	vec2 position = vec2(5, 10);  //random(0, 100);
	vec2 velocity = vec2(-2, 1);  //random(0, 5);
	Bird bird = Bird(position, velocity);
	m_birdsVec.push_back(bird);
};