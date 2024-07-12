#include "range.h"

int main() {
  const int begin = -7;
  const int end = 19;
  const int step = 5;

  const auto range = Range(begin, end, step);
  int i = begin + (end - begin + step - 1) / step * step - step;
  for (auto it = range.rbegin(); it != range.rend(); ++it) {
    std::cout << *it;
    if (*it != i) {
      std::cout << "fuck";
    }
    i -= step;
  }
  if (i != begin - step) {
    std::cout << "fuck";
  }
  return 0;
}