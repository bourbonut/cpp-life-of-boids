#include <array>
#include <vector>
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Bird.hpp"

Bird::Bird() : Agent(-5, 5) {};
//
//
//Bird::Bird(const Bird& other) {
//	m_position = other.m_position;
//	m_velocity = other.m_velocity;
//	m_bodySize = other.m_bodySize;
//};
////NEED CTOR BY COPY (rule of three) BUT ACCESSING TO OTHER BIRD'S DATA SEEMS WEIRD
////MAYBE WE NEED A STRUCT ?? OR MAYBE WE NEED TO APPLY THE ZERO LAW AND BIRDS ARE NOT THE ONES WHO RANDOMIZE!!
//Bird::Bird(const Bird& other) {
//m_position
//};
Bird::Bird(const Vec2& position, const Vec2& velocity) : 
	Agent(position, velocity) {};


void Bird::computeLaws(const std::vector<Agent*>& neighbors) {
	Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighbors);
	Vec2 vecAlignment = m_AlignmentLaw.compute(*this, neighbors);
	Vec2 vecSeparation = m_separationLaw.compute(*this, neighbors);
	Vec2 vec_displacement = vecCohesion / 10 + vecAlignment + vecSeparation * 1000;
	m_nextVelocity = this->getVelocity()* 0.99 + vec_displacement * 0.01;
};

void Bird::print() const {
	std::cout << ">>>Printing bird : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
};

