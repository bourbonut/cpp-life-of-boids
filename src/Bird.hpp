#pragma once

#include "myMath/Vec2.hpp"
#include <vector>

class Bird {
private:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextVelocity; // A copier dans velocity
	double m_bodySize = 1;
	double m_viewAngle = 1;
	double m_COHESION_RANGE = 1;
	double m_NEIGHBOR_RANGE = 1;
	double m_SEPARATION_RANGE = 1;
	double m_ALIGNMENT_RELAXATION = 1;
	double m_COHESION_RELAXATION = 1;

	std::vector<Bird> m_neighbors;

public:
	Bird(); // Constructeur avec argument par d�faut
	Bird(Vec2 &position, Vec2 &velocity);
	~Bird(); // Destructeur

public:
	Vec2 getPosition() const;
	Vec2 getVelocity() const;

	//std::vector<Bird> computeNeighbors();
	void updateVelocity(const std::vector<Bird>& neighbors);
	void updatePosition();
	Vec2 cohesion(const std::vector<Bird>& neighbors);
	Vec2 alignment(const std::vector<Bird>& neighbors) { return {}; };
	Vec2 separation(const std::vector<Bird>& neighbors);
	std::vector<Vec2> getCoordinatesArray(const std::vector<Bird>& neighbors);
	//Vec2 computeBarycenter(const std::vector<Vec2> &points);
	Vec2 computeAgentsBarycenter(const std::vector<Bird> &neighbors);
};