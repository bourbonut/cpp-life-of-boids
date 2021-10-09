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
	void cohesion(std::vector<Bird> neighbors);
	void alignment(std::vector<Bird> neighbors);
	void separation(std::vector<Bird> neighbors);
	void updateVelocity();
};