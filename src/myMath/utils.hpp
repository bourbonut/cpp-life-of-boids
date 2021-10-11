#pragma once
#include "vec2.hpp"
#include <vector>

float distance(Vec2 a, Vec2 b);

Vec2 barycenter(std::vector<Vec2> vecs);
