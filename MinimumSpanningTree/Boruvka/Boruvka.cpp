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
  Edge(size_t w, size_t u, size_t v) : weight(w), u(u), v(v), visited(false) {
  }
  size_t weight;
  size_t u;
  size_t v;
  bool visited;
};

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertices_number_ = size + 1;
  }
  void SpecialAdd(size_t u, size_t v, size_t weight) {
    Edge edge(weight, u, v);
    edges_.emplace_back(edge);
  }
  size_t Boruvka() {
    auto n = vertices_number_;
    const size_t inf = 2e9;
    auto dsu = DSU(n);
    size_t min_weight = 0;
    while (dsu.SetCount() > 2) {
      std::vector<Edge> min_edge(n, {inf, inf, inf});
      for (auto edge : edges_) {
        auto w = edge.weight;
        auto v = edge.v;
        auto u = edge.u;
        auto component_v = dsu.FindSet(v);
        auto component_u = dsu.FindSet(u);
        if (component_v != component_u) {
          if (w < min_edge[component_v].weight) {
            min_edge[component_v].v = v;
            min_edge[component_v].u = u;
            min_edge[component_v].weight = w;
          }
          if (w < min_edge[component_u].weight) {
            min_edge[component_u].v = v;
            min_edge[component_u].u = u;
            min_edge[component_u].weight = w;
          }
        }
      }
      for (auto edge : min_edge) {
        if (edge.weight == inf) {
          continue;
        }
        if (edge.visited) {
          continue;
        }
        edge.visited = true;
        auto component_u = dsu.FindSet(edge.u);
        auto component_v = dsu.FindSet(edge.v);
        if (component_u != component_v) {
          min_weight += edge.weight;
          dsu.Union(component_v, component_u);
        }
      }
    }
    return min_weight;
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
    size_t w = 0;
    std::cin >> v >> u >> w;
    graph.SpecialAdd(v, u, w);
  }
  auto ans = graph.Boruvka();
  std::cout << ans << '\n';
  return 0;
}
