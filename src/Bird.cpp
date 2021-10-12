
#include "Bird.hpp"

#include <array>
#include <vector>
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"

Vec2 getPosition() {
	return m_position; // Why ?
};

Vec2 getVelocity() {
	return m_velocity:
};

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = cohesion(neighbors);
	Vec2 vecAlignment = alignment(neighbors);
	Vec2 vecSeparation = separation(neighbors);
	Vec2 vec_displacement = vecCohesion + vecAlignment + vecSeparation;
	m_velocity = m_velocity + vec_displacement;
};

Vec2 Bird::computePosition() {
	m_nextPosition = m_position + m_velocity;
	return m_nextPosition;
};
