#pragma once
#include <iostream>

extern float EPS_;

typedef struct Vec2 {
    float x;
    float y;

public:
    Vec2();
    Vec2(float, float);
    Vec2(float);
    ~Vec2() {};

public:
    Vec2 operator+(const Vec2& other); // add vectors
    Vec2& operator+=(const Vec2& other); // add vectors

    Vec2 operator-(const Vec2& other) const; // substract vectors
    Vec2& operator-=(const Vec2& other); // substract vectors

    Vec2 operator*(const Vec2& other); // multiply vectors term by term
    Vec2 operator*(float other); // scale the vector

    Vec2 operator/(const Vec2& other); // divide vectors term by term
    Vec2 operator/(float other); // scale the vector

    Vec2& operator*=(const Vec2& other); // multiply vectors term by term
    Vec2& operator*=(float other); // scale the vector

    Vec2& operator/=(const Vec2& other); // divide vectors term by term
    Vec2& operator/=(float other); // scale the vector

    Vec2& operator=(const Vec2& other); // assign vector
    bool operator==(const Vec2& other) const; // compare current vector with vector

    float dot(const Vec2& other); // return the scalar product
    float norm(); // return the norm of the vector
    Vec2 normalize(); // return the current vector normalized
    float angle(); // return the angle between the current vector and `Vec2(1, 0)`
    float angle(Vec2& other); // return the angle between the current vector and an other vector
    Vec2 rotate(float angle); // rotate the vector anti-clockwise
    std::string string() const; // return a string useful when you need to display the vector
};

std::ostream& operator<<(std::ostream& os, const Vec2& obj);
