
#include "Bird.hpp"

#include <array>
#include <vector>
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"

Bird::Bird(Vec2 position, Vec2 velocity) {
	m_position = position;
	m_velocity = velocity;
	m_nextPosition = position;
	m_nextVelocity = velocity;
};

Bird::Bird() {
	m_position = Vec2(0, 0);
	m_velocity = Vec2(1, 1);
	m_nextPosition = Vec2(0, 0);
	m_nextVelocity = Vec2(1, 1);
};

Vec2 Bird::getPosition() {
	return m_position;
};

Vec2 Bird::getVelocity() {
	return m_velocity;
};

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = this->cohesion(neighbors);
	Vec2 vecAlignment = this->alignment(neighbors);
	Vec2 vecSeparation = this->separation(neighbors);
	Vec2 vec_displacement = vecCohesion + vecAlignment + vecSeparation;
	m_nextVelocity = m_velocity + vec_displacement;
};

void Bird::computePosition() {
	m_nextPosition = m_position + m_nextVelocity;
};

void Bird::updatePosition() {
	m_position = m_nextPosition;
	m_velocity = m_nextVelocity;
};
