#pragma once
#include "vec2.hpp"
#include <vector>

float distance(const Vec2 &a, const Vec2 &b);

Vec2 barycenter(std::vector<Vec2> vecs);
