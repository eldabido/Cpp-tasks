#include <iostream>
bool IsDigit(unsigned char c) {
  if (c >= '0' && c <= '9') {
    bool res = true;
    return res;
  }
  bool res = false;
  return res;
}

int main() {
  unsigned char c;
  std::cin >> c;
  if (IsDigit(c)) {
    std::cout << "yes";
  } else {
    std::cout << "no";
  }
  return 0;
}