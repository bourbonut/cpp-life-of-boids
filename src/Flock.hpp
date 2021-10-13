#pragma once

#include "myMath/Vec2.hpp"
#include "vector"
#include "Bird.hpp"
// #include "myMath/utils.hpp"

class Flock {
private :
	int m_popSize;
	std::vector<Bird> m_birdsVec;
	// std::vector<Vec2> m_nextPos;

public:
<<<<<<< HEAD
<<<<<<< HEAD
	void print();
	int getPopSize() const;
	Bird getAgent(int index) const;
=======
=======
	std::vector<Bird> getBirdsVec();
>>>>>>> Changes to integrate to the next commit
>>>>>>> Changes to integrate to the next commit
=======
>>>>>>> Rebase conflicts
	void createPopulation();
	void calculatePositions();
	void updatePositions();
	std::vector<Bird> computeNeighbors(const Bird& bird, const float& range, const float& angle);
	void addAgent();
	void addAgent(Bird b);
	void destroyAgent(Vec2 position);
	void moveAgents();

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	~Flock() {}; // Destructeur

};