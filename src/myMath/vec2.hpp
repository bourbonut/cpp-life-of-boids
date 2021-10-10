#pragma once

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
