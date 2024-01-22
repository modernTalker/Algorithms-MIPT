#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

struct Node {
  Node() = default;
  std::unordered_map<char, int> transitions;
  int suffix = -1;
  int length = 0;
  int end_pos = -1;
};

struct QueueElement {
  QueueElement() = default;
  int from;
  char symbol;
  int to;
};

class SuffixAutomaton {
 public:
  SuffixAutomaton() {
    automaton_.resize(1, {});
    last_ = 0;
  }
  explicit SuffixAutomaton(std::string& string) {
    automaton_.resize(1, {});
    last_ = 0;
    for (size_t i = 0; i < string.size(); ++i) {
      AddSymbol(string[i]);
    }
  }
  void AddSymbol(char c) {
    Node new_node;
    new_node.length = automaton_[last_].length + 1;
    new_node.end_pos = automaton_[last_].end_pos + 1;
    int new_id = static_cast<int>(automaton_.size());
    automaton_.push_back(new_node);
    while (last_ != -1 && !automaton_[last_].transitions.contains(c)) {
      automaton_[last_].transitions[c] = new_id;
      last_ = automaton_[last_].suffix;
    }
    if (last_ == -1) {
      automaton_[new_id].suffix = 0;
    } else if (automaton_[last_].length + 1 == automaton_[automaton_[last_].transitions[c]].length) {
      automaton_[new_id].suffix = automaton_[last_].transitions[c];
    } else {
      automaton_[new_id].suffix = Clone(last_, c, automaton_[last_].transitions[c]);
    }
    last_ = new_id;
  }
  void Traversal() {
    std::cout << automaton_.size() << '\n';
    for (size_t i = 0; i < automaton_.size(); ++i) {
      for (auto pair : automaton_[i].transitions) {
        std::cout << i << " " << pair.first << " " << pair.second << '\n';
      }
    }
  }

 private:
  int Clone(int parent, char c, int node) {
    Node clone = automaton_[node];
    clone.length = automaton_[parent].length + 1;
    int clone_idx = static_cast<int>(automaton_.size());
    automaton_.push_back(clone);
    automaton_[node].suffix = clone_idx;
    while ((parent != -1) && automaton_[parent].transitions.contains(c) && automaton_[parent].transitions[c] == node) {
      automaton_[parent].transitions[c] = clone_idx;
      parent = automaton_[parent].suffix;
    }
    return clone_idx;
  }

 private:
  std::vector<Node> automaton_;
  int last_;
};

int main() {
  std::string string;
  std::cin >> string;
  SuffixAutomaton automaton(string);
  automaton.Traversal();
  return 0;
}
