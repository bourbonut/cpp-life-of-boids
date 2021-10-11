#pragma once

class Flock {

public:
	int m_popSize;
	std::vector<Bird> m_birdsVec;
	std::vector<vec2> m_nextPos;
	void create_population();
	void calculate_positions();
	void add_agent();
	void destroy_agent();  // Any ideas?? Destroy by position or index?
	void move_agents();
	vec2 random(float min, float max);

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	~Flock(); // Destructeur
};