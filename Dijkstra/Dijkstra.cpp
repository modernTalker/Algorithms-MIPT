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
  void Resize(size_t size) {
    vertecies_.resize(size);
  }
  void SpecialAdd(size_t u, size_t v, int weight) {
    vertecies_[u].emplace_back(std::make_pair(v, weight));
    // vertecies_[v].emplace_back(std::make_pair(u, weight));
  }
  size_t Size() const {
    return vertecies_.size();
  }
  std::vector<std::pair<size_t, size_t>>& Neighbours(size_t u) {
    return vertecies_[u];
  }

  size_t Dijkstra(size_t start, size_t finish) {
    auto n = Size();
    const size_t inf = 2009000999;
    std::vector<size_t> dist(n, inf);
    dist[start] = 0;
    auto cmp = [](const std::pair<size_t, size_t>& a, const std::pair<size_t, size_t>& b) { return a.first > b.first; };
    std::priority_queue<std::pair<size_t, size_t>, std::vector<std::pair<size_t, size_t>>, decltype(cmp)> heap(cmp);
    heap.emplace(0, start);
    while (!heap.empty()) {
      size_t u = heap.top().second;
      size_t distance = heap.top().first;
      heap.pop();
      if ((distance == inf) || (u == finish)) {
        break;
      }
      for (auto neighbour : Neighbours(u)) {
        size_t v = neighbour.first;
        size_t weight = neighbour.second;
        if (dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
          heap.emplace(dist[v], v);
        }
      }
    }
    return dist[finish];
  }

 private:
  std::vector<std::vector<std::pair<size_t, size_t>>> vertecies_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  size_t start = 0;
  size_t finish = 0;
  const size_t inf = 2009000999;
  std::cin >> n >> start >> finish;
  Graph graph(n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      int w = 0;
      std::cin >> w;
      if ((w != -1) && (w != 0)) {
        graph.SpecialAdd(i + 1, j + 1, w);
      }
    }
  }
  auto ans = graph.Dijkstra(start, finish);
  if (ans == inf) {
    std::cout << -1 << '\n';
  } else {
    std::cout << ans << '\n';
  }
  return 0;
}
