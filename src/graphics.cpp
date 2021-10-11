#include "graphics.hpp"
#include "myMath/vec2.hpp"

using mat2x3 = std::array<Vec2, 3>;

mat2x3 drawAgent(Vec2 position, Vec2 velocity, float h, float w) {
	Vec2 extremite_triangle_1{ position.x() + h * 0.002f, position.y() };
	Vec2 extremite_triangle_2{ position.x() - h * 0.002f, position.y() - w * 0.002f };
	Vec2 extremite_triangle_3{ position.x() - h * 0.002f, position.y() + w * 0.002f };

	mat2x3 r = { extremite_triangle_1, extremite_triangle_2, extremite_triangle_3 };
	return r;
}