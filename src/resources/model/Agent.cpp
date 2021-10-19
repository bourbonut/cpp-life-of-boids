#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"

Vec2 Agent::getPosition() const{
	return m_position; 
};

Vec2 Agent::getVelocity() const {
	return m_velocity;
};

Vec2 Agent::getNextPosition() const {
	return m_nextPosition;
};

Vec2 Agent::getNextVelocity() const {
	return m_nextVelocity;
};

double Agent::getRange() const {
	return m_range;
};

double Agent::getViewAngle() const {
	return m_viewAngle;
};

void Agent::move() {
	m_position = m_nextPosition;
	m_velocity = m_nextVelocity;
};

void Agent::prepareMove() {
	m_nextPosition = m_position + m_nextVelocity;
}

void Agent::setPosition(const Vec2& newPos) {
	m_position = newPos;
};

void Agent::setNextPosition(const Vec2& newPos) {
	m_nextPosition = newPos;
}

Agent& Agent::operator=(const Agent& other)
{
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_nextPosition = other.m_nextPosition;
	m_nextVelocity = other.m_nextVelocity;
	m_bodySize = other.m_bodySize;
	m_range = other.m_range;
	m_viewAngle = other.m_viewAngle;

	return *this;
};

