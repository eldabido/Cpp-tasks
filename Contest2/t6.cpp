#include <iostream>
int Gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (a % b == 0) {
    return b;
  }
  if (b % a == 0) {
    return a;
  }
  if (a > b) {
    return Gcd(a % b, b);
  }
  return Gcd(a, b % a);
}
int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  std::cin >> arr[0];
  std::cin >> arr[1];
  int gcd = Gcd(arr[0], arr[1]);
  for (int i = 2; i < n; i++) {
    std::cin >> arr[i];
    if (arr[i] == 1) {
      gcd = 1;
      break;
    }
    if (gcd != 1) {
      gcd = Gcd(gcd, arr[i]);
    } else {
      break;
    }
  }
  std::cout << gcd;
  delete[] arr;
  return 0;
}