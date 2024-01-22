#include "../point.h"
#include "../segment.h"
#include "../vector.h"
#include <iostream>

namespace geometry {
  Point::Point() = default;
  Point::Point(int64_t x, int64_t y) : x_(x), y_(y) {
  }
  IShape& Point::Move(const Vector& vector) {
    x_ += vector.Xcor();
    y_ += vector.Ycor();
    return *this;
  }
  bool Point::ContainsPoint(const Point& point) const {
    return (x_ == point.Xcor() && y_ == point.Ycor());
  }
  bool Point::CrossesSegment(const Segment& segment) const {
    Vector v(segment.PointA(), *this);
    Vector u(*this, segment.PointB());
    auto scalar = ScalarProd(v, u);
    auto vector = VectorProd(v, u);
    return (vector == 0 && scalar >= 0);
  }
  std::shared_ptr<IShape> Point::Clone() const {
    return std::make_shared<Point>(x_, y_);
  }
  std::string Point::ToString() const {
    std::string ans;
    ans = "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    return ans;
  }
  int64_t Point::Xcor() const {
    return x_;
  }
  int64_t Point::Ycor() const {
    return y_;
  }
  Vector operator-(const Point& second, const Point& first) {
    int64_t x = second.Xcor() - first.Xcor();
    int64_t y = second.Ycor() - first.Ycor();
    Vector vector(x, y);
    return vector;
  }
}