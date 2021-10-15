#pragma once
#include "../lib/myMath/Vec2.hpp"
#include <vector>

class Agent{
private:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextPosition;
	double m_bodySize;
	double m_viewAngle;

public:
	Agent() {}; // Constructeur avec argument par défaut
	Agent(Vec2 m_position, Vec2 m_velocity);
	~Agent() {}; // Destructeur

public:
	Vec2 getPosition();
	Vec2 getVelocity();

	void computePosition();
	void updatePosition();
};