#include <cmath>
#include <iostream>
#include "Vec2.hpp"

Vec2::Vec2(){
  m_x = 0.;
  m_y = 0.;
}

Vec2::Vec2(float x, float y){
  m_x = x;
  m_y = y;
}

Vec2& Vec2::operator=(Vec2& other)
{
    m_x = other.x();
    m_y = other.y();
    return *this;
}

Vec2 Vec2::operator+(Vec2 other)
{
    return Vec2(m_x + other.x(), m_y + other.y());
}

Vec2 Vec2::operator-(Vec2 other)
{
    return Vec2(m_x - other.x(), m_y - other.y());
}

Vec2 Vec2::operator*(Vec2 other)
{
   return Vec2(m_x * other.x(), m_y * other.y());
}

Vec2 Vec2::operator*(float other)
{
    return Vec2(m_x * other, m_y * other);
}

float Vec2::x() {
    return m_x;
}

float Vec2::y() {
    return m_y;
}

float Vec2::dot(Vec2 other){
  return m_x * other.x() + m_y * other.y();
}

float Vec2::norm(){
  return std::sqrt(m_x*m_x + m_y*m_y);
}

Vec2 Vec2::normalize(){
  float norm = this->norm();
  return Vec2(m_x / norm, m_y / norm);
}

float Vec2::angle(){
  return std::acos(m_x/this->norm());
}

float Vec2::anglebt(Vec2 other){
  return acos(this->dot(other) / (this->norm() * other.norm()));
}

void Vec2::print(){
  std::cout << "Vec2(" << m_x << ", " << m_y << ")" << std::endl;
}
