#pragma once

#include <array>
#include <vector>

using vec2 = std::array<float, 2>;

class Bird {
private:
	vec2 position;
	vec2 velocity;
	vec2 nextVelocity; // A copier dans velocity
	double bodySize = 1;
	double viewAngle;
	double COHESION_RANGE;
	double NEIGHBOR_RANGE;
	double SEPARATION_RANGE;
	double ALIGNMENT_RELAXATION;
	double COHESION_RELAXATION;

	std::vector<Bird> neighbors;

public:
	Bird(); // Constructeur avec argument par défaut
	Bird(vec2 position, vec2 velocity);
	~Bird(); // Destructeur

public:
	vec2 getPosition();
	vec2 getVelocity();

	void computeNeighbors();
	vec2 vec_cohesion = cohesion(std::vector<Bird> neighbors);
	vec2 vec_alignment = alignment(std::vector<Bird> neighbors);
	vec2 vec_separation = separation(std::vector<Bird> neighbors);
	void updateVelocity(vec2 vec_cohesion, vec2 vec_alignment, vec2 vec_separation);
	void updatePosition()
};

void Bird::updateVelocity(vec2 vec_cohesion, vec2 vec_alignment, vec2 vec_separation) {
	vec2 vec_displacement = vec_cohesion + vec_alignment + vec_separation;
	velocity += vec_displacement;
};

void Bird::updatePosition() {
	position += velocity;
};


class Flock {

public:
	void create_population();
	void calculate_positions();
	void add_agent();
	void destroy_agent();
	void move_agents();
	void random(float min, float max);

public:
	Flock(); // Constructeur avec argument par défaut
	Flock(int popsize);
	~Flock(); // Destructeur
};

Flock::Flock(int popsize) {
	std::array<float, popsize> birds_vec;
	std::array<float, popsize> next_pos;
	create_population();
};

Flock::create_population() {
	for (int i = 0; i < popsize; ++i)
	{
		vec2 position = random(0, 100);
		vec2 velocity = random(0, 5);
		Bird bird = Bird(position, velocity);
		birds_vec.push_back(bird);
	}
};