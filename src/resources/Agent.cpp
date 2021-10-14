#include "Agent.hpp"

#include <array>
#include <vector>
#include "../lib/myMath/Vec2.hpp"

// #include "myMath/utils.hpp"

Agent::Agent(Vec2 position, Vec2 velocity) {
	m_position = position;
	m_velocity = velocity;
	m_nextPosition = position;
};

Vec2 Agent::getPosition() {
	return m_position; // Do we need it ?
};

Vec2 Agent::getVelocity() {
	return m_velocity; // Do we need it?
};

void Agent::computePosition() {
	m_nextPosition = m_position + m_velocity;
};


void Agent::updatePosition() {
	m_position = m_position + m_velocity;
};