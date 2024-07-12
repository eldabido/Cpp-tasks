#include <iostream>
#include "../ishape.h"
#include "../point.h"
#include "../segment.h"
#include "../vector.h"

// Реализация Point.

geometry::Point::Point() {
  x_ = 0;
  y_ = 0;
}

geometry::Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}

int geometry::Point::GetX() const {
  return x_;
}

int geometry::Point::GetY() const {
  return y_;
}

void geometry::Point::SetX(int value) {
  x_ += value;
}

void geometry::Point::SetY(int value) {
  y_ += value;
}

geometry::IShape& geometry::Point::Move(const Vector& vect) {
  x_ += vect.GetX();
  y_ += vect.GetY();
  return *this;
}

bool geometry::Point::ContainsPoint(const Point& point) const {
  return x_ == point.x_ && y_ == point.y_;
}

bool geometry::Point::CrossesSegment(const Segment& segment) const {
  // Проверяем по параметрическому уравнению прямой и смотрим, чтоб точка входила в промежуток.
  return (x_ - segment.GetA().x_) * (segment.GetB().y_ - segment.GetA().y_) ==
             (segment.GetB().x_ - segment.GetA().x_) * (y_ - segment.GetA().y_) &&
         std::max(segment.GetA().x_, segment.GetB().x_) >= x_ && std::max(segment.GetA().y_, segment.GetB().y_) >= y_ &&
         std::min(segment.GetA().x_, segment.GetB().x_) <= x_ && std::min(segment.GetA().y_, segment.GetB().y_) <= y_;
}

std::unique_ptr<geometry::IShape> geometry::Point::Clone() const {
  return std::make_unique<Point>(*this);
}

std::string geometry::Point::ToString() const {
  std::string str = "Point(";
  str += std::to_string(x_);
  str += ", ";
  str += std::to_string(y_);
  str += ")";
  return str;
}

geometry::Vector geometry::Point::operator-(const Point& sec) const {
  return Vector(x_ - sec.x_, y_ - sec.y_);
}
