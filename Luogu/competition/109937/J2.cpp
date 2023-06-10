#include <iostream>

int main() {
    
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::string s;
  int ans = 0, cur = 0;
  for (std::cin >> T; T; --T) {
    std::cin >> s;
    ++cur;
    if (s.find("std::cerr") != std::string::npos) {
      std::cerr << cur << '\n';
      ++ans;
    }
  }
  std::cout << ans << std::endl;
}