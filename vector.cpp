#include <iostream>
#include "../vector.h"
#include "../point.h"

namespace geometry {
  Vector::Vector() = default;
  Vector::Vector(const int64_t& a, const int64_t& b) : x_(a), y_(b) {
  }
  Vector::Vector(const Point& p1, const Point& p2) {
    x_ = p2.Xcor() - p1.Xcor();
    y_ = p2.Ycor() - p1.Ycor();
  }
  Vector& Vector::operator+=(const Vector& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
  }
  Vector& Vector::operator-=(const Vector& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
  }
  Vector& Vector::operator*=(const int64_t& value) {
    x_ *= value;
    y_ *= value;
    return *this;
  }
  Vector& Vector::operator/=(const int64_t& value) {
    x_ /= value;
    y_ /= value;
    return *this;
  }
  Vector Vector::operator+() {
    return *this;
  }
  Vector Vector::operator-() {
    auto tmp = *this;
    tmp *= -1;
    return tmp;
  }
  int64_t Vector::Xcor() const {
    return x_;
  }
  int64_t Vector::Ycor() const {
    return y_;
  }
  Vector operator+(const Vector& first, const Vector& second) {
    auto tmp = first;
    return tmp += second;
  }
  Vector operator-(const Vector& first, const Vector& second) {
    auto tmp = first;
    return tmp -= second;
  }
  Vector operator*(const Vector& first, const int64_t& value) {
    auto tmp = first;
    return tmp *= value;
  }
  Vector operator/(const Vector& first, const int64_t& value) {
    auto tmp = first;
    return tmp /= value;
  }
  bool operator==(const Vector& first, const Vector& second) {
    return (first.Xcor() == second.Xcor() && first.Ycor() == second.Ycor());
  }
  int64_t ScalarProd(const Vector& first, const Vector& second) {
    return (first.Xcor() * second.Xcor() + first.Ycor() * second.Ycor());
  }
  int64_t VectorProd(const Vector& first, const Vector& second) {
    return (first.Xcor() * second.Ycor() - first.Ycor() * second.Xcor());
  }
}