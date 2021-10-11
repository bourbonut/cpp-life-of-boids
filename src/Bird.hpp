#pragma once

#include "myMath/Vec2.hpp"
#include <vector>

class Bird {
private:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextVelocity; // A copier dans velocity
	double m_bodySize = 1;
	double m_viewAngle;
	double m_COHESION_RANGE;
	double m_NEIGHBOR_RANGE;
	double m_SEPARATION_RANGE;
	double m_ALIGNMENT_RELAXATION;
	double m_COHESION_RELAXATION;

	std::vector<Bird> m_neighbors;

public:
	Bird(); // Constructeur avec argument par d�faut
	Bird(const vec2& position, const vec2& velocity);
	~Bird(); // Destructeur

public:
	Vec2 getPosition();
	Vec2 getVelocity();

	std::vector<Bird> computeNeighbors();
	void updateVelocity(const std::vector<Bird>& neighbors);
	void updatePosition();
	Vec2 cohesion(const std::vector<Bird>& neighbors;
	Vec2 alignment(const std::vector<Bird>& neighbors);
	Vec2 separation(const std::vector<Bird>& neighbors);
	vec2 getCoordinatesArray(const std::vector<Bird>& neighbors);
	vec2 computeBarycenter(const std::vector<vec2> &points);
	vec2 computeAgentsBarycenter(const std::vector<Bird> &neighbors);
};



	std::vector<Vec2> getCoordinatesArray(const std::vector<Bird>& neighbors);
};