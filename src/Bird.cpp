
#include "Bird.hpp"

#include <array>
#include <vector>
#include "myMath/Vec2.hpp"
// #include "myMath/utils.hpp"

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = cohesion(neighbors);
	Vec2 vecAlignment = alignment(neighbors);
	Vec2 vecSeparation = separation(neighbors);
	Vec2 vec_displacement = vecCohesion + vecAlignment + vecSeparation;
	m_velocity = m_velocity + vec_displacement;
};

void Bird::updatePosition() {
	m_position = m_position + m_velocity;
};
