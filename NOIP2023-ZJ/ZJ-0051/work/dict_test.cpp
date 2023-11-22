#include <bits/stdc++.h>

constexpr int C = 26;
constexpr char CHAR_BEG = 'a';

int main() {
    // freopen("dict.in", "r", stdin);
    // freopen("dict.out", "w", stdout);
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> str(n);
    for (auto &s : str) {
        std::cin >> s;
        std::sort(s.begin(), s.end(), std::greater<char>());
    }

    for (int i = 0; i < n; ++i) {
        bool can = true;
        std::reverse(str[i].begin(), str[i].end());
        for (int j = 0; j < n; ++j) if (i != j) {
            bool small = false;
            for (int k = 0; k < m; ++k) if (str[i][k] != str[j][k]) {
                small = str[i][k] < str[j][k];
                break;
            }
            if (!small) {
                can = false;
                break;
            }
        }
        std::reverse(str[i].begin(), str[i].end());
        std::cout << can;
    }
    std::cout << '\n';

    return 0;
}
