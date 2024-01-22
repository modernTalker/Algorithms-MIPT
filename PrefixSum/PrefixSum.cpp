#include <iostream>
#include <vector>

class PrefixTable {
 public:
  explicit PrefixTable(const std::vector<int64_t>& data) {
    auto n = data.size();
    table_.resize(n);
    table_[0] = data[0];
    for (size_t i = 1; i < n; ++i) {
      table_[i] = table_[i - 1] + data[i];
    }
  }

  int64_t Query(size_t left, size_t right) {
    if (left == 0) {
      return table_[right];
    }
    return table_[right] - table_[left - 1];
  }

 private:
  std::vector<int64_t> table_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  std::cin >> n;
  std::vector<int64_t> array(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> array[i];
  }
  PrefixTable table(array);
  size_t k = 0;
  std::cin >> k;
  for (size_t i = 0; i < k; ++i) {
    size_t left = 0;
    size_t right = 0;
    std::cin >> left >> right;
    std::cout << table.Query(left - 1, right - 1) << " ";
  }
  std::cout << '\n';
  return 0;
}
