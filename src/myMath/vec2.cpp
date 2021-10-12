#include <cmath>
#include <iostream>
#include <string>
#include "Vec2.hpp"

Vec2::Vec2(){
  m_x = 0.;
  m_y = 0.;
}

Vec2::Vec2(float x, float y){
  m_x = x;
  m_y = y;
}

Vec2::Vec2(float a){
  m_x = a;
  m_y = a;
}

Vec2& Vec2::operator=(Vec2& other)
{
    m_x = other.m_x;
    m_y = other.m_y;
    return *this;
}

Vec2 Vec2::operator+(const Vec2& other)
{
    return Vec2(m_x + other.m_x, m_y + other.m_y);
}

Vec2 Vec2::operator-(const Vec2& other)
{
    return Vec2(m_x - other.m_x, m_y - other.m_y);
}

Vec2 Vec2::operator*(const Vec2& other)
{
   return Vec2(m_x * other.m_x, m_y * other.m_y);
}

Vec2 Vec2::operator*(float other)
{
    return Vec2(m_x * other, m_y * other);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
  m_x += other.m_x;
  m_y += other.m_y;
  return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
  m_x -= other.m_x;
  m_y -= other.m_y;
  return *this;
}

Vec2& Vec2::operator*=(const Vec2& other)
{
  m_x *= other.m_x;
  m_y *= other.m_y;
  return *this;
}

Vec2& Vec2::operator*=(float other)
{
  m_x *= other;
  m_y *= other;
  return *this;
}

Vec2 Vec2::operator/(const Vec2& other)
{
   return Vec2(m_x / other.m_x, m_y / other.m_y);
}

Vec2 Vec2::operator/(float other)
{
    return Vec2(m_x / other, m_y / other);
}

Vec2& Vec2::operator/=(const Vec2& other)
{
  m_x /= other.m_x;
  m_y /= other.m_y;
  return *this;
}

Vec2& Vec2::operator/=(float other)
{
  m_x /= other;
  m_y /= other;
  return *this;
}

bool Vec2::operator==(const Vec2& other)
{
  if(m_x == other.m_x && m_y == other.m_y){
    return true;
  }
  else{
    return false;
  }
}

std::ostream& operator<<(std::ostream& os, Vec2& obj)
{
    return os << obj.string();
}

float Vec2::x() {
    return m_x;
}

float Vec2::y() {
    return m_y;
}

float Vec2::dot(const Vec2& other){
  return m_x * other.m_x + m_y * other.m_y;
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

float Vec2::angle(Vec2& other){
  return acos(this->dot(other) / (this->norm() * other.norm()));
}

Vec2 Vec2::rotate(float angle){
  return Vec2(std::cos(angle) * m_x - std::sin(angle) * m_y, std::sin(angle) * m_x + std::cos(angle) * m_y);
}

std::string Vec2::string(){
  return "Vec2(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
}
