#ifndef CIRCLE
#define CIRCLE

#include "ishape.h"
#include "point.h"

namespace geometry {
  class Circle : public  IShape {
   public:
    Circle();
    Circle(const Point& point, const int64_t radius);
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::shared_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    Point Center() const;
    int64_t Radius() const;

    bool OnCircle(const Point& point) const;

   private:
    Point center_;
    int64_t radius_;
  };
}

#endif