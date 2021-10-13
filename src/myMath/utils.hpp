#pragma once
#include "Vec2.hpp"
#include <vector>

float distance(const Vec2 &a, const Vec2 &b);

Vec2 barycenter(std::vector<Vec2> vecs);

float radians(float angle);

float degrees(float angle);

bool isAntiClockwise(Vec2 a, Vec2 b);
