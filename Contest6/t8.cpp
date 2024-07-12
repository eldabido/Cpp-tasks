#include <cstdint>
#include <iostream>
#include <string>
#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::map<std::string, std::map<std::string, int64_t>> buyers;
  std::string surname;
  std::string goods;
  int64_t amount = 0;
  while (std::cin >> surname >> goods >> amount) {
    buyers[surname][goods] += amount;
  }

  for (auto people : buyers) {
    std::cout << people.first << ":\n";
    for (auto products : people.second) {
      std::cout << products.first << " " << products.second << "\n";
    }
  }
}