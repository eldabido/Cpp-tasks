#ifndef H_MATRIX
#define H_MATRIX

#define MATRIX_SQUARE_MATRIX_IMPLEMENTED
#include <iostream>

class MatrixOutOfRange {

};

class MatrixIsDegenerateError {

};

template <typename T, size_t Rows, size_t Cols>
class Matrix {
 public:
  T matrix_[Rows][Cols];

  constexpr size_t RowsNumber() const {
    return Rows;
  }

  constexpr size_t ColumnsNumber() const {
    return Cols;
  }

  const T& operator()(size_t i, size_t j) const {
    return matrix_[i][j];
  }

  T& operator()(size_t i, size_t j) {
    return matrix_[i][j];
  }

  const T& At(size_t i, size_t j) const {
    if (i >= Rows || j >= Cols) {
      throw MatrixOutOfRange();
    }
    return matrix_[i][j];
  }

  T& At(size_t i, size_t j) {
    if (i >= Rows || j >= Cols) {
      throw MatrixOutOfRange();
    }
    return matrix_[i][j];
  }

  Matrix<T, Rows, Cols> operator+(const Matrix& other) const {
    Matrix<T, Rows, Cols> new_matr;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        new_matr(i, j) = matrix_[i][j] + other.matrix_[i][j];
      }
    }
    return new_matr;
  }

  Matrix<T, Rows, Cols> operator-(const Matrix& other) const {
    Matrix<T, Rows, Cols> new_matr;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        new_matr.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
      }
    }
    return new_matr;
  }

  template<size_t K>
  friend Matrix<T, Rows, K> operator*(const Matrix<T, Rows, Cols>& matrix1, const Matrix<T, Cols, K>& matrix2) {
    Matrix<T, Rows, K> new_matr;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < K; ++j) {
        for (size_t k = 0; k < Cols; ++k) {
          if (k == 0) {
            new_matr.matrix_[i][j] = matrix1.matrix_[i][k] * matrix2.matrix_[k][j];
          } else {
            new_matr.matrix_[i][j] += matrix1.matrix_[i][k] * matrix2.matrix_[k][j];
          }
        }
      }
    }
    return new_matr;
  }

  Matrix<T, Rows, Cols>& operator+=(const Matrix<T, Rows, Cols>& matrix2) {
    *this = *this + matrix2;
    return *this;
  }

  Matrix<T, Rows, Cols>& operator-=(const Matrix<T, Rows, Cols>& matrix2) {
    *this = *this - matrix2;
    return *this;
  }

  template<size_t K>
  Matrix<T, Rows, K>& operator*=(const Matrix<T, K, Cols>& matrix2) {
    *this = *this * matrix2;
    return *this;
  }

  friend Matrix<T, Rows, Cols> operator*(const Matrix<T, Rows, Cols>& matr, const T& scalar) {
    Matrix<T, Rows, Cols> new_matr;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        new_matr(i, j) = scalar * matr.matrix_[i][j];
      }
    }
    return new_matr;
  }

  friend Matrix<T, Rows, Cols> operator*(const T& scalar, const Matrix<T, Rows, Cols>& matr) {
    Matrix<T, Rows, Cols> new_matr;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        new_matr.matrix_[i][j] = scalar * matr.matrix_[i][j];
      }
    }
    return new_matr;
  }

  friend Matrix<T, Rows, Cols> operator/(const Matrix<T, Rows, Cols>& matr, const T& scalar) {
    Matrix<T, Rows, Cols> new_matr;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        new_matr.matrix_[i][j] = matr.matrix_[i][j] / scalar;
      }
    }
    return new_matr;
  }

  Matrix<T, Rows, Cols>& operator*=(const T& scalar) {
    *this = *this * scalar;
    return *this;
  }

  Matrix<T, Rows, Cols>& operator/=(const T& scalar) {
    *this = *this / scalar;
    return *this;
  }

  bool operator==(const Matrix& other) const {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        if (matrix_[i][j] != other.matrix_[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(const Matrix& other) const {
    return !(*this == other);
  }

  friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
      for (size_t i = 0; i < Rows; ++i) {
        for (size_t j = 0; j < Cols; ++j) {
          is >> matrix.matrix_[i][j];
        }
      }
      return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        if (j != Cols - 1) {
          os << matrix.matrix_[i][j] << " ";
        } else {
          os << matrix.matrix_[i][j];
        }
      }
      os << std::endl;
    }
    return os;
  }
};

