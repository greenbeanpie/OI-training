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
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

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
        const int px = std::min_element(ax.begin(), ax.end()) - ax.begin();
        const int py = std::max_element(ay.begin(), ay.end()) - ay.begin();
        std::vector<std::pair<int, int> > sx, sy;
        sx.reserve(std::max(px + 1, n - px));
        sy.reserve(std::max(py + 1, m - py));
        {
            int last = INT32_MAX, now = INT32_MIN;
            for (int i = 0; i <= px; ++i) {
                now = std::max(now, ax[i]);
                if (ax[i] <= last) {
                    sx.emplace_back(ax[i], now);
                    last = ax[i];
                }
            }
        }
        {
            int last = INT32_MIN, now = INT32_MAX;
            for (int i = 0; i <= py; ++i) {
                now = std::min(now, ay[i]);
                if (ay[i] >= last) {
                    sy.emplace_back(ay[i], now);
                    last = ay[i];
                }
            }
        }
        {
            int i = 0, j = 0;
            while (i + 1 < sx.size() || j + 1 < sy.size()) {
                bool added = false;
                while (i + 1 < sx.size() && sx[i + 1].second < sy[j].first) ++i, added = true;
                while (j + 1 < sy.size() && sy[j + 1].second > sx[i].first) ++j, added = true;
                if (!added) return false;
            }
        }
        sx.resize(0);
        sy.resize(0);
        {
            int last = INT32_MAX, now = INT32_MIN;
            for (int i = n - 1; i >= px; --i) {
                now = std::max(now, ax[i]);
                if (ax[i] <= last) {
                    sx.emplace_back(ax[i], now);
                    last = ax[i];
                }
            }
        }
        {
            int last = INT32_MIN, now = INT32_MAX;
            for (int i = m - 1; i >= py; --i) {
                now = std::min(now, ay[i]);
                if (ay[i] >= last) {
                    sy.emplace_back(ay[i], now);
                    last = ay[i];
                }
            }
        }
        {
            int i = 0, j = 0;
            while (i + 1 < sx.size() || j + 1 < sy.size()) {
                bool added = false;
                while (i + 1 < sx.size() && sx[i + 1].second < sy[j].first) ++i, added = true;
                while (j + 1 < sy.size() && sy[j + 1].second > sx[i].first) ++j, added = true;
                if (!added) return false;
            }
        }
        return true;
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
