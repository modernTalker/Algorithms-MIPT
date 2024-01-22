#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <algorithm>

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

  void BFS(std::vector<int>& parent, std::vector<int>& min_capacity, std::queue<int>& q, int s, int t) {
    q.push(s);
    parent[s] = -2;
    min_capacity[s] = 1e9;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : Neighbours(u)) {
        v -= 2;
        Edge& edge = edges_[v];
        if (parent[edge.v] == -1 && edge.capacity > edge.flow) {
          parent[edge.v] = v;
          min_capacity[edge.v] = std::min(min_capacity[u], edge.capacity - edge.flow);
          if (edge.v == t) {
            break;
          }
          q.push(edge.v);
        }
      }
    }
  }

  size_t EdmundsKarp(int start, int t) {
    auto n = vertices_.size();
    size_t max = 0;
    while (true) {
      std::vector<int> parent(n, -1);
      std::vector<int> min_capacity(n, 1e9);
      std::queue<int> q;
      BFS(parent, min_capacity, q, start, t);
      if (parent[t] == -1) {
        break;
      }
      max += min_capacity[t];
      int u = t;
      while (u != start) {
        int v = parent[u];
        edges_[v].flow += min_capacity[t];
        edges_[v ^ 1].flow -= min_capacity[t];
        u = edges_[v].u;
      }
    }
    return max;
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
  std::cout << graph.EdmundsKarp(1, n) << '\n';
  return 0;
}
