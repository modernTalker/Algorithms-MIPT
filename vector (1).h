#ifndef VECTOR
#define VECTOR

#include <iostream>

namespace geometry {
  class Point;

class Vector {
 public:
  Vector();
  Vector(const int64_t& a, const int64_t& b);
  Vector(const Point& p1, const Point& p2);
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector& operator*=(const int64_t& value);
  Vector& operator/=(const int64_t& value);
  Vector operator+();
  Vector operator-();
  int64_t Xcor() const;
  int64_t Ycor() const;
 private:
  int64_t x_;
  int64_t y_;
};
Vector operator+(const Vector& first, const Vector& second);
Vector operator-(const Vector& first, const Vector& second);
Vector operator*(const Vector& first, const int64_t& value);
Vector operator/(const Vector& first, const int64_t& value);

bool operator==(const Vector& first, const Vector& second);
int64_t VectorProd(const Vector& first, const Vector& second);
int64_t ScalarProd(const Vector& first, const Vector& second);

}

#endif