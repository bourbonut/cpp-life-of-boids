#pragma once

#include "graphics.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "oglTypes.hpp"
#include "../Bird.hpp"

mat2x6 drawAgent(Vec2 position, Vec2 velocity) {

	float size = 7;
	float angle = velocity.angle();
	Vec2 front{ position + Vec2{ 1.f * size, 0 }.rotate(angle) } ;
	Vec2 backLeft{ position + Vec2{ - 1.f * size, 1.f * size }.rotate(angle) } ;
	Vec2 backRight{ position + Vec2{ -1.f * size, -1.f * size }.rotate(angle) } ;

	mat2x6 r = { position, front, backLeft, position, front, backRight };
	return r;
}

void verifyPosition(Bird& bird, float width, float height) {
	float x = bird.getNextPosition().x;
	float y = bird.getNextPosition().y;
	if (x >= width) {
		if (y >= height) {
			bird.setNextPosition(Vec2(x - width, y - height));
		}
		bird.setNextPosition(Vec2(x - width, y));
	}
	else if (y >= height) {
		bird.setNextPosition(Vec2(x, y - height));
	}
}