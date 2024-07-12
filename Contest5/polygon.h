#ifndef H_POLYGON
#define H_POLYGON
#include <iostream>
#include "ishape.h"
#include "point.h"
#include "vector.h"
#include "segment.h"
#include <vector>

namespace geometry {
class Polygon : public IShape {
 private:
  std::vector<Point> vertices_;
  size_t size_;

 public:
  explicit Polygon(std::vector<Point> verts);
  IShape& Move(const Vector& vect) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
  ~Polygon() override;
};
}  // namespace geometry
#endif