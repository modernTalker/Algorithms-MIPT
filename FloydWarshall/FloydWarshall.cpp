#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

class Graph {
 public:
  Graph() = default;
  explicit Graph(size_t size) {
    size_ = size;
    vertices_.resize(size);
    for (size_t i = 0; i < size; ++i) {
      vertices_[i].resize(size);
    }
  }
  void Resize(int size) {
    vertices_.resize(size + 1);
  }
  void SpecialAdd(size_t u, size_t v, int weight) {
    vertices_[u][v] = weight;
  }
  size_t Size() const {
    return vertices_.size();
  }

  std::vector<std::vector<int>> FloydWarshall() {
    for (size_t k = 0; k < size_; ++k) {
      for (size_t x = 0; x < size_; ++x) {
        for (size_t y = 0; y < size_; ++y) {
          vertices_[x][y] = std::min(vertices_[x][y], vertices_[x][k] + vertices_[k][y]);
        }
      }
    }
    return vertices_;
  }

 private:
  std::vector<std::vector<int>> vertices_;
  size_t size_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  std::cin >> n;
  Graph graph(n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      int w = 0;
      std::cin >> w;
      graph.SpecialAdd(i, j, w);
    }
  }
  auto matrix = graph.FloydWarshall();
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix.size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }
  return 0;
}
