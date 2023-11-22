#include <bits/stdc++.h>

template <typename Type>
Type read() {
    int ch, f = 0;
    while (!isdigit(ch = getchar())) f = ch == '-';
    Type x = ch ^ '0';
    while (isdigit(ch = getchar())) x = (x << 3) + (x << 1) + (ch ^ '0');
    return f ? -x : x;
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

int main() {
    // freopen("expand.in", "r", stdin);
    // freopen("expand.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    
    const int c = read<int>();
    int n = read<int>();
    int m = read<int>();
    const int q = read<int>();

    std::vector<int> ax(n), ay(m);
    for (auto &x : ax) read(x);
    for (auto &x : ay) read(x);

    auto solve = [&]() -> bool {
        std::vector<int> f(m);
        f[0] = 1;
        if (ax[0] >= ay[0]) return false;
        for (int i = 0; i < n; ++i) {
            std::vector<int> g(m);
            for (int j = 0; j < m; ++j) {
                f[j] &= ax[i] < ay[j];
                if (f[j]) {
                    if (j + 1 < m) f[j + 1] = 1;
                    g[j] = 1;
                }
            }
            if (i + 1 < n) f.swap(g);
        }
        return f.back();
    };

    auto query = [&]() {
        bool swaped;
        if (swaped = ax.front() > ay.front()) {
            ax.swap(ay);
            std::swap(n, m);
        }
        std::cout << solve();
        if (swaped) {
            ax.swap(ay);
            std::swap(n, m);
        }
    };

    query();

    for (int qi = 0; qi < q; ++qi) {
        const int kx = read<int>();
        const int ky = read<int>();
        std::vector<std::pair<int, int> > mx(kx), my(ky);
        for (auto &[p, v] : mx) {
            p = read<int>() - 1;
            v = ax[p];
            read(ax[p]);
        }
        for (auto &[p, v] : my) {
            p = read<int>() - 1;
            v = ay[p];
            read(ay[p]);
        }
        query();
        for (auto &[p, v] : mx) ax[p] = v;
        for (auto &[p, v] : my) ay[p] = v;
    }

    std::cout << '\n';

    return 0;
}
