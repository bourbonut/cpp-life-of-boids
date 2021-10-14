#pragma once

#include "graphics.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "oglTypes.hpp"

mat2x6 drawAgent(Vec2 position, Vec2 velocity) {

	float size = 7;
	float angle = velocity.angle();
	Vec2 front{ position + Vec2{ 1.f * size, 0 }.rotate(angle) } ;
	Vec2 backLeft{ position + Vec2{ - 1.f * size, 1.f * size }.rotate(angle) } ;
	Vec2 backRight{ position + Vec2{ -1.f * size, -1.f * size }.rotate(angle) } ;

	mat2x6 r = { position, front, backLeft, position, front, backRight };
	return r;
}