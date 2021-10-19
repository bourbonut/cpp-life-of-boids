#include <array>
#include <vector>
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Eagle.hpp"

Eagle::Eagle() : Agent(-8, 8) {};

Eagle::Eagle(const Vec2& position, const Vec2& velocity) :
	Agent(position, velocity) {};

void Eagle::print() const {
	std::cout << ">>>Printing eagle : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
};