#ifndef H_LINE
#define H_LINE
#include <iostream>
#include "ishape.h"
#include "point.h"
#include "segment.h"
namespace geometry {
class Line : public IShape {
 private:
  Point a_;
  Point b_;
  int coef_a_;
  int coef_b_;
  int coef_c_;

 public:
  Line(const Point& a, const Point& b);
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