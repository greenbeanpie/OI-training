#include <bits/stdc++.h>

std::mt19937_64 mt_rand(std::chrono::system_clock::now().time_since_epoch().count());

int64_t random(int64_t l, int64_t r) { return mt_rand() % (r - l + 1) + l; }

constexpr char CHAR_BEG = 'a';

int main() {
    // freopen("dict.in", "r", stdin);
    // freopen("dict.out", "w", stdout);
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n = 3000, m = 10, v = 5;

    std::cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cout << char(CHAR_BEG + random(0, v - 1));
        std::cout << '\n';
    }

    return 0;
}
