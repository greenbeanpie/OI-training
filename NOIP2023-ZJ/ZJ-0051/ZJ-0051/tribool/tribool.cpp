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

struct DSU {
    std::vector<int> f;
    DSU(size_t n) : f(n) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    int operator()(int i) { return find(i); }
    bool merge(int x, int y) { return (x = find(x)) != (y = find(y)) ? f[y] = x, 1 : 0; }
};

int main_single() {
    const int n = read<int>(), m = read<int>();

    std::vector<int> now(n);
    std::iota(now.begin(), now.end(), 0);
    for (int i = 0; i < m; ++i) {
        const char ch = read<char>();
        // std::cerr << "read " << ch << '\n';
        if (ch == 'T') {
            const int i = read<int>() - 1;
            now[i] = n;
        } else if (ch == 'F') {
            const int i = read<int>() - 1;
            now[i] = n + 1;
        } else if (ch == 'U') {
            const int i = read<int>() - 1;
            now[i] = n + 2;
        } else if (ch == '+') {
            const int i = read<int>() - 1;
            const int j = read<int>() - 1;
            now[i] = now[j];
        } else if (ch == '-') {
            const int i = read<int>() - 1;
            const int j = read<int>() - 1;
            now[i] = -1 - now[j];
        }
    }
    
    // std::cerr << "now = ";
    // for (auto x : now) std::cerr << x << ' ';
    // std::cerr << '\n';

    const int BEG = n + 3;
    for (auto &x : now) if (x == -1 - n) {
        x = n + 1;
    } else if (x == -1 - (n + 1)) {
        x = n;
    } else if (x == -1 - (n + 2)) {
        x = n + 2;
    } else if (x < 0) {
        x = (-1 - x) + BEG;
    }
    
    // std::cerr << "now = ";
    // for (auto x : now) std::cerr << x << ' ';
    // std::cerr << '\n';

    std::vector<int> ans(n + BEG, -2);

    DSU dsu(BEG + n);
    for (int i = 0; i < n; ++i) dsu.merge(now[i], i);

    std::vector<std::vector<int> > to(n + BEG);
    for (int i = 0; i < n; ++i) {
        const int u = dsu(i), v = dsu(BEG + i);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    auto _F_dfs = [&](auto self, int u, int c) -> bool {
        ans[u] = c;
        c = -c;
        for (auto v : to[u]) if (ans[v] == -2) {
            if (self(self, v, c)) return true;
        } else if (ans[v] != c) {
            if (c) return true;
            self(self, v, c);
        }
        return false;
    };
    if (dsu(n) == n) {
        auto b = _F_dfs(_F_dfs, n, 1);
        assert(!b);
    }
    if (dsu(n + 1) == n + 1 && ans[n + 1] == -2) {
        auto b = _F_dfs(_F_dfs, n + 1, -1);
        assert(!b);
    } else {
        assert(ans[dsu(n + 1)] == -1);
    }
    {
        auto b = _F_dfs(_F_dfs, n + 2, 0);
        assert(!b);
    }
    for (int i = 0; i < n + BEG; ++i) if (dsu(i) == i && ans[i] == -2) {
        auto b = _F_dfs(_F_dfs, i, 1);
        if (b) {
            b = _F_dfs(_F_dfs, i, 0);
            assert(!b);
        }
    }

    int out = 0;
    for (int i = 0; i < n; ++i) out += (ans[i] = ans[dsu(i)]) == 0;

    // for (int i = 0; i < n; ++i) std::cerr << ans[i] << ' ';//"FUT"[ans[i] + 1];
    // std::cerr << '\n';

    std::cout << out << '\n';

    return 0;
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int Sub, T = 1;
    read(Sub, T);
    while (T--) main_single();

    return 0;
}
