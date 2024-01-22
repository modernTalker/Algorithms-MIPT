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
  bool BFS(std::vector<int>& level, int s, int t) {
    std::fill(level.begin(), level.end(), -1);
    level[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : Neighbours(u)) {
        v -= 2;
        Edge& edge = edges_[v];
        if (level[edge.v] == -1 && edge.capacity > edge.flow) {
          level[edge.v] = level[u] + 1;
          q.push(edge.v);
        }
      }
    }
    return level[t] != -1;
  }

  int DFS(int u, int t, int flow, std::vector<int>& level, std::vector<int>& pointer) {
    if (u == t || flow == 0) {
      return flow;
    }
    for (auto idx : Neighbours(u)) {
      int v = edges_[idx - 2].v;
      Edge& edge = edges_[idx - 2];
      if (level[u] + 1 == level[v] && edge.capacity > edge.flow) {
        auto min = std::min(flow, edge.capacity - edge.flow);
        int pushed = DFS(v, t, min, level, pointer);
        if (pushed > 0) {
          edge.flow += pushed;
          edges_[idx - 1].flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  size_t Dinic(int start, int t) {
    const int inf = 1e9;
    auto n = vertices_.size();
    size_t max_flow = 0;
    std::vector<int> level(n, -1);
    while (BFS(level, start, t)) {
      std::vector<int> pointer(n, 0);
      int flow = 0;
      while ((flow = DFS(start, t, inf, level, pointer)) > 0) {
        max_flow += flow;
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
  std::cout << graph.Dinic(1, n) << '\n';
  return 0;
}
