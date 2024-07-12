#include <iostream>
void Reverse(int n, int a) {
  if (n != 1) {
    int b;
    std::cin >> b;
    Reverse(n - 1, b);
  }
  std::cout << a << " ";
}
int main() {
  int n;
  std::cin >> n;
  int a;
  std::cin >> a;
  Reverse(n, a);
}