template<typename T, size_t N, size_t M>
Matrix<T, N, M> GetTransposed(const Matrix<T, M, N>& matr) {
  Matrix<T, N, M> transp_matr;
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      transp_matr.matrix_[j][i] = matr.matrix_[i][j];
    }
  }
  return transp_matr;
};

template<typename T, size_t M, size_t N>
Matrix<T, N, M> Transpose(Matrix<T, M, N>& matrix) {
  Matrix<T, N, M> transp_matr;
  if (M == N) {
    T tmp;
    for (size_t i = 0; i < N - 1; ++i) {
      for (size_t j = i + 1; j < N; ++j) {
        tmp = matrix(j, i);
        matrix(j, i) = matrix(i, j);
        matrix(i, j) = tmp;
      }
    }
  } else {
    matrix = GetTransposed(matrix);
  }
  return matrix;
}

template<typename T, size_t N>
T Trace(const Matrix<T, N, N>& matrix) {
  T sum = 0;
  for (size_t i = 0; i < N; ++i) {
    sum += matrix(i, i);
  }
  return sum;
}

template <typename T, size_t N>
T Determinant(const Matrix<T, N, N> matrix) {
   Matrix<T, N, N> a = matrix;
   T det;
   for (size_t i = 0; i < N - 1; i++) {
      // assert(a(i, i) == 0);
      for (size_t j = i + 1; j < N; j++) {
         for (size_t k = i + 1; k < N; k++) {
            a(j, k) = a(j, k) * a(i, i) - a(j, i) * a(i, k);
	          if (i != 0) {
              a(j, k) /= a(i - 1,i - 1);
            }
         }
      }
   }
   return a(N - 1,N - 1);
}

template <typename T, size_t N>
Matrix<T, N, N> GetInversed(const Matrix<T, N, N>& matrix) {
  T det = Determinant(matrix);
  if (det == 0) {
    throw MatrixIsDegenerateError();
  }
  Matrix<T, N, N> alg_m;
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      if (N == 1) {
        alg_m(i, j) = T(1);
      } else {
        alg_m(i, j) = Minor(matrix, i, j);
      }
      if ((i + j) % 2 == 1) {
        alg_m(i, j) = -alg_m(i, j);
      }
      alg_m(i, j) = alg_m(i, j) / det;
    }
  }
  return GetTransposed(alg_m);
}

template<typename T, size_t N>
Matrix<T, N, N> Inverse(Matrix<T, N, N>& matrix) {
  matrix = GetInversed(matrix);
  return matrix;
}

template <typename T, size_t N>
T Minor(const Matrix<T, N, N>& matrix, size_t row, size_t col) {
  size_t del_i = 0;
  size_t del_j = 0;
  Matrix<T, N, N> minor;
  for (size_t i = 0; i < N - 1; ++i) {
    if (i == row) {
      del_i = 1;
    }
    for (size_t j = 0; j < N - 1; ++j) {
      if (j == col) {
        del_j = 1;
      }
      minor(i, j) = matrix(i + del_i, j + del_j);
    }
    del_j = 0;
  }
  for (size_t i = 0; i < N; ++i) {
    if (i == N - 1) {
      minor(i, N - 1) = 1;
    } else {
      minor(i, N - 1) = 0;
      minor(N - 1, i) = 0; 
    }
  }
  std::cout << minor << "fsdf\n";
  return Determinant(minor);
}

#endif