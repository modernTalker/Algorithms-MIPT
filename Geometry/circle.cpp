#include "../circle.h"
#include "../segment.h"
#include "../point.h"
#include <iostream>

namespace geometry {
  Circle::Circle() = default;
  Circle::Circle(const Point& point, const int64_t radius) : center_(point), radius_(radius) {
  }
  IShape& Circle::Move(const Vector& vector) {
    center_.Move(vector);
    return *this;
  }
  bool Circle::ContainsPoint(const Point& point) const {
    auto x = (point.Xcor() - center_.Xcor());
    auto y = (point.Ycor() - center_.Ycor());
    return (x * x + y * y <= radius_ * radius_); 
  }

  bool Circle::OnCircle(const Point& point) const {
    auto x = (point.Xcor() - center_.Xcor());
    auto y = (point.Ycor() - center_.Ycor());
    return (x * x + y * y == radius_ * radius_);
  }


  bool Circle::CrossesSegment(const Segment& segment) const {
    Point point1 = segment.PointA();
    Point point2 = segment.PointB();
    bool on1 = OnCircle(point1);
    bool on2 = OnCircle(point2);
    if (on1 || on2) {
      return true;
    }
    if (ContainsPoint(point1) && ContainsPoint(point2)) {
      return false;
    }
    return segment.Distance(center_) <= static_cast<double>(radius_ * radius_);
  }
  std::shared_ptr<IShape> Circle::Clone() const {
    return std::make_shared<Circle>(center_, radius_); 
  }
  std::string Circle::ToString() const {
    std::string ans;
    ans = "Circle(" + center_.ToString() + ", " + std::to_string(radius_) + ")";
    return ans;
  }
  Point Circle::Center() const {
    return center_;
  }
  int64_t Circle::Radius() const {
    return radius_;
  }
}