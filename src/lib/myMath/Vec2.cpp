#include <cmath>
#include <iostream>
#include <string>
#include "Vec2.hpp"
#include <algorithm>

float EPS_ = 0.00001;

Vec2::Vec2() {
    this->x = 0.;
    this->y = 0.;
}

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vec2::Vec2(float a) {
    this->x = a;
    this->y = a;
}

Vec2& Vec2::operator=(const Vec2& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Vec2 Vec2::operator+(const Vec2& other)
{
    return Vec2(this->x + other.x, this->y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
    return Vec2(this->x - other.x, this->y - other.y);
}

Vec2 Vec2::operator*(const Vec2& other)
{
    return Vec2(this->x * other.x, this->y * other.y);
}

Vec2 Vec2::operator*(float other)
{
    return Vec2(this->x * other, this->y * other);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(const Vec2& other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

Vec2& Vec2::operator*=(float other)
{
    this->x *= other;
    this->y *= other;
    return *this;
}

Vec2 Vec2::operator/(const Vec2& other)
{
    return Vec2(this->x / other.x, this->y / other.y);
}

Vec2 Vec2::operator/(float other)
{
    return Vec2(this->x / other, this->y / other);
}

Vec2& Vec2::operator/=(const Vec2& other)
{
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

Vec2& Vec2::operator/=(float other)
{
    this->x /= other;
    this->y /= other;
    return *this;
}

bool Vec2::operator==(const Vec2& other) const
{
    if (this->x == other.x && this->y == other.y) {
        return true;
    }
    else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Vec2& obj)
{
    return os << obj.string();
}

float Vec2::dot(const Vec2& other) {
    return this->x * other.x + this->y * other.y;
}

float Vec2::norm() {
    return std::sqrt(this->x * this->x + this->y * this->y);
}

Vec2 Vec2::normalize() {
    float norm = this->norm();
    Vec2 normalized = Vec2(this->x / (norm + EPS_), this->y / (norm + EPS_));
    if (std::isnan(normalized.x) | std::isnan(normalized.y)) {
        throw std::domain_error("Undefined coordinate");
    }
    return normalized;
}

float Vec2::angle() {
    float angle = std::acos(std::min(1., std::max(-1., (double)this->x / this->norm())));
    return (this->y > 0) ? angle : -angle;
}

float Vec2::angle(Vec2& other) {
    float norm = this->norm() * other.norm();
    if (norm == 0.) {
        return 0.;
    }
    else {
        return std::acos(std::min(1., std::max(-1., (double)this->dot(other) / norm)));
    }
}

Vec2 Vec2::rotate(float angle) {
    return Vec2(std::cos(angle) * this->x - std::sin(angle) * this->y, std::sin(angle) * this->x + std::cos(angle) * this->y);
}

std::string Vec2::string() const {
    return "Vec2(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}
