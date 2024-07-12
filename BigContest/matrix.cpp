#include <array>
#include <iostream>
#include <type_traits>
#include <utility>
#include "matrix.h"
#include <sstream>
#include "rational.h"
#include "rational.cpp"

template <class T, size_t N, size_t M>
void EqualMatrix(const Matrix<T, N, M>& matrix, const std::array<std::array<T, M>, N>& arr) {
  for (size_t i = 0u; i < N; ++i) {
    for (size_t j = 0u; j < M; ++j) {
      if (matrix(i, j) != arr[i][j]) {
        std::cout << "fuck\n";
        break;
      };
    }
  }
  std::cout << "yes\n";
}


int main() {
   Matrix<Rational, 3, 3> matrix{-1, 4, 9, 2, 5, -7, 0, 2, 0};
    Inverse(matrix);
    std::cout << matrix;
    Matrix<Rational, 2, 2> matr{2, -7, 0, 0};
    std::cout << Determinant(matr);
    EqualMatrix(matrix, std::array<std::array<Rational, 3>, 3>{Rational{7, 11}, Rational{9, 11}, Rational{-73, 22},
                                                               Rational{0}, Rational{0}, Rational{1, 2},
                                                               Rational{2, 11}, Rational{1, 11}, Rational{-13, 22}});
    
}