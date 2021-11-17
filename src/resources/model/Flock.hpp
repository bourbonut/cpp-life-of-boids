#pragma once
#include "../../lib/myMath/Vec2.hpp"
#include "Bird.hpp"
#include "vector"
#include <tuple>
#include <functional>
#include <utility>
#include <unordered_map>

using tupleNP = std::tuple<std::vector<Agent*>, std::vector<Agent*>>;
using pair = std::pair<Vec2, Agent*>;
using dict = std::unordered_map<int, std::vector<pair>>;

class Flock {
public :
	//std::vector<Bird> m_birdsVec;
	std::vector<Agent*> m_agents;
	std::vector<Agent*> m_bornAgents;
	std::function<tupleNP( const Agent& agent, const float& width, const float& height )> getNeighbors;
	dict m_grid;

public:
	void print();
	int getPopSize() const;
	Agent* getAgent(int index);
	Agent* operator[](int index) { return m_agents.at(index); };
	tupleNP computeNeighbors(const Agent& agent, const float& width, const float& height);
	tupleNP computeNeighborsOrigin(const Agent& agent);

	void addAgent(Agent *a);
	void setAgentsToBeDestroyed(const Vec2& position, const int& destroyRadius);
	void removeEatenBirds();
	void destroyLastAgent();
	void addBornAgent(Agent* agent);
	void updateGrid(const float& width, const float& height);
	void updateAgents(const bool& run_boids, const float& width, const float& height);

public:
	Flock(std::vector<Agent*> population);
	Flock();
	~Flock() {}; // Destructeur

	auto begin() { return m_agents.begin(); };
	auto end() { return m_agents.end(); };

};
