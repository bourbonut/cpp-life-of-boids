#include <array>
#include <vector>
#include <utility>

#include "Eagle.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"

using pair = std::pair<Vec2, Agent *>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;

Eagle::Eagle() : Agent(-8, 8, 2, 50) {};

Eagle::Eagle(const Vec2& position, const Vec2& velocity) :
	Agent(position, velocity, 2, 50, 30) {};

Eagle::Eagle(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float& speedRelaxation, const Color& color, const HuntingLaw& huntLaw) :
	Agent(position, velocity, bodySize, viewAngle, range, speedRelaxation, color), m_huntingLaw(), m_separationLaw() {
	m_huntingLaw = huntLaw;
}

Eagle::Eagle(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float& maxSpeed, const Color& color) :
	Agent(position, velocity, bodySize, viewAngle, range, maxSpeed, color), m_huntingLaw(), m_separationLaw() {};


void Eagle::computeLaws(const pairNP& neighbors) {
	std::vector<pair> neighborsBird = std::get<0>(neighbors);
	Vec2 vec_displacement{};

	if (neighborsBird.size() > 0) { vec_displacement = vec_displacement + m_huntingLaw.compute(*this, neighborsBird) ; }
	//if (allNeighbors.size() > 0) { vec_displacement = vec_displacement + m_separationLaw.compute(*this, allNeighbors) * 0.1f; }

	float norm = vec_displacement.norm();

	if (norm > 5) {
		vec_displacement = vec_displacement / norm;
	}

	m_nextVelocity = (m_velocity + vec_displacement);
	if (m_nextVelocity.norm() > m_maxSpeed) {
		m_nextVelocity = m_nextVelocity.normalize() * m_maxSpeed;
	}
}

void Eagle::print() const {
	std::cout << ">>>Printing eagle : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
};
