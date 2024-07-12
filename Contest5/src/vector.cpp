#include <iostream>
#include "../vector.h"

// реализация Vector.

geometry::Vector::Vector() {
  x_ = 0;
  y_ = 0;
}

geometry::Vector::Vector(int x, int y) {
  x_ = x;
  y_ = y;
}

int geometry::Vector::GetX() const {
  return x_;
}

int geometry::Vector::GetY() const {
  return y_;
}

std::string geometry::Vector::ToString() const {
  std::string str = "Vector(";
  str += std::to_string(x_);
  str += ", ";
  str += std::to_string(y_);
  str += ")";
  return str;
}

// Унарные операции.
geometry::Vector geometry::Vector::operator+() const {
  return *this;
}

geometry::Vector geometry::Vector::operator-() const {
  return {-x_, -y_};
}

// Бинарные операции.
geometry::Vector geometry::Vector::operator+(const Vector& other) const {
  return {x_ + other.x_, y_ + other.y_};
}

geometry::Vector geometry::Vector::operator-(const Vector& other) const {
  return {x_ - other.x_, y_ - other.y_};
}

geometry::Vector geometry::Vector::operator*(int val) const {
  return {val * x_, val * y_};
}

geometry::Vector geometry::Vector::operator/(int val) const {
  if (val != 0) {
    return {x_ / val, y_ / val};
  }
  return *this;
}

// Операции с дальнейшим присваиванием.
geometry::Vector& geometry::Vector::operator+=(const Vector& other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

geometry::Vector& geometry::Vector::operator-=(const Vector& other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

geometry::Vector& geometry::Vector::operator*=(int val) {
  x_ *= val;
  y_ *= val;
  return *this;
}

geometry::Vector& geometry::Vector::operator/=(int val) {
  if (val != 0) {
    x_ /= val;
    y_ /= val;
  } else {
    std::cerr << "Error: Division by zero\n";
  }
  return *this;
}

// Операции сравнения.
bool geometry::Vector::operator==(const Vector& other) const {
  return x_ == other.x_ && y_ == other.y_;
}
