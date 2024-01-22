#include "../line.h"
#include "../point.h"
#include "../segment.h"
#include <iostream>

namespace geometry {
  Line::Line() = default;
  Line::Line(int64_t a, int64_t b, int64_t c) : a_(a), b_(b), c_(c) {
  }
  Line::Line(const Point& first, const Point& second) {
    a_ = first.Ycor() - second.Ycor();
    b_ = second.Xcor() - first.Xcor();
    c_ = (first.Xcor() * second.Ycor() - second.Xcor() * first.Ycor());
  }
  IShape& Line::Move(const Vector& vector) {
    c_ -= vector.Xcor() * a_ + vector.Ycor() * b_;
    return *this;
  }
  bool Line::ContainsPoint(const Point& point) const {
    return (a_ * point.Xcor() + b_ * point.Ycor() + c_ == 0);
  }
  bool Line::CrossesSegment(const Segment& segment) const {
    auto x1 = segment.PointA().Xcor();
    auto y1 = segment.PointA().Ycor();
    auto x2 = segment.PointB().Xcor();
    auto y2 = segment.PointB().Ycor();
    return ((a_ * x1 + b_ * y1 + c_) * (a_ * x2 + b_ * y2 + c_) <= 0);
  }
  std::shared_ptr<IShape> Line::Clone() const {
    return std::make_shared<Line>(a_, b_, c_); 
  }
  std::string Line::ToString() const {
    std::string ans;
    ans = "Line(" + std::to_string(a_) + ", " + std::to_string(b_) + ", " + std::to_string(c_) + ")";
    return ans;
  }
  int64_t Line::CoefA() const {
    return a_;
  }
  int64_t Line::CoefB() const {
    return b_;
  }
  int64_t Line::CoefC() const {
    return c_;
  }
  double Line::Distance(const Point& point) const {
    auto numerator = static_cast<double>(a_ * point.Xcor() + b_ * point.Ycor() + c_);
    numerator *= numerator;
    auto denominator = static_cast<double>(a_ * a_ + b_ * b_);
    return numerator / static_cast<double>(denominator);
  }
}