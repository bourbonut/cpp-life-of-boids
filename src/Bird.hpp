#pragma once

#include <array>
#include <vector>

using vec2 = std::array<float, 2>;

class Bird {
private:
	vec2 m_position;
	vec2 m_velocity;
	vec2 m_nextVelocity; // A copier dans velocity
	double m_bodySize = 1;
	double m_viewAngle;
	double m_COHESION_RANGE;
	double m_NEIGHBOR_RANGE;
	double m_SEPARATION_RANGE;
	double m_ALIGNMENT_RELAXATION;
	double m_COHESION_RELAXATION;

	std::vector<Bird> m_neighbors;

public:
	Bird(); // Constructeur avec argument par défaut
	Bird(vec2 m_position, vec2 m_velocity);
	~Bird(); // Destructeur

public:
	vec2 getPosition();
	vec2 getVelocity();

	std::vector<Bird> computeNeighbors();
	vec2 m_vec_cohesion = cohesion(neighbors);
	vec2 m_vec_alignment = alignment(neighbors);
	vec2 m_vec_separation = separation(neighbors);
	void updateVelocity(m_vec_cohesion, m_vec_alignment, m_vec_separation);
	void updatePosition()
};

void Bird::updateVelocity(vec2 m_vec_cohesion, vec2 m_vec_alignment, vec2 m_vec_separation) { // Pq?
	vec2 vec_displacement = m_vec_cohesion + m_vec_alignment + m_vec_separation;
	m_velocity += vec_displacement;
};

void Bird::updatePosition() {
	m_position += m_velocity;
};


class Flock {

public:
	int m_popsize;
	std::vector<Bird> m_birds_vec;
	std::vector<vec2> m_next_pos;
	void create_population();
	void calculate_positions();
	void add_agent();
	void destroy_agent();  // Any ideas??
	void move_agents();
	void random(float min, float max);

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	~Flock(); // Destructeur
};

Flock::Flock(int m_popsize) {
	std::vector<Bird> m_birds_vec (m_popsize);
	std::vector<vec2> m_next_pos (m_popsize);
	
	create_population();
};

void Flock::create_population() {
	for (int i = 0; i < m_popsize; ++i)
	{
		vec2 position = vec2(5, 10);  //random(0, 100);
		vec2 velocity = vec2(-2, 1);  //random(0, 5);
		Bird bird = Bird(position, velocity);
		m_birds_vec[i] = bird;  // Does it modify the class attribute?
								// We should be able to add elements to m_birds_vec. Does a "vector" allows that?
	}
};

void Flock::add_agent() {
	vec2 position = vec2(5, 10);  //random(0, 100);
	vec2 velocity = vec2(-2, 1);  //random(0, 5);
	Bird bird = Bird(position, velocity);
	m_birds_vec.push_back(bird);
};