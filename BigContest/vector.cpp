#include <iostream>
#include "vector.h"
#include <vector>
#include <utility>

template <class T>
void Equal(const Vector<T>& real, const std::vector<T>& required) {
  if (real.Size() == required.size()) {
    for (size_t i = 0u; i < real.Size(); ++i) {
      if (real[i] != required[i]) {
        std::cout << "fuck";
        break;
      }
    }
    std::cout << "yes";
  }
}


int main() {
    const Vector<int> v{1, 2, 3, 4, 5};
    Equal(v, std::vector<int>{1, 2, 3, 4, 5});
  
}