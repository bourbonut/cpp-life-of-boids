#include "vec2.hpp"
#include <vector>

double distance(vec2 a, vec2 b) {
    return (a - b).norm();
}

vec2 barycenter(std::vector<vec2> vecs) {
    int size = vecs.size();
    double xg = 0;
    double yg = 0;
    for (vec2 v : vecs) {
        xg += v.x();
        yg += v.y();
    }
    return vec2(xg / size, yg / size);
}
