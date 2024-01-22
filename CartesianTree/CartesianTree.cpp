#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <random>

struct Node {
  Node(int64_t x, int64_t y) : value(x), priority(y) {
    result = x;
    promise = 0;
    size = 1;
  }
  Node(int64_t x, int64_t y, int64_t res, int64_t prom, size_t s, Node* par, Node* left, Node* right) {
    value = x;
    priority = y;
    result = res;
    promise = prom;
    size = s;
    parent = par;
    left_son = left;
    right_son = right;
  }
  ~Node() {
    delete left_son;
    delete right_son;
  }
  int64_t value;
  int64_t priority;
  int64_t result;
  int64_t promise;
  size_t size;
  Node* parent = nullptr;
  Node* left_son = nullptr;
  Node* right_son = nullptr;
};

class CartesianTree {
 public:
  CartesianTree() {
    root_ = nullptr;
  }
  explicit CartesianTree(const std::vector<std::pair<int, int>>& data) {
    if (data.empty()) {
      root_ = nullptr;
    }
    root_ = new Node(data[0].first, data[0].second);
    std::stack<Node*> stack;
    stack.push(root_);
    for (size_t i = 1; i < data.size(); ++i) {
      Node* node = new Node(data[i].first, data[i].second);
      if (node->priority > stack.top()->priority) {
        stack.top()->right_son = node;
        node->parent = stack.top();
      } else {
        while (!stack.empty() && node->priority <= stack.top()->priority) {
          stack.pop();
        }
        if (stack.empty()) {
          node->left_son = root_;
          root_->parent = node;
          root_ = node;
        } else {
          node->left_son = stack.top()->right_son;
          stack.top()->right_son->parent = node;
          stack.top()->right_son = node;
          node->parent = stack.top();
        }
      }
      stack.push(node);
    }
    while (!stack.empty()) {
      stack.pop();
    }
  }
  void Insert(size_t position, int64_t x, int64_t y) {
    Insert(root_, position, x, y);
  }
  void Erase(int64_t x) {
    if (Exists(root_, x)) {
      Erase(root_, x);
    }
  }
  bool Exists(int64_t x) {
    return Exists(root_, x);
  }
  int64_t Next(int64_t x) {
    auto node = Next(root_, x);
    if (node == nullptr) {
      return -2e9;
    }
    return node->value;
  }
  int64_t Previous(int64_t x) {
    auto node = Previous(root_, x);
    if (node == nullptr) {
      return -2e9;
    }
    return node->value;
  }
  int64_t Get(int64_t k) {
    auto node = Get(root_, k);
    if (node == nullptr) {
      return -2e9;
    }
    return node->value;
  }
  int64_t SubarrayMin(size_t left, size_t right) {
    return Rmq(root_, left, right);
  }
  void Permutation(size_t left, size_t right) {
    Permutation(root_, left, right);
  }
  void PrintTree() {
    PrintTree(root_);
  }
  ~CartesianTree() {
    delete root_;
  }

