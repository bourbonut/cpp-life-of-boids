#define _USE_MATH_DEFINES 
#include <math.h>
#include "graphics.hpp"
#include "myMath/vec2.hpp"

using mat2x3 = std::array<Vec2, 3>;
using mat2x6 = std::array<Vec2, 6>;

mat2x6 drawAgent(Vec2 position, Vec2 velocity, float h, float w) {

	float size = 0.01;
	float angle = velocity.angle();
	Vec2 front{ position + Vec2{ h * size, 0 }.rotate(angle) } ;
	Vec2 backLeft{ position + Vec2{ -h * size, w * size }.rotate(angle) } ;
	Vec2 backRight{ position + Vec2{ -h * size, -w * size }.rotate(angle) } ;

	mat2x6 r = { position, front, backLeft, position, front, backRight };
	return r;
}