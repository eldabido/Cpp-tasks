#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::unordered_map<std::string, int> words;
  std::string word;
  while (std::cin >> word) {
    words[word] += 1;
    std::cout << words[word] - 1 << " ";
  }
}