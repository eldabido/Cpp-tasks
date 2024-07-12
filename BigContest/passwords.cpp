#include <iostream>
#include <string>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::string> passwords(n);
  std::string word;
  for (int i = 0; i < n; ++i) {
    std::cin >> word;
    passwords[i] = word;
  }

  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && passwords[i].find(passwords[j]) != passwords[i].npos) {
        ++count;
      }
    }
  }
  std::cout << count << "\n";
}