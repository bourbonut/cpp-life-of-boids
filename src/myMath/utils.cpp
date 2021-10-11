#include "vec2.hpp"
#include <vector>

float distance(Vec2 a, Vec2 b) {
    return (a - b).norm();
}

Vec2 barycenter(std::vector<Vec2> vecs) {
    int size = vecs.size();
    float xg = 0;
    float yg = 0;
    for (Vec2 v : vecs) {
        xg += v.x();
        yg += v.y();
    }
    return Vec2(xg / size, yg / size);
}
