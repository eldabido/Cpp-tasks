#include <iostream>
#include <cstdint>
#include <cmath>
int main() {
  int64_t n;
  std::cin >> n;
  int flag = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      std::cout << "composite";
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    std::cout << "prime";
  }
  return 0;
}