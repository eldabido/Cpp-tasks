#include <iostream>
#include "../ishape.h"
#include "../line.h"
#include "../point.h"
#include "../segment.h"
#include "../vector.h"
// реализация Line.

geometry::Line::Line(const Point& a, const Point& b) {
  a_ = a;
  b_ = b;
  // Коэффициэнты уравнения прямой.
  coef_a_ = b.GetY() - a.GetY();
  coef_b_ = a.GetX() - b.GetX();
  coef_c_ = a.GetY() * (b.GetX() - a.GetX()) - a.GetX() * (b.GetY() - a.GetY());
}

geometry::Point geometry::Line::GetA() const {
  return a_;
}

geometry::Point geometry::Line::GetB() const {
  return b_;
}

geometry::IShape& geometry::Line::Move(const Vector& vect) {
  a_ = Point(vect.GetX() + a_.GetX(), vect.GetY() + a_.GetY());
  b_ = Point(vect.GetX() + b_.GetX(), vect.GetY() + b_.GetY());
  coef_a_ = b_.GetY() - a_.GetY();
  coef_b_ = a_.GetX() - b_.GetX();
  coef_c_ = a_.GetY() * (b_.GetX() - a_.GetX()) - a_.GetX() * (b_.GetY() - a_.GetY());
  return *this;
}

bool geometry::Line::ContainsPoint(const Point& point) const {
  // Проверяем по параметрическому уравнению прямой.
  return (point.GetX() - GetA().GetX()) * (GetB().GetY() - GetA().GetY()) ==
         (GetB().GetX() - GetA().GetX()) * (point.GetY() - GetA().GetY());
}

bool geometry::Line::CrossesSegment(const Segment& segment) const {
  // Проверяем по уравнению прямой.
  int x = coef_a_ * segment.GetA().GetX() + coef_b_ * segment.GetA().GetY() + coef_c_;
  int y = coef_a_ * segment.GetB().GetX() + coef_b_ * segment.GetB().GetY() + coef_c_;
  return (x > 0 && y < 0) || (x < 0 && y > 0) || x == 0 || y == 0;
}

std::unique_ptr<geometry::IShape> geometry::Line::Clone() const {
  return std::make_unique<Line>(*this);
}

std::string geometry::Line::ToString() const {
  std::string str = "Line(";
  str += std::to_string(coef_a_);
  str += ", ";
  str += std::to_string(coef_b_);
  str += ", ";
  str += std::to_string(coef_c_);
  str += ")";
  return str;
}
