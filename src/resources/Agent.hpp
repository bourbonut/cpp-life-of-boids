#pragma once
#include "../lib/myMath/Vec2.hpp"

class Agent{
private:
	Vec2 m_position;
	Vec2 m_velocity;
	double m_bodySize;
	double m_viewAngle;
	double m_range;

public:
	Agent(Vec2 m_position, Vec2 m_velocity);

	virtual void computeLaws() = 0;
	void move();

	Vec2 getPosition() const;
	Vec2 getVelocity() const;
};