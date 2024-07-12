#include <iostream>
#include "../ishape.h"
#include "../point.h"
#include "../segment.h"
#include "../circle.h"
#include "cmath"
#include "../vector.h"

// реализация Circle.

geometry::Circle::Circle(const Point& cent, int rad) {
  center_ = cent;
  radius_ = rad;
}

geometry::IShape& geometry::Circle::Move(const Vector& vect) {
  center_.Move(vect);
  return *this;
}

bool geometry::Circle::ContainsPoint(const Point& point) const {
  // Просто подставляем в уравнение окружности.
  return (point.GetX() - center_.GetX()) * (point.GetX() - center_.GetX()) +
             (point.GetY() - center_.GetY()) * (point.GetY() - center_.GetY()) <=
         radius_ * radius_;
}

bool geometry::Circle::CrossesSegment(const Segment& segment) const {
  // Сначала проверяем, что концы отрезка не находятся внутри (если они обе внутри, то пересечения нет).
  bool result;
  if ((result = ((segment.GetA().GetX() + center_.GetX()) * (segment.GetA().GetX() + center_.GetX()) +
                     (segment.GetA().GetY() + center_.GetY()) * (segment.GetA().GetY() + center_.GetY()) <
                 radius_ * radius_) &&
                ((segment.GetB().GetX() + center_.GetX()) * (segment.GetB().GetX() + center_.GetX()) +
                     (segment.GetB().GetY() + center_.GetY()) * (segment.GetB().GetY() + center_.GetY()) <
                 radius_ * radius_))) {
    return !result;
  }
  // Далее считаем расстояние от центра до отрезка, если оно больше радиуса, то нет пересечения.
  double l1 = std::sqrt(std::pow(std::abs(segment.GetA().GetX() - segment.GetB().GetX()), 2) +
                        std::pow(std::abs(segment.GetA().GetY() - segment.GetB().GetY()), 2));
  double l2 = std::sqrt(std::pow(std::abs(segment.GetA().GetX() - center_.GetX()), 2) +
                        std::pow(std::abs(segment.GetA().GetY() - center_.GetY()), 2));
  double l3 = std::sqrt(std::pow(std::abs(center_.GetX() - segment.GetB().GetX()), 2) +
                        std::pow(std::abs(center_.GetY() - segment.GetB().GetY()), 2));
  double semiper = (l1 + l2 + l3) / 2;
  double sq = std::sqrt(semiper * (semiper - l1) * (semiper - l2) * (semiper - l3));

  return 2 * sq / l1 <= radius_;
}

std::unique_ptr<geometry::IShape> geometry::Circle::Clone() const {
  return std::make_unique<Circle>(*this);
}

std::string geometry::Circle::ToString() const {
  std::string str = "Circle(";
  str += center_.ToString();
  str += ", ";
  str += std::to_string(radius_);
  str += ")";
  return str;
}