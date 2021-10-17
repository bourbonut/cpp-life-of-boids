#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"

Vec2 Agent::getPosition() const{
	return m_position; 
};

Vec2 Agent::getVelocity() const {
	return m_velocity;
};

double Agent::getRange() const {
	return m_range;
};

void Agent::move() {
	m_position += m_velocity;
};

void Agent::setPosition(const Vec2& newPos) {
	; m_position = newPos;
};

Agent& Agent::operator=(const Agent& other)
{
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_bodySize = other.m_bodySize;
	m_range = other.m_range;
	m_viewAngle = other.m_viewAngle;

	return *this;
};