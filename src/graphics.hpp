#pragma once

#include <vector>
#include <array>
#include "myMath/vec2.hpp"


using mat2x3 = std::array<Vec2, 3>;

mat2x3 drawAgent(Vec2 position, Vec2 velocity, float h, float w);