#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

struct Edge {
  Edge() = default;
  Edge(int first, int second, int w) : u(first), v(second), capacity(w), flow(0) {
  }
  int u;
  int v;
  int capacity;
  int flow;
};

class Graph {
 public:
  Graph() = default;
  explicit Graph(int size) {
    vertices_.resize(size + 1);
  }
  void Resize(int size) {
    vertices_.resize(size + 1);
  }
  void SpecialAdd(int u, int v, int capacity) {
    edges_.emplace_back(u, v, capacity);
    edges_.emplace_back(v, u, 0);
    auto cur_size = static_cast<int>(edges_.size());
    vertices_[u].push_back(cur_size);
    vertices_[v].push_back(cur_size + 1);
  }
  size_t Size() const {
    return vertices_.size();
  }
  std::vector<int>& Neighbours(int u) {
    return vertices_[u];
  }

  bool DFSVisit(std::vector<bool>& visited, int u, int t, int min_cap) {
    if (u == t) {
      return true;
    }
    visited[u] = true;
    for (auto idx : Neighbours(u)) {
      idx -= 2;
      Edge& edge = edges_[idx];
      auto v = edge.v;
      if (!visited[v] && edge.capacity - edge.flow >= min_cap && DFSVisit(visited, v, t, min_cap)) {
        edge.flow += min_cap;
        edges_[idx ^ 1].flow -= min_cap;
        return true;
      }
    }
    return false;
  }

  bool DFS(int u, int t, int min_cap) {
    std::vector<bool> visited(vertices_.size(), false);
    return DFSVisit(visited, u, t, min_cap);
  }

  size_t FordFulkerson(int start, int t) {
    size_t max_flow = 0;
    for (int curr_flow = 1e9; curr_flow >= 1; curr_flow /= 2) {
      while (DFS(start, t, curr_flow)) {
        max_flow += curr_flow;
      }
    }
    return max_flow;
  }

 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Edge> edges_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  for (size_t i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    int capacity = 0;
    std::cin >> u >> v >> capacity;
    graph.SpecialAdd(u, v, capacity);
  }
  std::cout << graph.FordFulkerson(1, n) << '\n';
  return 0;
}
