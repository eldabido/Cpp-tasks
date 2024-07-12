#include <iostream>
#include "../ishape.h"
#include "../point.h"
#include "../ray.h"
#include "../segment.h"
#include "../vector.h"
#include "../line.h"

// Реализация Ray.

geometry::Ray::Ray(const Point& a, const Point& b) {
  a_ = a;
  b_ = b;
  vect_ = Vector(b.GetX() - a.GetX(), b.GetY() - a.GetY());
}

geometry::Point geometry::Ray::GetA() const {
  return a_;
}

geometry::Point geometry::Ray::GetB() const {
  return b_;
}

geometry::Vector geometry::Ray::GetVect() const {
  return vect_;
}

geometry::IShape& geometry::Ray::Move(const Vector& vect) {
  a_ = Point(vect.GetX() + a_.GetX(), vect.GetY() + a_.GetY());
  b_ = Point(vect.GetX() + b_.GetX(), vect.GetY() + b_.GetY());
  return *this;
}

bool geometry::Ray::ContainsPoint(const Point& point) const {
  // Проверка в соответствии с презентацией.
  return (vect_.GetX() * (point.GetX() - GetA().GetX()) + vect_.GetY() * (point.GetY() - GetA().GetY()) >= 0) &&
         (vect_.GetX() * (point.GetY() - GetA().GetY()) - vect_.GetY() * (point.GetX() - GetA().GetX()) == 0);
}

bool geometry::Ray::CrossesSegment(const Segment& segment) const {
  // Тоже проверка в соответствии с презентацией.
  int cross1 = (GetA().GetX() - segment.GetA().GetX()) * (segment.GetB().GetY() - segment.GetA().GetY()) -
               (segment.GetB().GetX() - segment.GetA().GetX()) * (GetA().GetY() - segment.GetA().GetY());
  int cross2 = vect_.GetX() * (segment.GetB().GetY() - segment.GetA().GetY()) -
               vect_.GetY() * (segment.GetB().GetX() - segment.GetA().GetX());
  return ((Line(GetA(), GetB())).CrossesSegment(segment)) &&
         ((cross1 > 0 && cross2 < 0) || (cross1 < 0 && cross2 > 0) || ContainsPoint(segment.GetA()) ||
          ContainsPoint(segment.GetB()));
}

std::unique_ptr<geometry::IShape> geometry::Ray::Clone() const {
  return std::make_unique<Ray>(*this);
}

std::string geometry::Ray::ToString() const {
  std::string str = "Ray(";
  str += GetA().ToString();
  str += ", ";
  str += vect_.ToString();
  str += ")";
  return str;
}
