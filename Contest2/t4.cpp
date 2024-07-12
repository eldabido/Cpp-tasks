#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int** arr = new int*[n];
  for (int i = 0; i != n; i++) {
    arr[i] = new int[n];
  }
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != n; j++) {
      if (j == n - i - 1) {
        arr[i][j] = 1;
      } else if (i < n - j - 1) {
        arr[i][j] = 0;
      } else {
        arr[i][j] = 2;
      }
    }
  }
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i != n; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}