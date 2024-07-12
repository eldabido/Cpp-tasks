#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> mass(n);
  // Написано "Старайтесь избегать циклов", то есть в крайнем случае можно.
  // Не знаю просто, как тогда инициализировать.
  for (int i = 0; i < n; ++i) {
    std::cin >> mass[i];
  }
  int x = 0;
  std::cin >> x;
  std::cout << std::count(mass.begin(), mass.end(), x);
}