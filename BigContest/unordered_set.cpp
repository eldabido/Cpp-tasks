#include <iostream>
#include "unordered_set.h"
#include <string>
#include <forward_list>
#include <vector>
#include <sstream>

int main() {
  UnorderedSet<std::string> us;
  size_t expected_capacity = 1;
  for (size_t i = 0u; i < 10u; ++i) {
    const auto str = std::to_string(i);
    if (i % 2u == 0u) {
      us.Insert(str);
    } else {
      us.Insert(std::move(str));
    }
    if (i + 1 > expected_capacity) {
      expected_capacity *= 2;
    }
    std::cout << expected_capacity;
    if (us.Size() != i + 1) {
      std::cout << "fuck1";
    }
    if (us.Empty()) {
      std::cout << "fuck2";
    }
    std::cout << us.BucketCount();
    if (us.BucketCount() != expected_capacity) {
      std::cout << "fuck3";
    }
  }
  for (size_t i = 0; i < 10u; ++i) {
    const auto str = std::to_string(i);
    if (!us.Find(str)) {
      std::cout << "fuck4";
    }
  }
  for (size_t i = 10u; i < 20u; ++i) {
    const auto str = std::to_string(i);
    if (us.Find(str)) {
      std::cout << "fuck5";
    }
  }
}