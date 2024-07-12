#ifndef H_SEGMENT
#define H_SEGMENT
#include <iostream>
#include "ishape.h"
#include "point.h"

namespace geometry {
class Segment : public IShape {
 private:
  Point a_;
  Point b_;

 public:
  Segment(const Point& a, const Point& b);
  Point GetA() const;
  Point GetB() const;
  IShape& Move(const Vector& vect) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
#endif