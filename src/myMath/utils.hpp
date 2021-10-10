#pragma once
#include "vec2.hpp"
#include <vector>

double distance(vec2 a, vec2 b);

vec2 barycenter(std::vector<vec2> vecs);
