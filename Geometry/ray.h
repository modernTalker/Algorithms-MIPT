#ifndef RAY
#define RAY

#include "ishape.h"
#include "point.h"

namespace geometry {
  class Ray : public IShape {
   public:
    Ray();
    Ray(const Point& first, const Point& second);
    Ray(const Point& first, const Vector& vector);
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::shared_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    Point Begin() const;
    Vector Direct() const;

    double Distance(const Point& point) const;

   private:
    Point begin_;
    Vector direct_;
  };
}

#endif