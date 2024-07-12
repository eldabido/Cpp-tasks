#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::map<std::string, int> words;
  std::string word;
  while (std::cin >> word) {
    words[word] += 1;
  }
  std::map<size_t, std::vector<std::string>> count_of_words;
  for (auto w : words) {
    count_of_words[w.second].push_back(w.first);
  }
  for (auto v = count_of_words.rbegin(); v != count_of_words.rend(); ++v) {
    for (auto w : v->second) {
      std::cout << w << "\n";
    }
  }
}