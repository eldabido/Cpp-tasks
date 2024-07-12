#include <iostream>

void Sort(int* begin, int* end) {
  for (int i = 0; begin + i < end; i++) {
    int flag = 0;
    for (int j = 0; begin + j < end - i - 1; j++) {
      if (*(begin + j) > *(begin + j + 1)) {
        std::swap(*(begin + j), *(begin + j + 1));
        flag = 1;
      }
    }
    if (flag == 0) {
      break;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  Sort(arr, arr + n);
  for (int i = 0; i != n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}