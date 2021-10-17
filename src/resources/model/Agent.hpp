#pragma once
#include "../../lib/myMath/Vec2.hpp"
#include <vector>

class Agent{
protected:
	Vec2 m_position;
	Vec2 m_velocity;
	double m_bodySize = 1;
	double m_viewAngle = 50;
	double m_range = 50;

public:
	virtual void computeLaws(const std::vector<Agent*>& neighbors) = 0;
	void move();

	void setPosition(const Vec2& newPos);
	Vec2 getPosition() const;
	Vec2 getVelocity() const;
	double getRange() const;

	Agent& operator=(const Agent& other);

};