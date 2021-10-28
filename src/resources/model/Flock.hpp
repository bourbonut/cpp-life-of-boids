#pragma once

#include "../../lib/myMath/Vec2.hpp"
#include "vector"
#include <tuple>
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
	Agent* operator[](int index) { return m_agents.at(index); };
	std::tuple<std::vector<Agent*>, std::vector<Agent*>> computeNeighbors(const Agent& agent);

	void addAgent(Agent *a);
	void destroyAgent(const Vec2& position, const int& destroyRadius);
	void destroyLastAgent();

public:
	Flock(std::vector<Agent*> population);
	Flock();
	~Flock() {}; // Destructeur

	auto begin() { return m_agents.begin(); };
	auto end() { return m_agents.end(); };

};