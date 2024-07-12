#include <iostream>
#include <queue>

int main() {
  int n = 0;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> population;
  int num = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    population.push(num);
  }
  int passports = 0;
  // Получается, суммируем верхние два числа, убираем их из очереди.
  // Потом добавляем сумму в очередь, и она автоматически сортируется с остальными элементами.
  // Так мы достигаем того, что алгоритм суммирует наименьшие числа => делаем меньше.
  while (population.size() > 1) {
    int first = population.top();
    population.pop();
    int second = population.top();
    population.pop();
    int sum = first + second;
    passports += sum;
    population.push(sum);
  }
  std::cout << passports;
}