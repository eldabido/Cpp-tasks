#ifndef H_CIRCLE
#define H_CIRCLE
#include <iostream>
#include "ishape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"

namespace geometry {
class Circle : public IShape {
 private:
  Point center_;
  int radius_;

 public:
  Circle(const Point& cent, int rad);
  IShape& Move(const Vector& vect) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
#endif