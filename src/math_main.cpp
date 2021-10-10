#include "myMath/vec2.hpp"
#include "myMath/utils.hpp"
#include <iostream>
#include <vector>

int main() {
    vec2 a = vec2(4.5, 6.2);
    vec2 b = vec2(2., 100.2);
    a.print(); // Display the vector
    std::cout << "x: " << a.x() << std::endl; // return the x value
    std::cout << "y: " << a.y() << std::endl; // return the y value
    std::cout << "norm: " << a.norm() << std::endl; // return the norm of the vector
    a.normalize().print(); // display normalized `a` vector
    std::cout << "norm of normalized vector: " << a.normalize().norm() << std::endl; // return `1` because `a.normalized()` has a norm equal to 1
    std::cout << "angle: " << a.angle() << std::endl; //return the angle between `a` and `vec2(1, 0)`
    std::cout << "anglebt: " << a.anglebt(b) << std::endl; //return the angle between `a` and `b`
    std::cout << "dot: " << a.dot(b) << std::endl; //return the scalar product
    vec2 c;
    c = a; // assign to `c` the values of `a`
    std::cout << "c = a: ";
    c.print();
    vec2 d = a + b;
    std::cout << "Addition: ";
    d.print();
    std::cout << "Substraction: ";
    d = a - b;
    d.print();
    std::cout << "Multiplication: ";
    d = a * b; // multiply term by term `a` and `b`
    d.print();
    std::cout << "Scale: ";
    d = a * 5.; // multilply all terms of `a` by `5.`
    d.print();

    std::vector<vec2> vecs;
    vecs.push_back(vec2(0., 0.));
    vecs.push_back(vec2(0., 1.));
    vecs.push_back(vec2(1., 0.));
    vecs.push_back(vec2(1., 1.));
    std::cout << "Distance: " << distance(a, b) << std::endl;
    vec2 x = barycenter(vecs);
    x.print();

    return 0;
}
