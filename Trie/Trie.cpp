#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct Node {
  Node() = default;
  std::unordered_map<char, int> next;
  bool is_terminal;
};

class Trie {
 public:
  Trie() {
    trie_.resize(1, {});
  }
  void Insert(std::string& string) {
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
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Trie trie;
  char command = '0';
  while (std::cin >> command) {
    if (command == '#') {
      break;
    }
    if (command == '+') {
      std::string str;
      std::cin >> str;
      trie.Insert(str);
    } else {
      std::string str;
      std::cin >> str;
      if (trie.Find(str)) {
        std::cout << "YES" << '\n';
      } else {
        std::cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
