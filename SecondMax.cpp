#include <iostream>

class BinaryTree {
  struct Node {
    int64_t value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
  };
  Node* root_ = nullptr;
  int64_t height_ = 0;

  void ClearNode(Node* x) {
    if (x == nullptr) {
      return;
    }
    ClearNode(x->left);
    ClearNode(x->right);
    delete x;
  }
  Node* MaximumNode(Node* x) {
    if (x->right != nullptr) {
      return MaximumNode(x->right);
    }
    return x;
  }
  Node* ParentMax(Node* x) {
    int64_t mx = MaximumNode(root_)->value;
    if ((x->right != nullptr) && (x->right->value != mx)) {
      return ParentMax(x->right);
    }
    return x;
  }

 public:
  void Insert(int64_t value) {
    auto x = new Node{value};
    Node* y = nullptr;
    Node* r = root_;
    int64_t height = 1;
    while (r != nullptr) {
      height++;
      y = r;
      if (x->value < r->value) {
        r = r->left;
      } else {
        r = r->right;
      }
    }
    x->parent = y;
    if (y == nullptr) {
      root_ = x;
    } else if (x->value < y->value) {
      y->left = x;
    } else {
      y->right = x;
    }
    if (height > height_) {
      height_ = height;
    }
  }
  void Clear() {
    ClearNode(root_);
  }
  int64_t Height() {
    return height_;
  }
  Node* Maximum() {
    return MaximumNode(root_);
  }
  Node* ParentMax() {
    return ParentMax(root_);
  }
  int64_t SecondMax() {
    if (MaximumNode(root_)->parent == nullptr) {
      return MaximumNode(ParentMax(root_)->left)->value;
    }
    if (ParentMax(root_)->right->left != nullptr) {
      return MaximumNode(ParentMax(root_)->right->left)->value;
    }
    return ParentMax(root_)->value;
  }
};

int main() {
  BinaryTree tree;
  while (true) {
    int64_t a;
    std ::cin >> a;
    if (a == 0) {
      break;
    }
    tree.Insert(a);
  }
  std ::cout << tree.SecondMax() << '\n';
  tree.Clear();
  return 0;
}