 private:
  void Insert(Node*& root, size_t position, int64_t x, int64_t y) {
    auto [tree1, tree2] = Split(root, position);
    root = Merge(Merge(tree1, new Node(x, y)), tree2);
  }
  void Erase(Node*& root, int64_t x) {
    auto [tree1, tree2] = Split(root, x);
    auto [treex1, treex2] = Split(tree2, x + 1);
    delete treex1;
    root = Merge(tree1, treex2);
  }
  std::pair<Node*, Node*> Split(Node* root, size_t k) {
    Node* tree1 = nullptr;
    Node* tree2 = nullptr;
    if (root == nullptr) {
      return {tree1, tree2};
    }
    if (Size(root->left_son) < k) {
      auto [left_tree, right_tree] = Split(root->right_son, k - Size(root->left_son) - 1);
      tree1 = root;
      tree1->right_son = left_tree;
      if (left_tree != nullptr) {
        left_tree->parent = tree1;
      }
      tree2 = right_tree;
    } else {
      auto [left_tree, right_tree] = Split(root->left_son, k);
      tree2 = root;
      tree2->left_son = right_tree;
      if (right_tree != nullptr) {
        right_tree->parent = tree2;
      }
      tree1 = left_tree;
    }
    FixNode(tree1);
    FixNode(tree2);
    return {tree1, tree2};
  }
  Node* Merge(Node* tree1, Node* tree2) {
    if (tree1 == nullptr) {
      return tree2;
    }
    if (tree2 == nullptr) {
      return tree1;
    }
    if (tree1->priority < tree2->priority) {
      tree1->right_son = Merge(tree1->right_son, tree2);
      tree1->right_son->parent = tree1;
      FixNode(tree1);
      return tree1;
    }
    tree2->left_son = Merge(tree1, tree2->left_son);
    tree2->left_son->parent = tree2;
    FixNode(tree2);
    return tree2;
  }
  Node* Get(Node* root, size_t k) {
    if (Size(root) <= k) {
      return nullptr;
    }
    while (true) {
      if (Size(root->left_son) < k) {
        k -= Size(root->left_son) + 1;
        root = root->right_son;
      } else if (Size(root->left_son) > k) {
        root = root->left_son;
      } else {
        return root;
      }
    }
    return nullptr;
  }
  bool Exists(Node*& root, int64_t x) {
    if (root == nullptr) {
      return false;
    }
    if (root->value == x) {
      return true;
    }
    if (root->value < x) {
      return Exists(root->right_son, x);
    }
    return Exists(root->left_son, x);
  }
  Node* Next(Node* root, int64_t x) {
    if (root == nullptr) {
      return nullptr;
    }
    auto [tree1, tree2] = Split(root, x + 1);
    if (tree2 == nullptr) {
      return nullptr;
    }
    Node* current = tree2;
    while (current->left_son != nullptr) {
      current = current->left_son;
    }
    Merge(tree1, tree2);
    return current;
  }
  Node* Previous(Node* root, int64_t x) {
    if (root == nullptr) {
      return nullptr;
    }
    auto [tree1, tree2] = Split(root, x);
    if (tree1 == nullptr) {
      return nullptr;
    }
    Node* current = tree1;
    while (current->right_son != nullptr) {
      current = current->right_son;
    }
    Merge(tree1, tree2);
    return current;
  }
  void FixNode(Node* root) {
    if (root != nullptr) {
      root->result = Operation(Operation(Result(root->left_son), root->value), Result(root->right_son));
      root->size = 1;
      if (root->left_son != nullptr) {
        root->size += root->left_son->size;
      }
      if (root->right_son != nullptr) {
        root->size += root->right_son->size;
      }
    }
  }
  size_t Size(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->size;
  }

  int64_t Result(Node* root) {
    if (root == nullptr) {
      return 2e9;
    }
    return root->result;
  }
  int64_t Rmq(Node* root, size_t left, size_t right) {
    auto [tree1, tree2] = Split(root, left);
    auto [treex1, treex2] = Split(tree2, right - left);
    auto result = Result(treex1);
    root = Merge(Merge(tree1, treex1), treex2);
    return result;
  }
  int64_t Operation(int64_t a, int64_t b) {
    return std::min(a, b);
  }

  void Permutation(Node*& root, size_t left, size_t right) {
    auto [tree1, tree2] = Split(root, left);
    auto [treex1, treex2] = Split(tree2, right - left);
    root = Merge(treex1, Merge(tree1, treex2));
  }
  void PrintTree(Node* root) {
    if (root == nullptr) {
      return;
    }
    if (root->left_son != nullptr) {
      PrintTree(root->left_son);
    }
    std::cout << root->value << " ";
    if (root->right_son != nullptr) {
      PrintTree(root->right_son);
    }
  }

 private:
  Node* root_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  std::cin >> n;
  CartesianTree tree;
  for (size_t i = 0; i < n; ++i) {
    char request = 0;
    std::cin >> request;
    if (request == '+') {
      size_t position = 0;
      int64_t x = 0;
      std::cin >> position >> x;
      int64_t priority = rand();
      tree.Insert(position, x, priority);
    } else {
      int64_t left = 0;
      int64_t right = 0;
      std::cin >> left >> right;
      std::cout << tree.SubarrayMin(left - 1, right) << '\n';
    }
  }
  return 0;
}
