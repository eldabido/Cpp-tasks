#ifndef H_ISSORTEDUNTIL
#define H_ISSORTEDUNTIL
#include <iostream>
template <typename T>
T* IsSortedUntil(T* begin, T* end) {
  T* cur = begin + 1;
  while (begin < end) {
    if (*cur < *begin) {
      return cur;
    }
    ++begin;
    ++cur;
  }
  return begin;
}
#endif