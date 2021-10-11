#include "myMath/Vec2.hpp"
#include "myMath/utils.hpp"
#include <iostream>
#include <vector>

int main() {
    Vec2 a = Vec2(4.5, 6.2);
    Vec2 b = Vec2(2., 100.2);
    a.print(); // Display the vector
    std::cout << "x: " << a.x() << std::endl; // return the x value
    std::cout << "y: " << a.y() << std::endl; // return the y value
    std::cout << "norm: " << a.norm() << std::endl; // return the norm of the vector
    a.normalize().print(); // display normalized `a` vector
    std::cout << "norm of normalized vector: " << a.normalize().norm() << std::endl; // return `1` because `a.normalized()` has a norm equal to 1
    std::cout << "angle: " << a.angle() << std::endl; //return the angle between `a` and `Vec2(1, 0)`
    std::cout << "anglebt: " << a.anglebt(b) << std::endl; //return the angle between `a` and `b`
    std::cout << "dot: " << a.dot(b) << std::endl; //return the scalar product
    Vec2 c;
    c = a; // assign to `c` the values of `a`
    std::cout << "c = a: ";
    c.print();
    Vec2 d = a + b;
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

    std::vector<Vec2> vecs;
    vecs.push_back(Vec2(0., 0.));
    vecs.push_back(Vec2(0., 1.));
    vecs.push_back(Vec2(1., 0.));
    vecs.push_back(Vec2(1., 1.));
    std::cout << "Distance: " << distance(a, b) << std::endl;
    Vec2 x = barycenter(vecs);
    x.print();

    return 0;
}
