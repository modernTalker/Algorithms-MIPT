#include <algorithm>
#include <iostream>

class Avl {
  struct Node {
    int64_t value;
    int64_t height = 1;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
  };
  Node* root_ = nullptr;
  int64_t Bfactor(Node* x) {
    return Height(x->right) - Height(x->left);
  }
  void FixHeight(Node* q) {
    int64_t h_right = q->right->height;
    int64_t h_left = q->left->height;
    if (h_right > h_left) {
      q->height = h_right + 1;
    } else {
      q->height = h_left + 1;
    }
  }
  Node* RightRotate(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    FixHeight(p);
    FixHeight(q);
    return p;
  }
  Node* LeftRotate(Node* p) {
    Node* q = p->right;
    p->right = q->left;
    q->left = p;
    FixHeight(p);
    FixHeight(q);
    return p;
  }
  Node* Balance(Node* p) {
    if (Bfactor(p) == 2) {
      if (Bfactor(p->right) < 0) {
        p->right = RightRotate(p->right);
      }
      return LeftRotate(p);
    }
    if (Bfactor(p) == -2) {
      if (Bfactor(p->left) > 0) {
        p->left = LeftRotate(p->left);
      }
      return RightRotate(p);
    }
    return p;
  }
  void ClearNode(Node* x) {
    if (x == nullptr) {
      return;
    }
    ClearNode(x->left);
    ClearNode(x->right);
    delete x;
  }
  Node* InsertNode(Node* root, int64_t value) {
    if (root == nullptr) {
      auto r = new Node{value};
      return r;
    }
    if (value < root->value) {
      root->left = InsertNode(root->left, value);
    } else {
      root->right = InsertNode(root->right, value);
    }
    return Balance(root);
  }
  int64_t Height(Node* x) {
    if (x == nullptr) {
      return 0;
    }
    return x->height;
  }
  Node* MaximumNode(Node* x) {
    if (x->right != nullptr) {
      return MaximumNode(x->right);
    }
    return x;
  }
  Node* SearchNode(Node* x, int64_t k) {
    if ((x == nullptr) || (k == x->value)) {
      return x;
    }
    if (k < x->value) {
      return SearchNode(x->left, k);
    }
    return SearchNode(x->right, k);
  }

 public:
  void Insert(int64_t value) {
    root_ = InsertNode(root_, value);
  }
  void Clear() {
    ClearNode(root_);
  }
  int64_t Height() {
    return Height(root_);
  }
  int64_t InorderWalk(Node* x, int64_t value) {
    if (x != nullptr) {
      InorderWalk(x->left, value);
      if (x->value >= value) {
        std ::cout << x->value << " ";
        return x->value;
      }
      InorderWalk(x->right, value);
      // return -1;
    }
    return -1;
  }
  int64_t Next(int64_t value) {
    Node* r = root_;
    int64_t ans = -1;
    while (r != nullptr) {
      if (r->value == value) {
        return value;
      }
      if (value < r->value) {
        if (ans > r->value || ans < value) {
          ans = r->value;
        }
        r = r->left;
      } else {
        r = r->right;
      }
    }
    return ans;
  }
  Node* Maximum() {
    return MaximumNode(root_);
  }
  Node* Search(int64_t k) {
    return SearchNode(root_, k);
  }
};

int main() {
  Avl tree;
  int64_t n;
  std ::cin >> n;
  char prev = '+';
  int64_t cur = 0;
  for (int64_t i = 0; i < n; ++i) {
    char a;
    std ::cin >> a;
    if (a == '?') {
      int64_t value;
      std ::cin >> value;
      std ::cout << tree.Next(value) << '\n';
      prev = '?';
      cur = value;
    }
    if (a == '+' && prev == '+') {
      int64_t value;
      std ::cin >> value;
      tree.Insert(value);
      prev = '+';
    }
    if (a == '+' && prev == '?') {
      int64_t value;
      std ::cin >> value;
      tree.Insert((value + tree.Next(cur)) % 1000000000);
      prev = '+';
    }
  }
  tree.Clear();
  return 0;
}
