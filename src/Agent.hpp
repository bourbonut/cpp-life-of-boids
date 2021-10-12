#pragma once

#include "myMath/Vec2.hpp"
#include "vector"
// #include "Bird.hpp"
// #include "myMath/utils.hpp"

Agent{
private:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextVelocity; // A copier dans velocity
	double m_bodySize;

public:
	Agent() {} // Constructeur avec argument par défaut
	Agent(Vec2 m_position, Vec2 m_velocity) {}
	~Agent() {} // Destructeur

public:
	Vec2 getPosition();
	Vec2 getVelocity();

	void computePosition();
	void updatePosition();
};