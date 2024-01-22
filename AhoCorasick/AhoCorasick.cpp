#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

struct Node {
  Node() = default;
  std::unordered_map<char, int> next;
  int suff_link;
  int exit_link;
  bool is_terminal;
};

struct QueueElement {
  QueueElement() = default;
  QueueElement(char symb, int r, int n) : symbol(symb), root(r), node(n) {
  }
  char symbol;
  int root;
  int node;
};

class Trie {
 public:
  Trie() {
    trie_.resize(1, {});
  }
  explicit Trie(std::vector<std::string>& patterns) {
    trie_.resize(1, {});
    for (size_t i = 0; i < patterns.size(); ++i) {
      int node = Insert(patterns[i]);
      string_index_.insert({node, i});
      entries_.emplace_back();
    }
  }

  void BuildSuffixLinks() {
    int current_idx = 0;
    trie_[current_idx].suff_link = -1;
    std::queue<QueueElement> queue;
    for (auto pair : trie_[current_idx].next) {
      queue.emplace(pair.first, current_idx, pair.second);
    }
    while (!queue.empty()) {
      auto element = queue.front();
      queue.pop();
      char s = element.symbol;
      int parent = element.root;
      int node = element.node;
      auto suff_ref = trie_[parent].suff_link;
      while (suff_ref != -1 && !trie_[suff_ref].next.contains(s)) {
        suff_ref = trie_[suff_ref].suff_link;
      }
      trie_[node].suff_link = ((suff_ref == -1) ? 0 : trie_[suff_ref].next[s]);
      for (auto pair : trie_[node].next) {
        queue.emplace(pair.first, node, pair.second);
      }
    }
  }
  void BuildExitLinks() {
    int current_idx = 0;
    trie_[current_idx].exit_link = -1;
    std::queue<int> queue;
    for (auto pair : trie_[current_idx].next) {
      queue.push(pair.second);
    }
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();
      auto suff = trie_[node].suff_link;
      if (node != 0 && suff != 0) {
        trie_[node].exit_link = (trie_[suff].is_terminal ? suff : trie_[suff].exit_link);
      }
      for (auto pair : trie_[node].next) {
        queue.push(pair.second);
      }
    }
  }
  int NextState(char symbol, int node) {
    while (node != -1 && !trie_[node].next.contains(symbol)) {
      node = trie_[node].suff_link;
    }
    return (node == -1 ? 0 : trie_[node].next[symbol]);
  }
  void CollectEntries(int index, int node, std::vector<std::string>& patterns) {
    if (!trie_[node].is_terminal) {
      node = trie_[node].exit_link;
    }
    while (node > 0) {
      auto string_i = string_index_[node];
      auto size_of_string_i = patterns[string_i].size();
      entries_[string_i].emplace_back(index - size_of_string_i + 2);
      node = trie_[node].exit_link;
    }
  }
  void PrintEntries() {
    for (size_t i = 0; i < entries_.size(); ++i) {
      std::cout << entries_[i].size() << " ";
      if (!entries_[i].empty()) {
        for (size_t j = 0; j < entries_[i].size(); ++j) {
          std::cout << entries_[i][j] << " ";
        }
      }
      std::cout << '\n';
    }
  }

  int Insert(std::string& string) {
    int current_idx = 0;
    for (auto symbol : string) {
      int next_id = trie_[current_idx].next[symbol];
      if (next_id == 0) {
        trie_.emplace_back();
        trie_[current_idx].next[symbol] = static_cast<int>(trie_.size()) - 1;
        next_id = trie_[current_idx].next[symbol];
      }
      current_idx = next_id;
    }
    trie_[current_idx].is_terminal = true;
    return current_idx;
  }
  bool Find(std::string& string) {
    int current_idx = 0;
    for (auto symbol : string) {
      int next_id = trie_[current_idx].next[symbol];
      if (next_id == 0) {
        return false;
      }
      current_idx = next_id;
    }
    return trie_[current_idx].is_terminal;
  }

 private:
  std::vector<Node> trie_;
  std::unordered_map<int, int> string_index_;
  std::vector<std::vector<int>> entries_;
};

void AchoCorasick(std::string& string, std::vector<std::string>& patterns) {
  Trie trie(patterns);
  trie.BuildSuffixLinks();
  trie.BuildExitLinks();
  int cur = 0;
  for (size_t i = 0; i < string.size(); ++i) {
    cur = trie.NextState(string[i], cur);
    trie.CollectEntries(static_cast<int>(i), cur, patterns);
  }
  trie.PrintEntries();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string string;
  std::cin >> string;
  size_t n = 0;
  std::cin >> n;
  std::vector<std::string> patterns(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> patterns[i];
  }
  AchoCorasick(string, patterns);
  return 0;
}
