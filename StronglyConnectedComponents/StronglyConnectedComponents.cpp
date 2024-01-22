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

std::vector<size_t>& Reversed(std::vector<size_t>& array) {
  auto n = array.size();
  for (size_t i = 0; i < n / 2; ++i) {
    std::swap(array[i], array[n - i - 1]);
  }
  return array;
}

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    vertecies_.resize(size + 1);
    transposed_.resize(size + 1);
  }
  void AddEdge(size_t u, size_t v) {
    vertecies_[u].push_back(v);
    transposed_[v].push_back(u);
  }
  size_t Size() const {
    return vertecies_.size();
  }
  std::vector<size_t> Neighbours(size_t u) const {
    return vertecies_[u];
  }

  std::vector<size_t> TransposedNeighbours(size_t u) const {
    return transposed_[u];
  }

  std::vector<size_t> TopSort() {
    auto n = vertecies_.size();
    std::vector<std::string> colour(n, "white");
    std::vector<size_t> top_sorted;
    for (size_t v = 1; v < n; ++v) {
      if (colour[v] == "white") {
        TopSortDFS(v, colour, top_sorted);
      }
    }
    return Reversed(top_sorted);
  }

  bool TopSortDFS(size_t v, std::vector<std::string>& colour, std::vector<size_t>& top_sorted) {
    colour[v] = "gray";
    for (auto u : Neighbours(v)) {
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

  std::vector<std::vector<size_t>> SCC() {
    auto order = TopSort();
    auto components = TransposedDFS(order);
    return components;
  }

  std::vector<std::vector<size_t>> DFS(std::vector<size_t> order) {
    auto n = vertecies_.size();
    std::vector<std::string> colour(n, "white");
    std::vector<std::vector<size_t>> components;
    for (auto v : order) {
      if (colour[v] == "white") {
        components.emplace_back();
        DFSvisit(v, components[components.size() - 1], colour);
      }
    }
    return components;
  }

  void DFSvisit(size_t v, std::vector<size_t>& component, std::vector<std::string>& colour) {
    component.push_back(v);
    colour[v] = "gray";
    for (auto u : Neighbours(v)) {
      if (colour[u] == "white") {
        DFSvisit(u, component, colour);
      }
    }
  }

  std::vector<std::vector<size_t>> TransposedDFS(std::vector<size_t> order) {
    auto n = vertecies_.size();
    std::vector<std::string> colour(n, "white");
    std::vector<std::vector<size_t>> components;
    size_t comp_counter;
    for (auto v : order) {
      if (colour[v] == "white") {
        components.emplace_back();
        ++comp_counter;
        TransposedDFSvisit(v, components[components.size() - 1], colour);
      }
    }
    return components;
  }

  void TransposedDFSvisit(size_t v, std::vector<size_t>& component, std::vector<std::string>& colour) {
    component.push_back(v);
    colour[v] = "gray";
    for (auto u : TransposedNeighbours(v)) {
      if (colour[u] == "white") {
        TransposedDFSvisit(u, component, colour);
      }
    }
  }

 private:
  std::vector<std::vector<size_t>> vertecies_;
  std::vector<std::vector<size_t>> transposed_;
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
  auto components = graph.SCC();
  std::vector<size_t> distribution(n + 1);
  std::cout << components.size() << '\n';
  for (size_t i = 0; i < components.size(); ++i) {
    for (size_t j = 0; j < components[i].size(); ++j) {
      distribution[components[i][j]] = i + 1;
    }
  }
  for (size_t i = 1; i < distribution.size(); ++i) {
    std::cout << distribution[i] << " ";
  }
  std::cout << '\n';
  return 0;
}
