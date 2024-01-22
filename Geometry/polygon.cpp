#include "../polygon.h"
#include "../segment.h"
#include "../point.h"
#include <iostream>

namespace geometry {
  Polygon::Polygon() = default;
  Polygon::Polygon(const std::vector<Point>& vertexes) {
    size_t n = vertexes.size();
    for (size_t i = 0; i < n; ++i) {
      vertexes_.push_back(vertexes[i]);
    }
  }
  IShape& Polygon::Move(const Vector& vector) {
    size_t n = vertexes_.size();
    for (size_t i = 0; i < n; ++i) {
      vertexes_[i].Move(vector);
    }
    return *this;
  }
  bool Polygon::ContainsPoint(const Point& point) const {
    if (PointOnSide(point)) {
      return true;
    }
    size_t n = vertexes_.size();
    const int64_t x = 2e7;
    Point h(x, point.Ycor() + 1);
    size_t counter = 0;
    Segment segment(point, h);
    for (size_t i = 0; i < n; ++i) {
      Segment side(vertexes_[i], vertexes_[(i + 1) % n]);
      if (segment.CrossesSegment(side)) {
        ++counter;
      }
    }
    return (counter % 2 != 0);
  }
  bool Polygon::CrossesSegment(const Segment& segment) const {
    size_t n = vertexes_.size();
    for (size_t i = 0; i < n; ++i) {
      Segment side(vertexes_[i], vertexes_[(i + 1) % n]);
      if (segment.CrossesSegment(side)) {
        return true;
      }
    }
    return false;
  }
  std::shared_ptr<IShape> Polygon::Clone() const {
    return std::make_shared<Polygon>(vertexes_);
  }
  std::string Polygon::ToString() const {
    std::string ans;
    ans = "Polygon(";
    size_t n = vertexes_.size();
    Point vertex;
    for (size_t i = 0; i < n - 1; ++i) {
      vertex = vertexes_[i];
      ans += vertex.ToString();
      ans += ", ";
    }
    ans += vertexes_[n - 1].ToString();
    ans += ")";
    return ans;
  }
  std::vector<Point> Polygon::Vertex() const {
    return vertexes_;
  }

  bool Polygon::PointOnSide(const Point& point) const {
    size_t n = vertexes_.size();
    for (size_t i = 0; i < n; ++i) {
      Segment side(vertexes_[i], vertexes_[(i + 1) % n]);
      if (point.CrossesSegment(side)) {
        return true;
      }
    }
    return false;
  }
}