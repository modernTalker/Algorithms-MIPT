#include <iostream>
#include <vector>
#include <string>

class PiFunction {
 public:
  explicit PiFunction(const std::string& string) {
    prefix_.resize(string.size());
    prefix_[0] = 0;
    for (size_t i = 1; i < string.size(); ++i) {
      size_t j = prefix_[i - 1];
      while (j >= 1 && string[j] != string[i]) {
        j = prefix_[j - 1];
      }
      if (string[j] == string[i]) {
        ++j;
      }
      prefix_[i] = j;
    }
  }
  size_t operator[](size_t idx) {
    return prefix_[idx];
  }

 private:
  std::vector<size_t> prefix_;
};

std::vector<size_t> KMP(std::string& str, std::string& pattern) {
  size_t size = pattern.size() + str.size() + 1;
  std::string string(size, 'x');
  for (size_t i = 0; i < size; ++i) {
    if (i < pattern.size()) {
      string[i] = pattern[i];
    } else if (i == pattern.size()) {
      string[i] = '#';
    } else if (i > pattern.size()) {
      string[i] = str[i - pattern.size() - 1];
    }
  }
  PiFunction prefix(string);
  std::vector<size_t> idx_of_substring;
  for (size_t i = 0; i + pattern.size() + 1 < size; ++i) {
    if (prefix[i + pattern.size() + 1] == pattern.size()) {
      idx_of_substring.push_back(i - pattern.size() + 1);
    }
  }
  return idx_of_substring;
}

int main() {
  std::string string;
  std::cin >> string;
  std::string pattern;
  std::cin >> pattern;
  auto ans = KMP(string, pattern);
  for (size_t i = 0; i < ans.size(); ++i) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
