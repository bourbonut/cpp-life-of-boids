#pragma once

#include "myMath/Vec2.hpp"
#include "vector"
#include "Bird.hpp"
// #include "myMath/utils.hpp"

class Flock {

public:
	int m_popSize;
	std::vector<Bird> m_birdsVec;
	// std::vector<Vec2> m_nextPos;
	void createPopulation();
	void calculatePositions();
	void updatePositions();
	std::vector<Bird> computeNeighbors(Bird bird) { return std::vector<Bird>{}; };
	void addAgent();
	void destroyAgent(Vec2 position);
	void moveAgents();

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	~Flock() {}; // Destructeur

};