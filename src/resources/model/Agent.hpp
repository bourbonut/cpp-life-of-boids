#pragma once
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include <vector>
static int id = 0;

class Agent{
protected:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextPosition;
	Vec2 m_nextVelocity;
	double m_bodySize = 1;
	double m_viewAngle = 270;
	double m_range = 50;

protected:
	Agent(const int& lVelocity, const int& uVelocity); 
	Agent(const Vec2& position, const Vec2& velocity);

public:
	int _id = ++id;
	virtual void computeLaws(const std::vector<Agent*>& neighbors) = 0;
	void prepareMove();
	void move();

	void setPosition(const Vec2& newPos);
	void setNextPosition(const Vec2& newPos);
	Vec2 getPosition() const;
	Vec2 getVelocity() const;
	Vec2 getNextVelocity() const;
	Vec2 getNextPosition() const;
	double getRange() const;
	double getViewAngle() const;

	Agent& operator=(const Agent& other);

};