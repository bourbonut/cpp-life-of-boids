#pragma once

#include <vector>
#include <array>
#include "myMath/Vec2.hpp"


using mat2x3 = std::array<Vec2, 3>;
using mat2x6 = std::array<Vec2, 6>;

mat2x6 drawAgent(Vec2 position, Vec2 velocity, float h, float w);