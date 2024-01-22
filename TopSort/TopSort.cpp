#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

bool Contain(std::string number, const char aim) {
  auto n = number.size();
  for (size_t i = 0; i < n; ++i) {
    if (number[i] == aim) {
      return true;
    }
  }
  return false;
}

std::vector<size_t> Reversed(std::vector<size_t>& array) {
  auto n = array.size();
  std::vector<size_t> barray;
  for (size_t i = 0; i < n; ++i) {
    barray.push_back(array[n - i - 1]);
  }
  return barray;
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
  std::vector<size_t> Neighbours(size_t u) const {
    return vertecies_[u];
  }

  std::vector<size_t> TopSort() {
    auto n = vertecies_.size();
    std::vector<std::string> colour(n, "white");
    std::vector<size_t> top_sorted;
    for (size_t v = 1; v < n; ++v) {
      if (colour[v] == "white") {
        if (!TopSortDFS(v, colour, top_sorted)) {
          std::vector<size_t> nullsize;
          return nullsize;
        }
      }
    }
    return Reversed(top_sorted);
  }

  bool TopSortDFS(size_t v, std::vector<std::string>& colour, std::vector<size_t>& top_sorted) {
    colour[v] = "gray";
    for (auto u : Neighbours(v)) {
      if (colour[u] == "gray") {
        return false;
      }
      if (colour[u] == "white") {
        if (!TopSortDFS(u, colour, top_sorted)) {
          return false;
        }
      }
    }
    colour[v] = "black";
    top_sorted.push_back(v);
    return true;
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
  auto top_sorted = graph.TopSort();
  if (top_sorted.empty()) {
    std::cout << -1 << '\n';
  } else {
    for (size_t i = 0; i < top_sorted.size(); ++i) {
      std::cout << top_sorted[i] << " ";
    }
    std::cout << '\n';
  }
  return 0;
}
