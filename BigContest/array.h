#ifndef H_ARRAY
#define H_ARRAY

#include <iostream>

class ArrayOutOfRange {

};

template <typename T, size_t N>
class Array {
 public:
  T arr_[N];

  const T& operator[](size_t i) const {
    return arr_[i];
  }

  T& operator[](size_t i) {
    return arr_[i];
  }

  const T& At(size_t i) const {
    if (i >= N) {
      throw ArrayOutOfRange();
    }
    return arr_[i];
  }

  T& At(size_t i) {
    if (i >= N) {
      throw ArrayOutOfRange();
    }
    return arr_[i];
  }

  T& Front() {
    return arr_[0];
  }

   const T& Front() const {
    return arr_[0];
  }

  T& Back() {
    return arr_[N - 1];
  }

  const T& Back() const {
    return arr_[N - 1];
  }

  T* Data() {
    return arr_;
  }

  const T* Data() const {
    return arr_;
  }

  size_t Size() const {
    return N;
  }

  bool Empty() const {
    return N == 0;
  }

  void Fill(const T& value) {
    for (size_t i = 0; i < N; ++i) {
      arr_[i] = value;
    }
  }

  void Swap(Array<T, N>& other) {
    for (size_t i = 0; i < N; ++i) {
      std::swap(arr_[i], other[i]);
    }
  }
};

#endif