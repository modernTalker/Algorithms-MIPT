#ifndef POLYGON
#define POLYGON

#include "ishape.h"
#include "point.h"
#include <vector>

namespace geometry {
  class Polygon : public IShape {
    public:
    Polygon();
    explicit Polygon(const std::vector<Point>& vertexes);
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::shared_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    std::vector<Point> Vertex() const;

    bool PointOnSide(const Point& point) const;

   private:
    std::vector<Point> vertexes_;
  };
}

#endif