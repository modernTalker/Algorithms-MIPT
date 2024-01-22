#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertecies_.resize(size + 1);
  }
  void AddEdge(size_t u, size_t v) {
    vertecies_[u].push_back(v);
    vertecies_[v].push_back(u);
  }
  void Vertex(size_t u) const {
    return PrintNeighbours(u);
  }
  void PrintNeighbours(size_t u) const {
    auto n = vertecies_[u].size();
    if (n == 0) {
      std::cout << '\n';
      return;
    }
    for (size_t i = 0; i < n - 1; ++i) {
      std::cout << vertecies_[u][i] << " ";
    }
    std::cout << vertecies_[u][n - 1] << '\n';
  }
  size_t Size() const {
    return vertecies_.size();
  }
  std::vector<size_t> Neighbours(size_t u) const {
    return vertecies_[u];
  }

  std::vector<size_t> ShortestPath(size_t vertex, size_t destination) {
    auto n = Size();
    const size_t inf = 2e7;
    std::vector<size_t> distances(n, inf);
    std::vector<size_t> parents(n, -1);
    std::vector<size_t> path;
    std::queue<size_t> queue;
    queue.push(vertex);
    distances[vertex] = 0;
    while (!queue.empty()) {
      auto v = queue.front();
      queue.pop();
      for (auto u : Neighbours(v)) {
        if (distances[u] == inf) {
          distances[u] = distances[v] + 1;
          parents[u] = v;
          queue.push(u);
        }
      }
    }
    auto parent = destination;
    auto distance = distances[destination];
    if (distance == inf) {
      return path;
    }
    path.push_back(destination);
    for (size_t i = 0; i < distance; ++i) {
      path.push_back(parents[parent]);
      parent = parents[parent];
    }
    return path;
  }

 private:
  std::vector<std::vector<size_t>> vertecies_;
};

int main() {
  size_t n, m;
  size_t a, b;
  std::cin >> n >> m;
  std::cin >> a >> b;
  Graph graph(n);
  for (size_t i = 0; i < m; ++i) {
    size_t v1, v2;
    std::cin >> v1 >> v2;
    graph.AddEdge(v1, v2);
  }
  std::vector<size_t> path(graph.ShortestPath(a, b));
  auto k = path.size();
  if (k == 0) {
    std::cout << -1 << '\n';
  } else {
    std::cout << k - 1 << '\n';
    for (size_t i = 0; i < k; ++i) {
      std::cout << path[k - i - 1] << " ";
    }
    std::cout << '\n';
  }
  return 0;
}
