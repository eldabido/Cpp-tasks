#include <iostream>
#include <unordered_map>

int main() {
  int n = 0;
  std::cin >> n;
  std::unordered_map<int, int> colors;
  int color = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> color;
    colors[color] += 1;
  }
  int m = 0;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int x = 0;
    std::cin >> x;
    std::cout << colors[x] << "\n";
  }
}