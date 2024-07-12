#include <iostream>
void Hanoi(int n, int first, int second, int third) {
  if (n == 1) {
    std::cout << 1 << " " << first << " " << third << std::endl;
  } else {
    Hanoi(n - 1, first, third, second);
    std::cout << n << " " << first << " " << third << std::endl;
    Hanoi(n - 1, second, first, third);
  }
}

int main() {
  int n;
  std::cin >> n;
  Hanoi(n, 1, 2, 3);
  return 0;
}