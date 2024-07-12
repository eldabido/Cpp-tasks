#include <iostream>

size_t GetNextIndex(size_t cur, size_t row_size, int dir) {
  if (dir == 0) {
    cur -= row_size;
  } else if (dir == 1) {
    cur++;
  } else if (dir == 2) {
    cur += row_size;
  } else {
    cur--;
  }
  return static_cast<size_t>(cur);
}

int main() {
  size_t n;
  std::cin >> n;
  int* m = new int[n * n];
  for (size_t i = 0; i != n * n; ++i) {
    m[i] = i < n ? 1 : 0;
  }
  size_t step = n;
  int dir = 2;
  size_t cur = n - 1;
  while (step >= 3) {
    for (size_t k = 0; k < 2; ++k) {
      for (size_t j = 1; j != step; ++j) {
        cur = GetNextIndex(cur, n, dir);
        m[cur] = 1;
      }
      dir = dir == 3 ? 0 : dir + 1;
    }
    step -= 2;
  }
  for (size_t i = 0; i != n * n; ++i) {
    if (i % n == 0 && i != 0) {
      std::cout << std::endl;
    }
    std::cout << m[i];
  }
  delete[] m;
  return 0;
}