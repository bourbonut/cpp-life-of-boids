#pragma once
#include "../../lib/myMath/Vec2.hpp"
#include "Bird.hpp"
#include <vector>
#include <functional>
#include <utility>
#include <unordered_map>

using pair = std::pair<Vec2, Agent*>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;
using dict = std::unordered_map<int, std::vector<pair>>;

class Flock {
private :
	double m_precision = 50.;
	std::vector<Agent*> m_agents;
	std::vector<Agent*> m_bornAgents;
	std::function<pairNP( const Agent& agent, const float& width, const float& height )> getNeighbors;
	dict m_grid;

public:
	int getPopSize() const { return (int)m_agents.size(); };
	Agent* operator[](int index) { return m_agents.at(index); };
	const pairNP computeNeighbors(const Agent& agent, const float& width, const float& height);
	pairNP computeNeighborsOrigin(const Agent& agent);

	void addAgent(Agent *a) { m_agents.emplace_back(a); };
	void setAgentsToBeDestroyed(const Vec2& position, const int& destroyRadius);
	void removeEatenBirds();
	void destroyLastAgent();
	void addBornAgent(Agent* agent) { m_bornAgents.push_back(agent); };
	void updateGrid(const float& width, const float& height);
	void updateAgents(const bool& run_boids, const float& width, const float& height);
	void experiment(const bool& run_boids, const float& width, const float& height, const int& nb_threads, const bool& thread_switch);
	std::string string() const;

public:
	Flock(std::vector<Agent*> population);
	Flock(){};
	~Flock(){};

	auto begin() { return m_agents.begin(); };
	auto end() { return m_agents.end(); };

};

std::ostream& operator<<(std::ostream& os, const Flock& obj);
