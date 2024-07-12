#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::cout << "Введите размерности массивов: ";
  int n;
  int m;
  std::cin >> n >> m;

  std::vector<int> v1;
  std::vector<int> v2;
  int elem;
  std::cout << "Введите элементы массива 1: ";
  for (int i = 0; i < n; ++i) {
    std::cin >> elem;
    v1.push_back(elem);
  }
  std::cout << "Введите элементы массива 2: ";
  for (int i = 0; i < m; ++i) {
    std::cin >> elem;
    v2.push_back(elem);
  }
  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::vector<int> v;
  size_t size1 = v1.size();
  size_t size2 = v2.size();
  size_t i = 0;
  size_t j = 0;
  while (i < size1 && j < size2) {
    if (v1[i] < v2[j]) {
      v.push_back(v1[i]);
      ++i;
    } else {
      if (v1[i] == v2[j]) {
        ++i;
      }
      ++j;
    }
  }
  while (i < size1) {
    v.push_back(v1[i]);
    ++i;
  }

  for (auto num: v) {
    std::cout << num << " ";
  }
  std::cout << "\n";
}