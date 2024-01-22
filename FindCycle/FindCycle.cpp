#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <algorithm>

bool Contain(std::string number, const char aim) {
  auto n = number.size();
  for (size_t i = 0; i < n; ++i) {
    if (number[i] == aim) {
      return true;
    }
  }
  return false;
}

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertecies_.resize(size + 1);
  }
  void AddEdge(size_t u, size_t v) {
    vertecies_[u].push_back(v);
  }
  size_t Size() const {
    return vertecies_.size();
  }
  std::vector<size_t>& Neighbours(size_t u) {
    return vertecies_[u];
  }

  std::vector<size_t> HasCycle() {
    size_t n = vertecies_.size();
    std::vector<std::string> colour(n, "white");
    std::vector<size_t> cycle;
    for (size_t v = 1; v < n; ++v) {
      if (colour[v] == "white") {
        if (HasCycleDFS(v, colour, cycle)) {
          std::vector<size_t> recycle;
          size_t i = cycle.size() - 2;
          recycle.push_back(cycle[cycle.size() - 1]);
          while (cycle[cycle.size() - 1] != cycle[i]) {
            recycle.push_back(cycle[i]);
            --i;
          }
          std::reverse(recycle.begin() + 1, recycle.end());
          return recycle;
        }
      }
    }
    std::vector<size_t> nullsize;
    return nullsize;
  }

  bool HasCycleDFS(size_t v, std::vector<std::string>& colour, std::vector<size_t>& cycle) {
    colour[v] = "gray";
    cycle.push_back(v);
    for (auto u : Neighbours(v)) {
      if (colour[u] == "gray") {
        // cycle.push_back(v);
        cycle.push_back(u);
        return true;
      }
      if (colour[u] == "white") {
        if (HasCycleDFS(u, colour, cycle)) {
          // cycle.push_back(u);
          return true;
        }
      }
    }
    colour[v] = "black";
    cycle.pop_back();
    return false;
  }

 private:
  std::vector<std::vector<size_t>> vertecies_;
};

int main() {
  size_t n, m;
  std::cin >> n >> m;
  Graph graph(n);
  for (size_t i = 0; i < m; ++i) {
    size_t u, v;
    std::cin >> u >> v;
    graph.AddEdge(u, v);
  }
  auto cycle = graph.HasCycle();
  if (cycle.empty()) {
    std::cout << "NO" << '\n';
  } else {
    std::cout << "YES" << '\n';
    for (size_t i = 0; i < cycle.size(); ++i) {
      std::cout << cycle[i] << " ";
    }
    std::cout << '\n';
  }
  return 0;
}
