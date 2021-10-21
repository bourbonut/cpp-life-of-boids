#include <array>
#include <vector>
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Eagle.hpp"

Eagle::Eagle() : Agent(-8, 8, 2, 180) {};

Eagle::Eagle(const Vec2& position, const Vec2& velocity) :
	Agent(position, velocity, 2, 180, 30) {};

void Eagle::computeLaws(const std::vector<Agent*>& allNeighbors, const std::vector<Agent*>& preyNeighbors) {
	Vec2 vec_displacement{};
	
	if (preyNeighbors.size() > 0) { vec_displacement = vec_displacement + m_huntingLaw.compute(*this, preyNeighbors) * 1.f; }
	if (allNeighbors.size() > 0) { vec_displacement = vec_displacement + m_separationLaw.compute(*this, allNeighbors) * 0.1f; }
	
	float norm = vec_displacement.norm();

	if (norm > 5) {
		vec_displacement = vec_displacement / norm;
	}

	m_nextVelocity = (m_velocity * 0.90 + vec_displacement * 0.10);
	if (m_nextVelocity.norm() > 10) {
		m_nextVelocity = m_nextVelocity.normalize() * 10;
	}
}

void Eagle::print() const {
	std::cout << ">>>Printing eagle : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
};