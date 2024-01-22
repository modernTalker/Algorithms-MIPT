#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

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
  size_t Size() const {
    return vertecies_.size();
  }
  std::vector<size_t> Neighbours(size_t u) const {
    return vertecies_[u];
  }

  std::set<size_t> DFS() {
    auto n = vertecies_.size();
    const int64_t inf = 2e7;
    std::set<size_t> articulation_points;
    std::vector<std::string> colour(n, "white");
    std::vector<size_t> time_in(n, inf);
    std::vector<size_t> time_up(n, inf);
    size_t time = 0;
    for (size_t v = 1; v < n; ++v) {
      if (colour[v] == "white") {
        DFSvisit(v, colour, time_in, time_up, articulation_points, time, true);
      }
    }
    return articulation_points;
  }

  void DFSvisit(size_t v, std::vector<std::string>& colour, std::vector<size_t>& time_in, std::vector<size_t>& time_up,
                std::set<size_t>& articulation_points, size_t time, bool is_root) {
    colour[v] = "gray";
    time_in[v] = time_up[v] = ++time;
    auto n_children = 0;
    for (auto u : Neighbours(v)) {
      if (colour[u] == "gray") {
        time_up[v] = std::min(time_up[v], time_in[u]);
      }
      if (colour[u] == "white") {
        ++n_children;
        DFSvisit(u, colour, time_in, time_up, articulation_points, time, false);
        time_up[v] = std::min(time_up[v], time_up[u]);
        if (!is_root && time_in[v] <= time_up[u]) {
          articulation_points.insert(v);
        }
      }
    }
    if (is_root && n_children > 1) {
      articulation_points.insert(v);
    }
    colour[v] = "black";
  }

 private:
  std::vector<std::vector<size_t>> vertecies_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n, m;
  std::cin >> n >> m;
  Graph graph(n);
  for (size_t i = 0; i < m; ++i) {
    size_t u, v;
    std::cin >> u >> v;
    graph.AddEdge(u, v);
  }
  auto a_p = graph.DFS();
  std::cout << a_p.size() << '\n';
  for (auto p : a_p) {
    std::cout << p << '\n';
  }
  return 0;
}
