#ifndef H_POINT
#define H_POINT
#include <iostream>
#include "ishape.h"

namespace geometry {
class Point : public IShape {
 private:
  int x_;
  int y_;

 public:
  Point();
  Point(int x, int y);
  int GetX() const;
  int GetY() const;
  void SetX(int value);
  void SetY(int value);
  IShape& Move(const Vector& vect) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
  Vector operator-(const Point& sec) const;
};
}  // namespace geometry
#endif