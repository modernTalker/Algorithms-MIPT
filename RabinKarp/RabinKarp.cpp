#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <cmath>

class RabinKarp {
 public:
  explicit RabinKarp(std::string& s) {
    deg_.resize(s.size() + 1, 1);
    hash_s_.resize(s.size() + 1, 0);
    deg2_.resize(s.size() + 1, 1);
    hash_s2_.resize(s.size() + 1, 0);
    for (size_t i = 0; i < s.size(); ++i) {
      hash_s_[i + 1] = (((hash_s_[i] * p_) % m_) + (s[i])) % m_;
      deg_[i + 1] = (deg_[i] * p_) % m_;
      hash_s2_[i + 1] = (((hash_s2_[i] * p2_) % m_) + (s[i])) % m_;
      deg2_[i + 1] = (deg2_[i] * p2_) % m_;
    }
  }
  std::pair<int64_t, int64_t> SubstringHash(size_t left, size_t right) {
    int64_t result1 = (hash_s_[right + 1] - ((hash_s_[left] * deg_[right - left + 1]) % m_)) % m_;
    int64_t result2 = (hash_s2_[right + 1] - ((hash_s2_[left] * deg2_[right - left + 1]) % m_)) % m_;
    if (result1 < 0) {
      result1 += m_;
    }
    if (result2 < 0) {
      result2 += m_;
    }
    return {result1, result2};
  }

 private:
  std::vector<int64_t> deg_;
  std::vector<int64_t> hash_s_;
  std::vector<int64_t> deg2_;
  std::vector<int64_t> hash_s2_;
  int64_t p_ = 41;
  int64_t p2_ = 37;
  int64_t m_ = static_cast<int64_t>(std::pow(10, 9)) + 9;
};

int64_t CycleShiftsCount(std::string& pattern, std::string& text) {
  if (pattern.size() > text.size()) {
    return 0;
  }
  std::string shifts = pattern + pattern;
  RabinKarp hash_shifts(shifts);
  std::unordered_map<int64_t, int64_t> cycle_shift_hash;
  for (size_t i = 0; i < pattern.size(); ++i) {
    std::pair<int64_t, int64_t> double_hash = hash_shifts.SubstringHash(i, i + pattern.size() - 1);
    cycle_shift_hash[double_hash.first] = double_hash.second;
  }
  RabinKarp hash_text(text);
  int64_t sum = 0;
  for (size_t i = 0; i < text.size() - pattern.size() + 1; ++i) {
    std::pair<int64_t, int64_t> double_hash = hash_text.SubstringHash(i, i + pattern.size() - 1);
    if (cycle_shift_hash.contains(double_hash.first)) {
      if (cycle_shift_hash[double_hash.first] == double_hash.second) {
        sum += 1;
      }
    }
  }
  return sum;
}

int main() {
  std::string pattern;
  std::cin >> pattern;
  std::string text;
  std::cin >> text;
  std::cout << CycleShiftsCount(pattern, text) << '\n';
  return 0;
}
