#include <iostream>
#include "array.h"

template <class T, class U, size_t N>
void Equals(const Array<T, N>& actual, const std::array<U, N>& required) {
  for (size_t i = 0; i < N; ++i) {
    if (actual[i] == required[i]) {
      std::cout << "yes\n";
    }
  }
}

int main() {
  const Array<int, 7> array{};
  if (array.Size() == 7 && !(array.Empty())) {
    std::cout << "yes yes yes";
  }
}