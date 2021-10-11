#include <iostream>
#include <vector>
#include "myMath/Vec2.hpp"
#include "graphics.hpp"

using mat2x3 = std::array<Vec2, 3>;

int main() {
	std::cout << "Hello, world !" << std::endl;

	Vec2 position(500, 500);
	Vec2 velocity(-4, 5);

	mat2x3 result = drawAgent(position, velocity, 600.f, 800.f);

	for (int i = 0; i < result.size(); ++i) {
		result[i].print();
	}
}