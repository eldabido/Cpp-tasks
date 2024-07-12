#include <iostream>
#include <queue>

int main() {
  int n = 0;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> numbers;
  int num = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    numbers.push(num);
  }
  double coins = 0;
  // Получается, суммируем верхние два числа, убираем их из очереди.
  // Потом добавляем сумму в очередь, и она автоматически сортируется с остальными элементами.
  // Так мы достигаем того, что алгоритм суммирует наименьшие числа => платим меньше.
  while (numbers.size() > 1) {
    int first = numbers.top();
    numbers.pop();
    int second = numbers.top();
    numbers.pop();
    int sum = first + second;
    coins += 0.05 * sum;
    numbers.push(sum);
  }
  std::cout << coins;
}