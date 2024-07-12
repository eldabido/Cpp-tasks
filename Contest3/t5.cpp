#include <iostream>
#include <string>
#include <vector>

class Stack {
 private:
  std::vector<int> stack_;

 public:
  void Push(int elem) {
    stack_.push_back(elem);
  }

  void Pop() {
    std::cout << stack_.back() << "\n";
    stack_.pop_back();
  }

  int Back() {
    return stack_.back();
  }

  int Size() {
    return stack_.size();
  }

  void Clear() {
    stack_.clear();
  }

  void Exit() {
    std::cout << "bye\n";
  }
};

int main() {
  int n;
  std::cin >> n;
  std::string command;
  Stack stack = Stack();
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "push") {
      int num;
      std::cin >> num;
      stack.Push(num);
      std::cout << "ok\n";
    } else if (command == "pop") {
      stack.Pop();
    } else if (command == "back") {
      std::cout << stack.Back() << "\n";
    } else if (command == "size") {
      std::cout << stack.Size() << "\n";
    } else if (command == "clear") {
      stack.Clear();
      std::cout << "ok\n";
    } else if (command == "exit") {
      stack.Exit();
      break;
    }
  }
  return 0;
}