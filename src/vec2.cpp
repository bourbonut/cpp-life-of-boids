#include <cmath>
#include <iostream>
#include <vector>

class vec2 {
private:
    double _x;
    double _y;

public:
    vec2();
    vec2(double, double);

public:
    double x(); // return the x value
    double y(); // return the y value
    vec2 operator+(vec2 other); // add vectors
    vec2 operator-(vec2 other); // substract vectors
    vec2 operator*(vec2 other); // multiply vectors term by term
    vec2 operator*(double other); // scale the vector
    vec2& operator=(vec2& other); // assign vector
    double dot(vec2 other); // return the scalar product
    double norm(); // return the norm of the vector
    vec2 normalize(); // return the current vector normalized
    double angle(); // return the angle between the current vector and `vec2(1, 0)`
    double anglebt(vec2 other); // return the angle between the current vector and an other vector
    void print(); // display the vector in shell
};

vec2::vec2(){
  _x = 0.;
  _y = 0.;
}

vec2::vec2(double x, double y){
  _x = x;
  _y = y;
}

vec2& vec2::operator=(vec2& other)
{
    _x = other.x();
    _y = other.y();
    return *this;
}

vec2 vec2::operator+(vec2 other)
{
    return vec2(_x + other.x(), _y + other.y());
}

vec2 vec2::operator-(vec2 other)
{
    return vec2(_x - other.x(), _y - other.y());
}

vec2 vec2::operator*(vec2 other)
{
   return vec2(_x * other.x(), _y * other.y());
}

vec2 vec2::operator*(double other)
{
    return vec2(_x * other, _y * other);
}

double vec2::x() {
    return _x;
}

double vec2::y() {
    return _y;
}

double vec2::dot(vec2 other){
  return _x * other.x() + _y * other.y();
}

double vec2::norm(){
  return std::sqrt(_x*_x + _y*_y);
}

vec2 vec2::normalize(){
  double norm = this->norm();
  return vec2(_x / norm, _y / norm);
}

double vec2::angle(){
  return std::acos(_x/this->norm());
}

double vec2::anglebt(vec2 other){
  return acos(this->dot(other) / (this->norm() * other.norm()));
}

void vec2::print(){
  std::cout << "vec2(" << _x << ", " << _y << ")" << std::endl;
}

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
    barycenter(vecs).print();

    return 0;
}
