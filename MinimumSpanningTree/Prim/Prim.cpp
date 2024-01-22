#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <set>

struct Comparator {
  bool operator()(const std::pair<size_t, size_t>& a, const std::pair<size_t, size_t>& b) const {
    return a.second > b.second;
  }
};

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertices_.resize(size + 1);
  }
  void Resize(size_t size) {
    vertices_.resize(size + 1);
  }
  void SpecialAdd(size_t u, size_t v, size_t weight) {
    vertices_[u].emplace_back(std::make_pair(v, weight));
    vertices_[v].emplace_back(std::make_pair(u, weight));
  }
  size_t Size() const {
    return vertices_.size();
  }
  std::vector<std::pair<size_t, size_t>>& Neighbours(size_t u) {
    return vertices_[u];
  }
  size_t Prim() {
    size_t weight = 0;
    const size_t inf = 2e8;
    size_t n = vertices_.size();
    std::vector<size_t> dist(n, inf);
    dist[1] = 0;
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<size_t, size_t>, std::vector<std::pair<size_t, size_t>>, Comparator> heap;
    heap.emplace(1, 0);
    while (!heap.empty()) {
      size_t v = heap.top().first;
      heap.pop();
      if (visited[v]) {
        continue;
      }
      visited[v] = true;
      weight += dist[v];
      for (auto neighbour : Neighbours(v)) {
        size_t u = neighbour.first;
        size_t w = neighbour.second;
        if ((!visited[u]) && (w < dist[u])) {
          dist[u] = w;
          heap.emplace(u, w);
        }
      }
    }
    return weight;
  }

 private:
  std::vector<std::vector<std::pair<size_t, size_t>>> vertices_;
};

int main() {
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  for (size_t i = 0; i < m; ++i) {
    size_t v = 0;
    size_t u = 0;
    size_t w = 0;
    std::cin >> v >> u >> w;
    graph.SpecialAdd(v, u, w);
  }
  auto ans = graph.Prim();
  std::cout << ans << '\n';
  return 0;
}
