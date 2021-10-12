#include "graphics.hpp"
#include "myMath/vec2.hpp"

using mat2x3 = std::array<Vec2, 3>;
using mat2x6 = std::array<Vec2, 6>;

mat2x6 drawAgent(Vec2 position, Vec2 velocity, float h, float w) {
	//Vec2 extremite_triangle_1{ position.x() + h * 0.008f, position.y() };
	//Vec2 extremite_triangle_2{ position.x() - h * 0.008f, position.y() - w * 0.008f };
	//Vec2 extremite_triangle_3{ position.x() - h * 0.008f, position.y() + w * 0.008f };
	float size = 0.01;

	Vec2 extremite_triangle_1{ position.x(), position.y()};
	Vec2 extremite_triangle_2{ position.x() + h * size, position.y()};
	Vec2 extremite_triangle_3{ position.x() - h * size, position.y() + w * size };
	Vec2 extremite_triangle_4{ position.x(), position.y() };
	Vec2 extremite_triangle_5{ position.x() + h * size, position.y() };
	Vec2 extremite_triangle_6{ position.x() - h * size, position.y() - w * size };

	mat2x6 r = { extremite_triangle_1, extremite_triangle_2, extremite_triangle_3
		, extremite_triangle_4, extremite_triangle_5, extremite_triangle_6 };
	return r;
}