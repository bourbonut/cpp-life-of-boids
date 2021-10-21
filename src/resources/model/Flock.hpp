#pragma once

#include "../../lib/myMath/Vec2.hpp"
#include "vector"
#include "Bird.hpp"
// #include "myMath/utils.hpp"

class Flock {
private :
	//std::vector<Bird> m_birdsVec;
	std::vector<Agent*> m_agents;

public:
	void print();
	int getPopSize() const;
	Agent* getAgent(int index);
	//void createPopulation();
	std::vector<Agent*> computeNeighbors(const Agent& agent);//, const float& range, const float& angle);
	//void addAgent();
	//void addAgent(float xpos, float ypos);

	void addAgent(Agent *a);
	void destroyAgent(Vec2 position);
	void destroyLastAgent();
	//void moveAgents();

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	Flock(std::vector<Agent*> population);
	~Flock() {}; // Destructeur

	//auto begin() { return m_birdsVec.begin(); };
	auto begin() { return m_agents.begin(); };
	//auto end() { return m_birdsVec.end(); };
	auto end() { return m_agents.end(); };

};