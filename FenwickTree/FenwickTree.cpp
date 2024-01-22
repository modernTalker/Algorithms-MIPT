#include <iostream>
#include <vector>

class FenwickTree {
 public:
  explicit FenwickTree(const std::vector<int64_t>& array) {
    size_t n = array.size();
    std::vector<int64_t> prefix(n);
    prefix[0] = array[0];
    for (size_t i = 1; i < n; ++i) {
      prefix[i] = prefix[i - 1] + array[i];
    }
    fenwick_.resize(n);
    std::fill(fenwick_.begin(), fenwick_.end(), 0);
    for (size_t i = 0; i < n; ++i) {
      if ((i & (i + 1)) > 1) {
        fenwick_[i] = prefix[i] - prefix[(i & (i + 1)) - 1];
      } else {
        fenwick_[i] = prefix[i];
      }
    }
  }

  void Update(size_t k, int64_t delta) {
    size_t n = fenwick_.size();
    for (size_t i = k; i < n; i = (i | (i + 1))) {
      fenwick_[i] += delta;
    }
  }
  int64_t Query(size_t r) {
    int64_t sum = 0;
    for (auto i = static_cast<int64_t>(r); i >= 0; i = (i & (i + 1)) - 1) {
      sum += fenwick_[i];
    }
    return sum;
  }

  int64_t Q(size_t l, size_t r) {
    if (l < 1) {
      return Query(r);
    }
    return Query(r) - Query(l - 1);
  }

 private:
  std::vector<int64_t> fenwick_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  std::cin >> n;
  std::vector<int64_t> data(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> data[i];
  }
  FenwickTree tree(data);
  size_t m = 0;
  std::cin >> m;
  for (size_t i = 0; i < m; ++i) {
    char request = 0;
    std::cin >> request;
    if (request == 's') {
      size_t left = 0;
      size_t right = 0;
      std::cin >> left >> right;
      std::cout << tree.Q(left - 1, right - 1) << " ";
    } else {
      size_t index = 0;
      int64_t value = 0;
      std::cin >> index >> value;
      int64_t difference = value - data[index - 1];
      data[index - 1] = value;
      tree.Update(index - 1, difference);
    }
  }
  std::cout << '\n';
  return 0;
}
