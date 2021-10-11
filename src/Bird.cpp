
#include "Bird.hpp"

#include <array>
#include <vector>

using vec2 = std::array<float, 2>;

void Bird::updateVelocity(vec2 m_vec_cohesion, vec2 m_vec_alignment, vec2 m_vec_separation) { // Pq?
	vec2 vec_displacement = m_vec_cohesion + m_vec_alignment + m_vec_separation;
	m_velocity += vec_displacement;
};

void Bird::updatePosition() {
	m_position += m_velocity;
};
