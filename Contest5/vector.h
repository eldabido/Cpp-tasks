#ifndef H_VECTOR
#define H_VECTOR
#include <iostream>

namespace geometry {
class Vector {
 private:
  int x_, y_;

 public:
  Vector();
  Vector(int x, int y);
  int GetX() const;
  int GetY() const;
  std::string ToString() const;
  // Унарные операции.
  Vector operator+() const;
  Vector operator-() const;
  // Бинарные операции.
  Vector operator+(const Vector& other) const;
  Vector operator-(const Vector& other) const;
  Vector operator*(int val) const;
  Vector operator/(int val) const;
  // Операции с дальнейшим присваиванием.
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector& operator*=(int val);
  Vector& operator/=(int val);
  // Операции сравнения.
  bool operator==(const Vector& other) const;
};
}  // namespace geometry
#endif