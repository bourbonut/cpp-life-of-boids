#include <array>
#include <vector>
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Bird.hpp"


Bird::Bird() {
	Vec2 pos = randomVec2Generation(0, 1000);
	Vec2 vel = randomVec2Generation(-5, 5);
	m_position = pos;
	m_velocity = vel;
	m_nextPosition = pos + 1;
	m_nextVelocity = vel + 1;
};


Bird::Bird(const Vec2& position, const Vec2& velocity) {
	m_position = position;
	m_velocity = velocity;
};


void Bird::computeLaws(const std::vector<Agent*>& neighbors) {
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

Vec2 Bird::computeAlignment(const std::vector<Agent*>& neighbors) {
	Vec2 vecAlignment = m_AlignmentLaw.compute(*this, neighbors);
	return vecAlignment;
}