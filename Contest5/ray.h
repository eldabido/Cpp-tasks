#ifndef H_RAY
#define H_RAY
#include <iostream>
#include "ishape.h"
#include "point.h"
#include "segment.h"
#include "vector.h"

namespace geometry {
class Ray : public IShape {
 private:
  Point a_;
  Point b_;
  Vector vect_;

 public:
  Ray(const Point& a, const Point& b);
  Point GetA() const;
  Point GetB() const;
  Vector GetVect() const;
  IShape& Move(const Vector& vect) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
#endif