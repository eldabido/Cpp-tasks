#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  std::unordered_map<std::string, int> bank;
  int num_of_op = 0;
  std::string name;
  int money = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> num_of_op;
    std::cin >> name;
    if (num_of_op == 1) {
      std::cin >> money;
      bank[name] += money;
    } else {
      if (bank.find(name) != bank.end()) {
        std::cout << bank[name] << "\n";
      } else {
        std::cout << "ERROR\n";
      }
    }
  }
  return 0;
}