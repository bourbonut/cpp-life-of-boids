#include <cmath>
#include <iostream>
#include "vec2.hpp"

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
