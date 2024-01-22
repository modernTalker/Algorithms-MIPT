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
  int64_t Exit() {
    Clear();
    return 0;
  }
};

int main() {
  List list;
  int k;
  std ::cin >> k;
  for (int i = 0; i < k; ++i) {
    char command[30];
    std ::cin >> command;
    if (strcmp(command, "push_back") == 0) {
      int64_t value;
      std ::cin >> value;
      list.PushBack(value);
      std ::cout << "ok" << '\n';
    }
    if (strcmp(command, "push_front") == 0) {
      int64_t value;
      std ::cin >> value;
      list.PushFront(value);
      std ::cout << "ok" << '\n';
    }
    if (strcmp(command, "pop_front") == 0) {
      if (list.length == 0) {
        std ::cout << "error" << '\n';
        continue;
      }
      int64_t ans = list.PopFront();
      std ::cout << ans << '\n';
    }
    if (strcmp(command, "pop_back") == 0) {
      if (list.length == 0) {
        std ::cout << "error" << '\n';
        continue;
      }
      int64_t ans = list.PopBack();
      std ::cout << ans << '\n';
    }
    if (strcmp(command, "front") == 0) {
      if (list.length == 0) {
        std ::cout << "error" << '\n';
        continue;
      }
      int64_t ans = list.Front();
      std ::cout << ans << '\n';
    }
    if (strcmp(command, "back") == 0) {
      if (list.length == 0) {
        std ::cout << "error" << '\n';
        continue;
      }
      int64_t ans = list.Back();
      std ::cout << ans << '\n';
    }
    if (strcmp(command, "size") == 0) {
      int64_t ans = list.Size();
      std ::cout << ans << '\n';
    }
    if (strcmp(command, "clear") == 0) {
      list.Clear();
      std ::cout << "ok" << '\n';
    }
    if (strcmp(command, "exit") == 0) {
      list.Exit();
      std ::cout << "bye" << '\n';
    }
  }
  int64_t len = list.length;
  if (len > 0) {
    list.Clear();
  }
  return 0;
}
