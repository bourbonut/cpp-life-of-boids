#pragma once

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES 
#include <math.h>
#include "lib/myMath/Vec2.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/oglTypes.hpp"

int main() {
	std::cout << "Hello, world !" << std::endl;

	Vec2 position(500, 500);
	Vec2 velocity(2, 5);
	Vec2 velocity2(2, -5);

	mat2x6 result = drawAgent(position, velocity, 600.f, 800.f);

	for (int i = 0; i < result.size(); ++i) {
		std::cout << result[i].string() << std::endl;
	}

	std::cout << "Velocity : " << velocity.string() << " angle : " << velocity.angle() << std::endl;
	std::cout << "Velocity : " << velocity2.string() << " angle : " << velocity2.angle() << std::endl;
}