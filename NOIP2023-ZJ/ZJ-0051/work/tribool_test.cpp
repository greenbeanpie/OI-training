#include <bits/stdc++.h>

template <typename Type>
Type read() {
    int ch, f = 0;
    while (!isdigit(ch = getchar())) f = ch == '-';
    Type x = ch ^ '0';
    while (isdigit(ch = getchar())) x = (x << 3) + (x << 1) + (ch ^ '0');
    return f ? -x : x;
}

template <>
char read<char>() {
    int ch;
    while (isspace(ch = getchar())) ;
    return ch;
}

template <typename Type>
void read(Type &x) {
    x = read<Type>();
}

template <typename Type, typename... Args>
void read(Type &x, Args &...args) {
    x = read<Type>();
    read(args...);
}

int main_single() {
    const int n = read<int>(), m = read<int>();

    std::vector<std::tuple<char, int, int> > opers(m);
    for (auto &[ch, i, j] : opers) {
        read(ch);
        j = 0;
        if (ch == 'T') {
            read(i);
        } else if (ch == 'F') {
            read(i);
        } else if (ch == 'U') {
            read(i);
        } else if (ch == '+') {
            read(i, j);
        } else if (ch == '-') {
            read(i, j);
        }
        --i, --j;
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

    std::cout << ans << '\n';

    return 0;
}

int main() {
    // freopen("tribool.in", "r", stdin);
    // freopen("tribool.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int Sub, T = 1;
    read(Sub, T);
    while (T--) main_single();

    return 0;
}
