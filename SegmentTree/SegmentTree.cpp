#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  Node() : max(-2e7), promise(0) {
  }
  Node(int maxim, int count) : max(maxim), promise(count) {
  }
  int max;
  int promise;
};

size_t Log(size_t n) {
  size_t result = 0;
  while (n >>= 1) {
    ++result;
  }
  return result;
}

class SegmentTree {
 public:
  explicit SegmentTree(const std::vector<int>& data) : neutral_(-2e7), size_(data.size()) {
    size_t power = Log(data.size()) + 1;
    size_ = 1 << power;
    tree_.resize(2 * size_ - 1, Node(neutral_, 0));  // if data.size() == 2**x
    for (size_t i = size_ - 1; i < 2 * size_ - 1; ++i) {
      if (i - size_ + 1 < data.size()) {
        tree_[i] = Node(data[i - size_ + 1], 0);
      }
    }
    for (int i = static_cast<int>(size_) - 2; i >= 0; --i) {
      UpdateAtPoint(i);
    }
  }
  void Update(size_t left, size_t right, size_t node, size_t a, size_t b, int delta) {
    if (a >= left && b <= right) {
      tree_[node].promise += delta;
      return;
    }
    if (a > right || b < left) {
      return;
    }
    Push(node);
    size_t mid = (a + b) / 2;
    Update(left, right, Left(node), a, mid, delta);
    Update(left, right, Right(node), mid + 1, b, delta);
    tree_[node].max = std::max(Query(a, mid, Left(node), a, mid), Query(mid + 1, b, Right(node), mid + 1, b));
  }
  int Query(size_t left, size_t right, size_t node, size_t a, size_t b) {
    if (a >= left && b <= right) {
      return tree_[node].max + tree_[node].promise;
    }
    if (a > right || b < left) {
      return neutral_;
    }
    Push(node);
    size_t mid = (a + b) / 2;
    auto left_res = Query(left, right, Left(node), a, mid);
    auto right_res = Query(left, right, Right(node), mid + 1, b);
    return QueryOperation(left_res, right_res);
  }
  int Q(size_t left_border, size_t right_border) {
    return Query(left_border, right_border, 0, 0, size_ - 1);
  }
  void U(size_t left, size_t right, int delta) {
    return Update(left, right, 0, 0, size_ - 1, delta);
  }

 private:
  size_t Parent(size_t i) {
    return ((i - 1) / 2);
  }
  size_t Left(size_t i) {
    return 2 * i + 1;
  }
  size_t Right(size_t i) {
    return 2 * i + 2;
  }
  size_t IsLeftSon(size_t i) {
    return i % 2 == 1;
  }
  size_t IsRightSon(size_t i) {
    return i % 2 == 0;
  }
  int QueryOperation(int x, int y) {
    return std::max(x, y);
  }
  void UpdateAtPoint(size_t i) {
    tree_[i] = Node(std::max(tree_[Left(i)].max, tree_[Right(i)].max), 0);
  }

  void Push(size_t node) {
    tree_[node].max += tree_[node].promise;
    tree_[Left(node)].promise += tree_[node].promise;
    tree_[Right(node)].promise += tree_[node].promise;
    tree_[node].promise = 0;
  }

 private:
  int neutral_;
  size_t size_;
  std::vector<Node> tree_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  std::cin >> n;
  std::vector<int> data(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> data[i];
  }
  SegmentTree tree(data);
  size_t k = 0;
  std::cin >> k;
  for (size_t i = 0; i < k; ++i) {
    char request = 0;
    std::cin >> request;
    if (request == 'm') {
      size_t left = 0;
      size_t right = 0;
      std::cin >> left >> right;
      auto ans = tree.Q(left - 1, right - 1);
      std::cout << ans << '\n';
    } else {
      size_t left = 0;
      size_t right = 0;
      int delta = 0;
      std::cin >> left >> right >> delta;
      tree.U(left - 1, right - 1, delta);
    }
  }
  return 0;
}
