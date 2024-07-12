#include <iostream>
#include <vector>

void AddEgde(int u, int v, std::vector<std::vector<int>>& graph) {
  graph[u - 1].push_back(v);
}

void Vertex(int u, std::vector<std::vector<int>>& graph) {
  for (auto elem : graph[u - 1]) {
    std::cout << elem << ' ';
  }
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n;
  std::cin >> k;
  std::vector<std::vector<int>> graph(n);
  int num_of_op = 0;
  int u = 0;
  int v = 0;
  for (int i = 0; i < k; ++i) {
    std::cin >> num_of_op;
    std::cin >> u;
    if (num_of_op == 1) {
      std::cin >> v;
      AddEgde(u, v, graph);
      AddEgde(v, u, graph);
    } else {
      Vertex(u, graph);
    }
  }
  return 0;
}
