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
	//double COHESION_RANGE;
	//double NEIGHBOR_RANGE;
	//double SEPARATION_RANGE;
	//double ALIGNMENT_RELAXATION;
	//double COHESION_RELAXATION;

	std::vector<Bird> m_neighbors;

public:
	Bird(); // Constructeur avec argument par défaut
	Bird(const vec2& position, const vec2& velocity);
	~Bird(); // Destructeur

public:
	vec2 getPosition();
	vec2 getVelocity();

	void computeNeighbors();
	vec2 cohesion(const std::vector<Bird>& neighbors);
	vec2 alignment(std::vector<Bird> neighbors);
	vec2 separation(std::vector<Bird> neighbors);
	void updateVelocity();

	vec2 calculateDistance();

	vec2 computeAgentsBarycenter(const std::vector<Bird> &neighbors);
	vec2 computeBarycenter(const std::vector<vec2> &points);

	std::vector<vec2> getCoordinatesArray(const std::vector<Bird>& neighbors);
};