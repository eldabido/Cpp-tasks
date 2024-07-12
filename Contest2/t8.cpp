#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdint>
double Length(int64_t x1, int64_t x2, int64_t y1, int64_t y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
  int64_t x1;
  int64_t y1;
  int64_t x2;
  int64_t y2;
  int64_t x3;
  int64_t y3;
  double s;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  s = Length(x1, x2, y1, y2);
  s += Length(x1, x3, y1, y3);
  s += Length(x2, x3, y2, y3);
  std::cout << std::fixed << std::setprecision(6) << s;
}