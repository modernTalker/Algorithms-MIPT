#include <iostream>
#include <vector>

class SparseTable {
 public:
  explicit SparseTable(const std::vector<std::vector<int>>& data) {
    size_t n = data.size();
    size_t m = data[0].size();
    size_t max = std::max(n, m);
    useful_.resize(max + 1);
    for (size_t i = 2; i <= max; ++i) {
      useful_[i] = useful_[i >> 1] + 1;
    }
    table_.resize(useful_[n] + 1, std::vector<std::vector<std::vector<int>>>(
                                      useful_[m] + 1, std::vector<std::vector<int>>(n, std::vector<int>(m))));
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < m; ++j) {
        table_[0][0][i][j] = data[i][j];
      }
    }
    for (size_t i = 0; i < n; ++i) {
      for (size_t p = 1; (1 << p) < static_cast<int>(m); ++p) {
        for (size_t j = 0; j < m; ++j) {
          if (j + (1 << (p - 1)) < m) {
            table_[0][p][i][j] = std::min(table_[0][p - 1][i][j], table_[0][p - 1][i][j + (1 << (p - 1))]);
          } else {
            table_[0][p][i][j] = table_[0][p - 1][i][j];
          }
        }
      }
    }
    for (size_t k = 1; (1 << k) <= static_cast<int>(n); ++k) {
      for (size_t p = 0; (1 << p) <= static_cast<int>(m); ++p) {
        for (size_t i = 0; i < n; ++i) {
          for (size_t j = 0; j < m; ++j) {
            if (i + (1 << (k - 1)) < n) {
              table_[k][p][i][j] = std::min(table_[k - 1][p][i][j], table_[k - 1][p][i + (1 << (k - 1))][j]);
            } else {
              table_[k][p][i][j] = table_[k - 1][p][i][j];
            }
          }
        }
      }
    }
  }

  int Query(size_t left, size_t up, size_t right, size_t down) {
    int x = useful_[right - left];
    int y = useful_[down - up];
    int ans1 = table_[x][y][left][up];
    int ans2 = table_[x][y][right - (1 << x) + 1][up];
    int ans3 = table_[x][y][left][down - (1 << y) + 1];
    int ans4 = table_[x][y][right - (1 << x) + 1][down - (1 << y) + 1];
    return std::min(std::min(std::min(ans1, ans2), ans3), ans4);
  }

 private:
  std::vector<std::vector<std::vector<std::vector<int>>>> table_;
  std::vector<int> useful_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> data(n, std::vector<int>(m));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      std::cin >> data[i][j];
    }
  }
  SparseTable table(data);
  size_t q = 0;
  std::cin >> q;
  for (size_t i = 0; i < q; ++i) {
    size_t left = 0;
    size_t up = 0;
    size_t right = 0;
    size_t down = 0;
    std::cin >> left >> up >> right >> down;
    std::cout << table.Query(left - 1, up - 1, right - 1, down - 1) << '\n';
  }
  return 0;
}
