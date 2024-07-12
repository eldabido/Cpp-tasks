#include <iostream>
#include <stack>

int main() {
  std::stack<int> stck1;
  char c;
  int flag = 1;
  while (std::cin.get(c) && c != '\n') {
    if (c == '(') {
      stck1.push(1);
    } else if (c == '{') {
      stck1.push(2);
    } else if (c == '[') {
      stck1.push(3);
    } else if (c == '<') {
      stck1.push(4);
    } else if (c == ')') {
      if (!stck1.empty() && stck1.top() == 1) {
        stck1.pop();
      } else {
        flag = 0;
        while (!stck1.empty()) {
        stck1.pop();
        }
        break;
      }
    } else if (c == '}') {
      if (!stck1.empty() && stck1.top() == 2) {
        stck1.pop();
      } else {
        flag = 0;
        break;
      }
    } else if (c == ']') {
      if (!stck1.empty() && stck1.top() == 3) {
        stck1.pop();
      } else {
        flag = 0;
        while (!stck1.empty()) {
        stck1.pop();
        }
        break;
      }
    } else if (c == '>') {
      if (!stck1.empty() && stck1.top() == 4) {
        stck1.pop();
      } else {
        flag = 0;
        while (!stck1.empty()) {
        stck1.pop();
        }
        break;
      }
    }
  }
  if (!stck1.empty()) {
    flag = 0;
  }
  if (flag) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }
}