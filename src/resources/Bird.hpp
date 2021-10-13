#pragma once

#include "Agent.hpp"
#include "../lib/myMath/Vec2.hpp"
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


public:
	Bird(); // Constructeur sans arguments
	Bird(const Vec2 &position, const Vec2 &velocity);
	~Bird(); // Destructeur
	Vec2 getPosition() const;
	Vec2 getVelocity() const;
	Vec2 getNextPosition() const;
	Vec2 getNextVelocity() const;

	void updateVelocity(const std::vector<Bird>& neighbors);
	void computePosition();
	void updatePosition();
	Vec2 cohesion(const std::vector<Bird>& neighbors);
	Vec2 alignment(const std::vector<Bird>& neighbors) { return {}; };
	Vec2 separation(const std::vector<Bird>& neighbors);
	std::vector<Vec2> getCoordinatesArray(const std::vector<Bird>& neighbors);
	//Vec2 computeBarycenter(const std::vector<Vec2> &points);
	Vec2 computeAgentsBarycenter(const std::vector<Bird> &neighbors);
	void print() const;
};
