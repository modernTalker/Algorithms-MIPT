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
  explicit Graph(int size) {
    vertecies_.resize(size + 1);
  }
  void AddEdge(int u, int v, int i) {
    vertecies_[u].emplace_back(v, i + 1);
    vertecies_[v].emplace_back(u, i + 1);
  }
  int Size() const {
    return vertecies_.size();
  }
  std::vector<std::pair<int, int>> Neighbours(int u) const {
    return vertecies_[u];
  }

  std::set<int> DFS() {
    int n = vertecies_.size();
    const int inf = 2e7;
    std::set<int> bridges;
    std::vector<std::string> colour(n, "white");
    std::vector<int> time_in(n, inf);
    std::vector<int> time_up(n, inf);
    int time = 0;
    for (int v = 1; v < n; ++v) {
      if (colour[v] == "white") {
        DFSvisit(v, colour, time_in, time_up, bridges, time);
      }
    }
    return bridges;
  }

  void DFSvisit(int v, std::vector<std::string>& colour, std::vector<int>& time_in, std::vector<int>& time_up,
                std::set<int>& bridges, int time, int numb = 0) {
    colour[v] = "gray";
    time_in[v] = time_up[v] = ++time;
    for (auto u : Neighbours(v)) {
      if (u.second == numb) {
        continue;
      }
      if (colour[u.first] == "gray") {
        time_up[v] = std::min(time_up[v], time_in[u.first]);
      }
      if (colour[u.first] == "white") {
        DFSvisit(u.first, colour, time_in, time_up, bridges, time, u.second);
        time_up[v] = std::min(time_up[v], time_up[u.first]);
        if (time_in[v] < time_up[u.first]) {
          bridges.insert(u.second);
        }
      }
    }
    colour[v] = "black";
  }

 private:
  std::vector<std::vector<std::pair<int, int>>> vertecies_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph.AddEdge(u, v, i);
  }
  auto bridges = graph.DFS();
  std::cout << bridges.size() << '\n';
  for (auto p : bridges) {
    std::cout << p << '\n';
  }
  return 0;
}
