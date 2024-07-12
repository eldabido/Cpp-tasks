#ifndef H_ISHAPE
#define H_ISHAPE
#include <iostream>
#include <memory>
#include "vector.h"

namespace geometry {
class Segment;
class Point;

class IShape {
 public:
  virtual IShape& Move(const Vector& vect) = 0;
  virtual bool ContainsPoint(const Point& point) const = 0;
  virtual bool CrossesSegment(const Segment& segment) const = 0;
  virtual std::unique_ptr<IShape> Clone() const = 0;
  virtual std::string ToString() const = 0;
  virtual ~IShape() = default;
};
}  // namespace geometry
#endif