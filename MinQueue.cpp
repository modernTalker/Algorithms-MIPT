#include <cstring>
#include <iostream>

class List {
 private:
  struct Node {
    int64_t value;
    Node* previous = nullptr;
    Node* next = nullptr;
  };

 public:
  Node* begin;
  Node* end;
  int64_t length = 0;
  void PushFront(int64_t value) {
    auto x = new Node{value};
    if (length == 0) {
      begin = x;
      end = x;
      length++;
      return;
    }
    begin->previous = x;
    x->next = begin;
    begin = x;
    length++;
  }
  void PushBack(int64_t value) {
    auto x = new Node{value};
    if (length == 0) {
      begin = x;
      end = x;
      length++;
      return;
    }
    end->next = x;
    x->previous = end;
    end = x;
    length++;
  }
  int64_t PopFront() {
    if (length == 0) {
      return -1;
    }
    if (length == 1) {
      Node* x = begin;
      int64_t ans = x->value;
      length--;
      delete x;
      return ans;
    }
    Node* y = begin->next;
    Node* x = begin;
    int64_t ans = x->value;
    y->previous = nullptr;
    begin = y;
    length--;
    delete x;
    return ans;
  }
  int64_t PopBack() {
    if (length == 0) {
      return -1;
    }
    if (length == 1) {
      Node* x = end;
      int64_t ans = x->value;
      length--;
      delete x;
      return ans;
    }
    Node* y = end;
    Node* x = end->previous;
    int64_t ans = y->value;
    x->next = nullptr;
    end = x;
    length--;
    delete y;
    return ans;
  }
  int64_t Front() {
    if (length == 0) {
      return -1;
    }
    int64_t ans = begin->value;
    return ans;
  }
  int64_t Back() {
    if (length == 0) {
      return -1;
    }
    int64_t ans = end->value;
    return ans;
  }
  int64_t Size() {
    int64_t ans = length;
    return ans;
  }
  void Clear() {
    while (length > 0) {
      PopFront();
    }
  }
};

// Stack with minimum;

class Stack {
  List list_;
  List mins_;

 public:
  int64_t Pop() {
    if (list_.Back() == mins_.Back()) {
      mins_.PopBack();
    }
    int64_t ans = list_.PopBack();
    return ans;
  }
  void Push(int64_t x) {
    if (mins_.length == 0 || x <= mins_.Back()) {
      mins_.PushBack(x);
    }
    list_.PushBack(x);
  }
  int64_t Top() {
    int64_t ans = list_.Back();
    return ans;
  }
  int64_t Size() {
    int64_t ans = list_.length;
    return ans;
  }
  void Clear() {
    list_.Clear();
    mins_.Clear();
  }
  int64_t Min() {
    int64_t ans = mins_.Back();
    return ans;
  }
};

class Queue {
  Stack stack1_;
  Stack stack2_;

 public:
  void Push(int64_t x) {
    stack1_.Push(x);
  }
  int64_t Pop() {
    if (stack2_.Size() == 0) {
      while (stack1_.Size() > 0) {
        stack2_.Push(stack1_.Pop());
      }
      return stack2_.Pop();
    }
    return stack2_.Pop();
  }
  int64_t Top() {
    if (stack2_.Size() == 0) {
      while (stack1_.Size() > 0) {
        stack2_.Push(stack1_.Pop());
      }
      return stack2_.Top();
    }
    return stack2_.Top();
  }
  int64_t Size() {
    int64_t ans = stack1_.Size() + stack2_.Size();
    return ans;
  }
  void Clear() {
    stack1_.Clear();
    stack2_.Clear();
  }
  int64_t Min() {
    if (stack1_.Size() == 0) {
      return stack2_.Min();
    }
    if (stack2_.Size() == 0) {
      return stack1_.Min();
    }
    if (stack1_.Min() < stack2_.Min()) {
      return stack1_.Min();
    }
    return stack2_.Min();
  }
};

int main() {
  Queue list;
  int k;
  std::cin >> k;
  for (int i = 0; i < k; ++i) {
    char command[8];
    std::cin >> command;
    if (strcmp(command, "enqueue") == 0) {
      int64_t value;
      std ::cin >> value;
      list.Push(value);
      std::cout << "ok" << '\n';
    }
    if (strcmp(command, "dequeue") == 0) {
      if (list.Size() == 0) {
        std::cout << "error" << '\n';
        continue;
      }
      int64_t ans = list.Pop();
      std::cout << ans << '\n';
    }
    if (strcmp(command, "front") == 0) {
      if (list.Size() == 0) {
        std::cout << "error" << '\n';
        continue;
      }
      int64_t ans = list.Top();
      std::cout << ans << '\n';
    }
    if (strcmp(command, "size") == 0) {
      int64_t ans = list.Size();
      std::cout << ans << '\n';
    }
    if (strcmp(command, "clear") == 0) {
      list.Clear();
      std::cout << "ok" << '\n';
    }
    if (strcmp(command, "min") == 0) {
      if (list.Size() == 0) {
        std::cout << "error" << '\n';
        continue;
      }
      std::cout << list.Min() << '\n';
    }
  }
  list.Clear();
  return 0;
}
