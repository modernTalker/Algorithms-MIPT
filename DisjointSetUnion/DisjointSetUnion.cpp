#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

class DSU {
 public:
  explicit DSU(size_t n) {
    parent_.resize(n);
    rank_.resize(n);
    size_ = n;
    for (size_t i = 0; i < n; i++) {
      parent_[i] = i;
      rank_[i] = 0;
    }
  }
  size_t SetCount() const {
    return size_;
  }
  size_t FindSet(size_t v) {
    if (parent_[v] != v) {
      parent_[v] = FindSet(parent_[v]);
    }
    return parent_[v];
  }

  void Union(size_t a, size_t b) {
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
      if (rank_[a] < rank_[b]) {
        std::swap(a, b);
      }
      parent_[b] = a;
      if (rank_[a] == rank_[b]) {
        rank_[a]++;
      }
    }
    size_--;
  }

 private:
  std::vector<size_t> parent_;
  std::vector<size_t> rank_;
  size_t size_;
};

struct Edge {
  Edge() = default;
  Edge(size_t u, size_t v) : u(u), v(v) {
  }
  size_t u;
  size_t v;
};

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertices_number_ = size;
  }
  void SpecialAdd(size_t u, size_t v) {
    Edge edge(u, v);
    edges_.emplace_back(edge);
  }

  size_t MinimumBridges(size_t n) {
    DSU dsu(n);
    size_t num_bridges = 0;
    for (auto bridge : edges_) {
      size_t island1 = bridge.u;
      size_t island2 = bridge.v;
      if (dsu.FindSet(island1) != dsu.FindSet(island2)) {
        dsu.Union(island1, island2);
      }
      num_bridges++;
      if (dsu.SetCount() == 1) {
        return num_bridges;
      }
    }
    return num_bridges;
  }

 private:
  size_t vertices_number_;
  std::vector<Edge> edges_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  for (size_t i = 0; i < m; ++i) {
    size_t v = 0;
    size_t u = 0;
    std::cin >> v >> u;
    graph.SpecialAdd(v, u);
  }
  auto ans = graph.MinimumBridges(n);
  std::cout << ans << '\n';
  return 0;
}
