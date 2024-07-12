#include <iostream>

int main() {
  size_t n;
  size_t m;
  std::cin >> n >> m;
  int **arr = new int *[n];
  for (size_t i = 0; i != n; i++) {
    arr[i] = new int[m];
  }
  for (size_t i = 0; i != n; i++) {
    for (size_t j = 0; j != m; j++) {
      if (i == 0 || j == 0) {
        arr[i][j] = 1;
      }
    }
  }
  for (size_t i = 1; i != n; i++) {
    for (size_t j = 1; j != m; j++) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }
  for (size_t i = 0; i != n; i++) {
    for (size_t j = 0; j != m; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (size_t i = 0; i != n; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}