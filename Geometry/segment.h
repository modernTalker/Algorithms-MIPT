#ifndef SEGMENT
#define SEGMENT

#include "ishape.h"
#include "point.h"

namespace geometry {
  class Segment : public IShape {
    public:
    Segment();
    Segment(const Point& first, const Point& second);
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::shared_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    Point PointA() const;
    Point PointB() const;

    double Distance(const Point& point) const;

   private:
    Point begin_;
    Point end_;
  };
}

#endif