#include <iostream>

int main() {
  int counter = 0;
  int open_brackets = 0;
  char c;
  while (std::cin.get(c) && c != '\n') {
    if (c == '(') {
      ++open_brackets;
    } else if (c == ')') {
      if (open_brackets > 0) {
        --open_brackets;
      } else {
        ++counter;
      }
    }
  }
  counter += open_brackets;
  std::cout << counter;
}