#include "Agent.hpp"
#include "../lib/myMath/Vec2.hpp"

Agent::Agent(Vec2 position, Vec2 velocity) {
	m_position = position;
	m_velocity = velocity;
};

Vec2 Agent::getPosition() const{
	return m_position; 
};

Vec2 Agent::getVelocity() const {
	return m_velocity;
};

void Agent::move() {
	m_position += m_velocity;
}