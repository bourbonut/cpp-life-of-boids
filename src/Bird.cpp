
#include "Bird.hpp"

#include <array>
#include <vector>
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"

Bird::Bird(Vec2 position, Vec2 velocity) {
	m_position = position;
	m_velocity = velocity;
	m_nextPosition = position;
};

Vec2 Bird::getPosition() {
	return m_position; // Do we need it ?
};

Vec2 Bird::getVelocity() {
	return m_velocity; // Do we need it?
};

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = cohesion(neighbors);
	Vec2 vecAlignment = alignment(neighbors);
	Vec2 vecSeparation = separation(neighbors);
	Vec2 vec_displacement = vecCohesion + vecAlignment + vecSeparation;
	m_velocity = m_velocity + vec_displacement;  // The change in velocity impacts the laws?
};

void Bird::computePosition() {
	m_nextPosition = m_position + m_velocity;
};

void Bird::updatePosition() {
	m_position = m_nextPosition;
};
