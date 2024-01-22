#ifndef ISHAPE
#define ISHAPE

#include <string>
#include <memory>

namespace geometry {
  class Point;
  class Vector;
  class Segment;

class IShape {
 public:
  virtual IShape& Move(const Vector&) = 0;
  virtual bool ContainsPoint(const Point&) const = 0;
  virtual bool CrossesSegment(const Segment&) const = 0;
  virtual std::shared_ptr<IShape> Clone() const = 0;
  virtual std::string ToString() const = 0;
  virtual ~IShape() = default;
};
}

#endif