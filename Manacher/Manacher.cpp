#include <iostream>
#include <vector>
#include <string>

void Manacher(const std::vector<int>& string) {
  int n = static_cast<int>(string.size());
  std::vector<int> even_polindroms(n);
  int left_border = 0;
  int right_border = -1;
  for (int i = 0; i < n; ++i) {
    int current_radius = 0;
    if (i <= right_border) {
      current_radius = std::min(even_polindroms[left_border + right_border - i + 1], right_border - i + 1);
    }
    while (i + current_radius < n && i - current_radius - 1 >= 0 &&
           string[i + current_radius] == string[i - current_radius - 1]) {
      ++current_radius;
    }
    even_polindroms[i] = current_radius;
    if (i + current_radius - 1 > right_border) {
      left_border = i - current_radius;
      right_border = i + current_radius - 1;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == even_polindroms[i]) {
      std::cout << n - i << " ";
    }
  }
}

int main() {
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  std::vector<int> cubes(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> cubes[i];
  }
  Manacher(cubes);
  return 0;
}
