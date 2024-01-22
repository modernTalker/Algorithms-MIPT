#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

struct Comparator {
  bool operator()(const std::pair<size_t, std::pair<size_t, size_t>>& a,
                  const std::pair<size_t, std::pair<size_t, size_t>>& b) {
    return a.first > b.first;
  }
};

class DSU {
 public:
  explicit DSU(size_t n) {
    parent_.resize(n);
    rank_.resize(n);
    for (size_t i = 0; i < n; i++) {
      parent_[i] = i;
      rank_[i] = 0;
    }
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
  }

 private:
  std::vector<size_t> parent_;
  std::vector<size_t> rank_;
};

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertices_.resize(size + 1);
  }
  void Resize(size_t size) {
    vertices_.resize(size);
  }
  void SpecialAdd(size_t u, size_t v, size_t weight) {
    edges_.emplace(weight, std::make_pair(u, v));
    edges_.emplace(weight, std::make_pair(v, u));
  }
  size_t Size() const {
    return vertices_.size();
  }
  std::vector<std::pair<size_t, size_t>>& Neighbours(size_t u) {
    return vertices_[u];
  }
  size_t Kruskal() {
    auto dsu = DSU(vertices_.size());
    size_t min_weight = 0;
    while (!edges_.empty()) {
      auto edge = edges_.top();
      edges_.pop();
      size_t weight = edge.first;
      size_t u = edge.second.first;
      size_t v = edge.second.second;
      if (dsu.FindSet(u) != dsu.FindSet(v)) {
        dsu.Union(v, u);
        min_weight += weight;
      }
    }
    return min_weight;
  }

 private:
  std::vector<std::vector<std::pair<size_t, size_t>>> vertices_;
  std::priority_queue<std::pair<size_t, std::pair<size_t, size_t>>,
                      std::vector<std::pair<size_t, std::pair<size_t, size_t>>>, Comparator>
      edges_;
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
    size_t w = 0;
    std::cin >> v >> u >> w;
    graph.SpecialAdd(v, u, w);
  }
  auto ans = graph.Kruskal();
  std::cout << ans << '\n';
  return 0;
}
