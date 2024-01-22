#ifndef LINE
#define LINE

#include "ishape.h"
#include "point.h"

namespace geometry {
  class Line : public IShape {
   public:
    Line();
    Line(int64_t a, int64_t b, int64_t c);
    Line(const Point& first, const Point& second);
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::shared_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    int64_t CoefA() const;
    int64_t CoefB() const;
    int64_t CoefC() const;

    double Distance(const Point& point) const;

   private:
    int64_t a_;
    int64_t b_;
    int64_t c_;
  };
}

#endif