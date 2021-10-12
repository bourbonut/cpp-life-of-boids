#pragma once

#include "myMath/Vec2.hpp"
#include <vector>

class Bird {
private:
	// Use an ID attribute?
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextVelocity;
	Vec2 m_nextPosition; // A copier dans velocity
	double m_bodySize { 1 };
	double m_viewAngle;
	double m_COHESION_RANGE;
	double m_NEIGHBOR_RANGE;
	double m_SEPARATION_RANGE;
	double m_ALIGNMENT_RELAXATION;
	double m_COHESION_RELAXATION;

	std::vector<Bird> m_neighbors;

public:
	Bird() {} // Constructeur avec argument par défaut
	Bird(Vec2 m_position, Vec2 m_velocity);
	~Bird() {} // Destructeur

public:
	Vec2 getPosition(); // Do we need it?
	Vec2 getVelocity();

	const std::vector<Bird> computeNeighbors();
	void updateVelocity(const std::vector<Bird>& neighbors);
	void computePosition();
	void updatePosition();
	Vec2 cohesion(const std::vector<Bird>& neighbors) {
		return {};
	}
	Vec2 alignment(const std::vector<Bird>& neighbors) {
		return {};
	}
	Vec2 separation(const std::vector<Bird>& neighbors) {
		return {};
	}
};


