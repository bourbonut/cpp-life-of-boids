#pragma once

#include "../lib/myMath/Vec2.hpp"
#include "vector"
#include "Bird.hpp"
// #include "myMath/utils.hpp"

class Flock {
private :
	std::vector<Bird> m_birdsVec;

public:
	void print();
	int getPopSize() const;
	Bird getAgent(int index);
	void createPopulation();
	void calculatePositions();
	void updatePositions();
	std::vector<Bird> computeNeighbors(const Bird& bird, const float& range, const float& angle);
	void addAgent();
	void addAgent(float xpos, float ypos);

	void addAgent(Bird b);
	void destroyAgent(Vec2 position);
	void moveAgents();

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	~Flock() {}; // Destructeur

	auto begin() { return m_birdsVec.begin(); };
	auto end() { return m_birdsVec.end(); };

};