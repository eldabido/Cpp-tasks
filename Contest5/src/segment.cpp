#include <iostream>
#include "../ishape.h"
#include "../point.h"
#include "../segment.h"
#include "../vector.h"
#include "../line.h"

// реализация Segment.

geometry::Segment::Segment(const Point& a, const Point& b) {
  a_ = a;
  b_ = b;
}

geometry::Point geometry::Segment::GetA() const {
  return a_;
}

geometry::Point geometry::Segment::GetB() const {
  return b_;
}

geometry::IShape& geometry::Segment::Move(const Vector& vect) {
  a_ = Point(vect.GetX() + a_.GetX(), vect.GetY() + a_.GetY());
  b_ = Point(vect.GetX() + b_.GetX(), vect.GetY() + b_.GetY());
  return *this;
}

bool geometry::Segment::ContainsPoint(const Point& point) const {
  // Проверяем по уравнению прямой, и смотрим, попадает ли точка в промежутки.
  return (point.GetX() - GetA().GetX()) * (GetB().GetY() - GetA().GetY()) ==
             (GetB().GetX() - GetA().GetX()) * (point.GetY() - GetA().GetY()) &&
         std::max(GetA().GetX(), GetB().GetX()) >= point.GetX() &&
         std::max(GetA().GetY(), GetB().GetY()) >= point.GetY() &&
         std::min(GetA().GetX(), GetB().GetX()) <= point.GetX() &&
         std::min(GetA().GetY(), GetB().GetY()) <= point.GetY();
}

bool geometry::Segment::CrossesSegment(const Segment& segment) const {
  // Проверяем в соответствии с презентацией.
  Line ab = Line(GetA(), GetB());
  Line cd = Line(segment.GetA(), segment.GetB());
  // Векторные произведения не должны равняться нулю одновременно.
  int cross1 = (GetB().GetX() - GetA().GetX()) * (segment.GetA().GetY() - GetA().GetY()) -
               (GetB().GetY() - GetA().GetY()) * (segment.GetA().GetX() - GetA().GetX());
  int cross2 = (GetB().GetX() - GetA().GetX()) * (segment.GetB().GetY() - GetA().GetY()) -
               (GetB().GetY() - GetA().GetY()) * (segment.GetB().GetX() - GetA().GetX());
  int cross3 = (segment.GetA().GetX() - segment.GetB().GetX()) * (GetA().GetY() - segment.GetA().GetY()) -
               (segment.GetA().GetY() - segment.GetB().GetY()) * (GetA().GetX() - segment.GetA().GetX());
  int cross4 = (segment.GetA().GetX() - segment.GetB().GetX()) * (GetB().GetY() - segment.GetA().GetY()) -
               (segment.GetA().GetY() - segment.GetB().GetY()) * (GetB().GetX() - segment.GetA().GetX());
  bool result1 = (cross1 != 0) || (cross2 != 0) || (cross3 != 0) || (cross4 != 0);
  bool result2 = (segment.ContainsPoint(GetA())) || (segment.ContainsPoint(GetB())) ||
                 (ContainsPoint(segment.GetA())) || (ContainsPoint(segment.GetB()));
  return (ab.CrossesSegment(segment) && cd.CrossesSegment(*this) && result1) || (!result1 && result2);
}

std::unique_ptr<geometry::IShape> geometry::Segment::Clone() const {
  return std::make_unique<Segment>(*this);
}

std::string geometry::Segment::ToString() const {
  std::string str = "Segment(";
  str += GetA().ToString();
  str += ", ";
  str += GetB().ToString();
  str += ")";
  return str;
}
