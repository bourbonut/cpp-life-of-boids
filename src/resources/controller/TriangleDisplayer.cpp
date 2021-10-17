#include "TriangleDisplayer.hpp"
#include <vector>
#include "../../lib/myMath/Vec2.hpp"


std::vector<Vec2> TriangleDisplayer::drawAgent() const {
	Vec2& position = (*m_pAgent).getPosition();
	Vec2& velocity = (*m_pAgent).getVelocity();


	float size = 7;
	float angle = velocity.angle();
	Vec2 front{ position + Vec2{ 1.f * size, 0 }.rotate(angle) };
	Vec2 backLeft{ position + Vec2{ -1.f * size, 1.f * size }.rotate(angle) };
	Vec2 backRight{ position + Vec2{ -1.f * size, -1.f * size }.rotate(angle) };
	
	std::vector<Vec2> r{ position, front, backLeft, position, front, backRight };
	return r;
	//mat2x6 r = { position, front, backLeft, position, front, backRight };
	//return r;
};