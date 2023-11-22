#include <bits/stdc++.h>

std::mt19937_64 mt_rand(std::chrono::system_clock::now().time_since_epoch().count());

int64_t random(int64_t l, int64_t r) { return mt_rand() % (r - l + 1) + l; }

constexpr char CHAR_BEG = 'a';

int main_single() {

    const int n = 10, m = 10;

    std::vector<std::tuple<char, int, int> > opers(m);
    while (true) {
        for (auto &[ch, i, j] : opers) {
            ch = "TFU+++---"[random(0, 8)];
            if (ch == 'T') {
                i = random(0, n - 1);
            } else if (ch == 'F') {
                i = random(0, n - 1);
            } else if (ch == 'U') {
                i = random(0, n - 1);
            } else if (ch == '+') {
                i = random(0, n - 1);
                j = random(0, n - 1);
            } else if (ch == '-') {
                i = random(0, n - 1);
                j = random(0, n - 1);
            }
        }
        
        int ans = n + 1;
        std::vector<int> now(n), last(n);
        auto _F_dfs = [&](auto self, int u, int s) -> void {
            if (s >= ans) return;
            if (u == n) {
                last = now;
                for (auto [ch, i, j] : opers) {
                    if (ch == 'T') {
                        last[i] = 1;
                    } else if (ch == 'F') {
                        last[i] = -1;
                    } else if (ch == 'U') {
                        last[i] = 0;
                    } else if (ch == '+') {
                        last[i] = last[j];
                    } else if (ch == '-') {
                        last[i] = -last[j];
                    }
                }
                for (int i = 0; i < n; ++i) if (last[i] != now[i]) return;
                ans = std::min(ans, s);
                return;
            }
            now[u] = 1;
            self(self, u + 1, s);
            now[u] = -1;
            self(self, u + 1, s);
            now[u] = 0;
            self(self, u + 1, s + 1);
        };
        _F_dfs(_F_dfs, 0, 0);

        if (ans <= n) break;
    }

    std::cout << n << ' ' << m << '\n';
    for (auto [ch, i, j] : opers) {
        std::cout << ch << ' ' << i + 1;
        if (ch == '-' || ch == '+') std::cout << ' ' << j + 1;
        std::cout << '\n';
    }

    return 0;
}

int main() {
    // freopen("tribool.in", "r", stdin);
    // freopen("tribool.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int Sub = 0, T = 1;
    std::cout << Sub << ' ' << T << '\n';
    while (T--) main_single();

    return 0;
}
