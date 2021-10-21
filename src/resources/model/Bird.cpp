#include <array>
#include <vector>
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Bird.hpp"

Bird::Bird() : Agent(-5, 5, 6, 270) {};
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
	Agent(position, velocity, 6, 270, 50) {};


void Bird::computeLaws(const std::vector<Agent*>& neighbors,
					  const std::vector<Agent*>& neighborsPredator) {
	Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighbors);
	Vec2 vecAlignment = m_AlignmentLaw.compute(*this, neighbors);
	Vec2 vecSeparation = m_separationLaw.compute(*this, neighbors);
	Vec2 vec_displacement = vecAlignment * 0.01 + vecCohesion * 0.005 + vecSeparation * 1.f;
	float norm = vec_displacement.norm();

	if (norm > 5) {
		vec_displacement = vec_displacement / norm;
	}

	//std::cout << "Bird id " << this->_id << " | nb neigh : " << neighbors.size() << " | alignment vec " << vecAlignment << " | cohesion vec " << vecCohesion << " | Separation vec " << vecSeparation << '\n';
	m_nextVelocity = (m_velocity * 0.99 + vec_displacement) ; 
	if (m_nextVelocity.norm() > 10) {
		m_nextVelocity = m_nextVelocity.normalize() * 10;
	}
};

void Bird::print() const {
	std::cout << ">>>Printing bird : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
};


