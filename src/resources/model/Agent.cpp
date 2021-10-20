#include "Agent.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"

Agent::Agent(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const Color& color)
{
	m_color = color;
	switch (m_color)
	{
	case Color::Red:
		m_GLColor = { 1.f, 0.f, 0.f };
		break;
	case Color::Green:
		m_GLColor = { 0.f, 1.f, 0.f };
		break;
	case Color::Blue:
		m_GLColor = { 0.f, 0.f, 1.f };
		break;
	default:
		m_GLColor = { 1.0f,1.0f,1.0f };
		break;
	}

	m_position = position;
	m_velocity = velocity;
	m_bodySize = bodySize;
	m_viewAngle = viewAngle;
	m_range = range;

};

Agent::Agent(const int &lVelocity, const int& uVelocity, const double& bodySize,
	const double& viewAngle) {
	Vec2 pos = randomVec2Generation(0, 1000);
	Vec2 vel = randomVec2Generation(lVelocity, uVelocity);
	m_position = pos;
	m_velocity = vel;
	m_nextPosition = pos + 1;
	m_nextVelocity = vel + 1;
	m_bodySize = bodySize;
	m_viewAngle = viewAngle;
	m_range = 50;
};

Agent::Agent(const Vec2& position, const Vec2& velocity, const double& bodySize, 
	const double& viewAngle, const double& range) {
	m_position = position;
	m_velocity = velocity;
	m_bodySize = bodySize;
	m_viewAngle = viewAngle;
	m_range = range;
};


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

int Agent::getRange() const {
	return m_range;
};

int Agent::getViewAngle() const {
	return m_viewAngle;
};

int Agent::getBodySize() const {
	return m_bodySize;
}

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

std::array<float, 3> Agent::getGLColor() const {
	return m_GLColor;
};

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

