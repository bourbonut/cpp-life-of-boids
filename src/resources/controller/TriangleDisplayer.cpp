#include "TriangleDisplayer.hpp"
#include <array>
#include "../../lib/myMath/Vec2.hpp"

TriangleDisplayer::TriangleDisplayer(const Agent *pAgent) {
	m_pAgent = pAgent;
};

std::array<Vec2, 6> TriangleDisplayer:: drawAgent() const {
	Vec2 position = (*m_pAgent).getPosition();
	Vec2 velocity = (*m_pAgent).getVelocity();

	float size = 7;
	float angle = (velocity).angle();
	Vec2 front{ position + Vec2{ 1.f * size, 0 }.rotate(angle) };
	Vec2 backLeft{ position + Vec2{ -1.f * size, 1.f * size }.rotate(angle) };
	Vec2 backRight{ position + Vec2{ -1.f * size, -1.f * size }.rotate(angle) };
	
	return std::array<Vec2, 6>{ position, front, backLeft, position, front, backRight };
};