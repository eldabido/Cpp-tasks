#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  size_t n = 0;
  std::cin >> n;
  std::unordered_map<std::string, std::string> synonyms;
  std::string first_syn;
  std::string second_syn;
  for (size_t i = 0; i != n; ++i) {
    std::cin >> first_syn >> second_syn;
    synonyms[first_syn] = second_syn;
    synonyms[second_syn] = first_syn;
  }
  std::cin >> n;
  for (size_t i = 0; i != n; ++i) {
    std::cin >> first_syn;
    std::cout << synonyms[first_syn] << "\n";
  }
}