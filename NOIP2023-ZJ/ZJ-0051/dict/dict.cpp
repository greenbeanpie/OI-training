#include <bits/stdc++.h>

constexpr int C = 26;
constexpr char CHAR_BEG = 'a';

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::array<int, C> max_num;
    max_num.fill(0);

    std::vector<std::string> str(n);
    for (auto &s : str) {
        std::cin >> s;
        for (auto &ch : s) ch -= CHAR_BEG;
        std::sort(s.begin(), s.end());
        ++max_num[s.back()];
    }

    for (auto s : str) {
        --max_num[s.back()];
        int max_n = 0;
        for (int i = s.front(); i >= 0; --i) max_n = std::max(max_n, max_num[i]);
        std::cout << !max_n;
        ++max_num[s.back()];
    }
    std::cout << '\n';

    return 0;
}
