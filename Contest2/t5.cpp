#include <iostream>

int main() {
  int n;
  int m;
  int w;
  std::cin >> n >> m >> w;
  char** arr = new char*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new char[m];
  }
  int a;
  int b;
  for (int i = 0; i < w; i++) {
    std::cin >> a >> b;
    arr[a - 1][b - 1] = '*';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int count = 0;
      if (arr[i][j] != '*') {
        if (i != 0 && arr[i - 1][j] == '*') {
          count++;
        }
        if (i != 0 && j != 0 && arr[i - 1][j - 1] == '*') {
          count++;
        }
        if (i != 0 && j != m - 1 && arr[i - 1][j + 1] == '*') {
          count++;
        }
        if (i != n - 1 && j != m - 1 && arr[i + 1][j + 1] == '*') {
          count++;
        }
        if (j != 0 && i != n - 1 && arr[i + 1][j - 1] == '*') {
          count++;
        }
        if (i != n - 1 && arr[i + 1][j] == '*') {
          count++;
        }
        if (j != 0 && arr[i][j - 1] == '*') {
          count++;
        }
        if (j != m - 1 && arr[i][j + 1] == '*') {
          count++;
        }
        arr[i][j] = '0' + count;
      }
    }
  }
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != m; j++) {
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