#include "../segment.h"
#include "../line.h"
#include "../point.h"
#include "../ray.h"
#include <iostream>

namespace geometry {
  Segment::Segment() = default;
  Segment::Segment(const Point& first, const Point& second) : begin_(first), end_(second) {
  }
  IShape& Segment::Move(const Vector& vector) {
    begin_.Move(vector);
    end_.Move(vector);
    return *this;
  }
  bool Segment::ContainsPoint(const Point& point) const {
    Vector v1(begin_, end_);
    Vector v2(begin_, point);
    Vector u1(point, begin_);
    Vector u2(point, end_);
    return (VectorProd(v1, v2) == 0) && (ScalarProd(u1, u2) <= 0);
  }
  bool Segment::CrossesSegment(const Segment& segment) const {
    Point a = begin_;
    Point b = end_;
    Point c = segment.PointA();
    Point d = segment.PointB();
    Vector ab(a, b);
    Vector ac(a, c);
    Vector ad(a, d);
    Vector cd(c, d);
    Vector cb(c, b);
    Vector ca(c, a);
    Line line(a, b);
    if (VectorProd(ab, ac) == 0 && VectorProd(ab, ad) == 0 && VectorProd(cd, ca) == 0 &&
        VectorProd(cd, cb) == 0) {
      return (c.CrossesSegment(*this) || d.CrossesSegment(*this) ||
              a.CrossesSegment(segment) || b.CrossesSegment(segment));
    }
    return VectorProd(ab, ac) * VectorProd(ab, ad) <= 0 && VectorProd(cd, ca) * VectorProd(cd, cb) <= 0;
  }
  std::shared_ptr<IShape> Segment::Clone() const {
    return std::make_shared<Segment>(begin_, end_);
  }
  std::string Segment::ToString() const {
    std::string ans1;
    std::string ans2;
    std::string ans;
    ans1 = "Segment(" + begin_.ToString() + ", ";
    ans2 = end_.ToString() + ")";
    ans = ans1 + ans2;
    return ans;
  }
  Point Segment::PointA() const {
    return begin_;
  }
  Point Segment::PointB() const {
    return end_;
  }
  double Segment::Distance(const Point& point) const {
    Ray ray1(begin_, end_);
    Ray ray2(end_, begin_);
    return std::max(ray1.Distance(point), ray2.Distance(point));
  }

}