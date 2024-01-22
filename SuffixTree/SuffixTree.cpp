#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct Node {
  Node() = default;
  std::unordered_map<char, int> transitions;
  int suffix = -1;
  int length = 0;
  int end_pos = -1;
};

class SuffixTree;

class SuffixAutomaton {
  friend SuffixTree;

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

struct TreeNode {
  TreeNode() = default;
  std::unordered_map<char, int> transitions;
  int begin = -1;
  int length = 0;
};

class SuffixTree {
  friend SuffixAutomaton;

 public:
  explicit SuffixTree(std::string& string) {
    std::string tree_string = string + "#";
    std::string reversed_string(tree_string.rbegin(), tree_string.rend());
    SuffixAutomaton automaton(reversed_string);
    tree_.resize(automaton.automaton_.size(), {});
    for (int node_id = 1; node_id < static_cast<int>(tree_.size()); ++node_id) {
      ExtractTransitions(automaton, node_id, tree_string);
    }
  }
  void Traversal() {
    std::cout << tree_.size() << '\n';
    for (size_t i = 0; i < tree_.size(); ++i) {
      for (auto pair : tree_[i].transitions) {
        std::cout << i << " " << pair.first << " " << tree_[pair.second].length << " " << pair.second << '\n';
      }
    }
  }

 private:
  void ExtractTransitions(SuffixAutomaton& automaton, int node_id, std::string& string) {
    int suffix_id = automaton.automaton_[node_id].suffix;
    tree_[node_id].begin = static_cast<int>(string.size()) - 1 -
                           (automaton.automaton_[node_id].end_pos - automaton.automaton_[suffix_id].length);
    tree_[node_id].length = automaton.automaton_[node_id].length - automaton.automaton_[suffix_id].length;
    tree_[suffix_id].transitions[string[tree_[node_id].begin]] = node_id;
  }

 private:
  std::vector<TreeNode> tree_;
};

int main() {
  std::string string;
  std::cin >> string;
  SuffixTree tree(string);
  tree.Traversal();
  return 0;
}
