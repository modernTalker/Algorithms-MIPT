#include "../ray.h"
#include "../segment.h"
#include "../line.h"
#include "../point.h"
#include <iostream>

namespace geometry {
  Ray::Ray() = default;
  Ray::Ray(const Point& first, const Point& second) {
    begin_ = first;
    direct_ = Vector(first, second);
  }
  Ray::Ray(const Point& first, const Vector& vector) {
    begin_ = first;
    direct_ = vector;
  }
  IShape& Ray::Move(const Vector& vector) {
    begin_.Move(vector);
    return *this;
  }
  bool Ray::ContainsPoint(const Point& point) const {
    Vector v(begin_, point);
    auto scalar = ScalarProd(direct_, v);
    auto vector = VectorProd(direct_, v);
    return (vector == 0) && (scalar >= 0);
  }
  bool Ray::CrossesSegment(const Segment& segment) const {
    Point a = begin_;
    Point b (begin_.Xcor() + direct_.Xcor(), begin_.Ycor() + direct_.Ycor());
    Point c = segment.PointA();
    Point d = segment.PointB();
    Vector v1(a, b);
    Vector v2(c, d);
    Vector v3(c, a);
    Line line(a, b);
    return line.CrossesSegment(segment) && (VectorProd(v1, v2) * VectorProd(v3, v2) <= 0);
  }
  std::shared_ptr<IShape> Ray::Clone() const {
    return std::make_shared<Ray>(begin_, direct_);
  }
  std::string Ray::ToString() const {
    std::string ans1;
    std::string ans2;
    std::string ans;
    ans1 = "Ray(" + begin_.ToString() + ", ";
    ans2 = "Vector(" + std::to_string(direct_.Xcor()) + ", " + std::to_string(direct_.Ycor()) + "))";
    ans = ans1 + ans2;
    return ans;
  }
  Point Ray::Begin() const {
    return begin_;
  }
  Vector Ray::Direct() const {
    return direct_;
  }
  double Ray::Distance(const Point& point) const {
    Vector v(direct_);
    Vector u(begin_, point);
    Point b (begin_.Xcor() + direct_.Xcor(), begin_.Ycor() + direct_.Ycor());
    Line line(begin_, b);
    if (ScalarProd(v, u) >= 0) {
      return line.Distance(point);
    }
    auto x = point.Xcor() - begin_.Xcor();
    auto y = point.Ycor() - begin_.Ycor();
    return static_cast<double>(x * x + y * y);
  }
}