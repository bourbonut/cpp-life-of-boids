#include "Bird.hpp"

#include <array>
#include <vector>
#include "../lib/myMath/Vec2.hpp"
#include "../lib/myMath/utils.hpp"

//Bird::Bird() = default;
//Bird::Bird(Vec2 &position, Vec2 &velocity){
//	m_position = Vec2(position);
//	m_velocity = Vec2(velocity);
//}
Bird::~Bird() {};

Bird::Bird(const Vec2 &position, const Vec2 &velocity) : m_position{ position }, m_velocity{ velocity },
										   m_nextPosition{ position }, m_nextVelocity{velocity} {};

Bird::Bird() {
	m_position = randomVec2Generation(0, 10);
	m_velocity = randomVec2Generation(0, 10);
	m_nextPosition = randomVec2Generation(0, 10);
	m_nextVelocity = randomVec2Generation(0, 10);
};

Vec2 Bird::getPosition() const {
	return m_position;
};

Vec2 Bird::getVelocity() const {
	return m_velocity;
};

Vec2 Bird::getNextPosition() const {
	return m_nextPosition;
};

Vec2 Bird::getNextVelocity() const {
	return m_nextVelocity;
};

void Bird::updateVelocity(const std::vector<Bird> &neighbors) {
	Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighbors);
	//Vec2 vecAlignment = this->alignment(neighbors);
	Vec2 vecSeparation = m_separationLaw.compute(*this, neighbors);
	Vec2 vec_displacement = vecCohesion + /*vecAlignment +*/ vecSeparation;
	m_nextVelocity = m_velocity + vec_displacement;
};

void Bird::computePosition() {
	m_nextPosition = m_position + m_nextVelocity;
};

void Bird::updatePosition() {
	m_position = m_nextPosition;
	m_velocity = m_nextVelocity;
};

void Bird::print() const {
	std::cout << ">>>Printing bird : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
	std::cout << "\n>>>           N_P( " << m_nextPosition.x << ", " << m_nextPosition.y << " ) / N_V(" << m_nextVelocity.x << ", " << m_nextVelocity.y << " )\n";
};
