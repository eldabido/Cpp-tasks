#include <iostream>

int main() {
  int n;
  int m;
  int s;
  int k;
  std::cin >> n >> m;
  int **arr = new int *[n];
  for (int i = 0; i != n; i++) {
    arr[i] = new int[m];
  }
  int count = 0;
  for (int i = 0; i < n + m; i++) {
    s = i - m > 0 ? i - m : 0;
    k = i < n ? i : n;
    for (int j = s; j < k; j++) {
      arr[j][i - j - 1] = count++;
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