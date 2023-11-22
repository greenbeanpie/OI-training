#include <bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = unsigned __int128;
template <typename T>
using Vec = std::vector<T>;
using Str = std::string;
template <typename T, i32... size>
struct ArraySwitch;
template <typename T, i32 size>
struct ArraySwitch<T, size> { using Result = typename std::array<T, size>; };
template <typename T, i32 size, i32... other>
struct ArraySwitch<T, size, other...> { using Result = typename std::array<typename ArraySwitch<T, other...>::Result, size>; };
template <typename T, i32... size>
using Arr = typename ArraySwitch<T, size...>::Result;

template <typename T>
T _min(T x) { return x; }
template <typename T, typename... Args>
T _min(T x, T y, Args... args) { return _min<T>(std::min<T>(x, y), args...); }
template <typename T>
T _max(T x) { return x; }
template <typename T, typename... Args>
T _max(T x, T y, Args... args) { return _max<T>(std::max<T>(x, y), args...); }

constexpr i32 N = 500005;
constexpr i32 inf32 = i32(1e9) + 9;

i32 n, m, q;
Arr<i32, N> _a, _b, a, b;

namespace solution1 {
    Arr<i32, 2003, 2003> f;
    void solve() {
        for (i32 i = 1; i <= n; i++)
        for (i32 j = 1; j <= m; j++)
            f[i][j] = 0;
        f[1][1] = 1;
        for (i32 i = 1; i <= n; i++)
        for (i32 j = 1; j <= m; j++) {
            if (!f[i][j]) continue;
            if (i < n && a[i + 1] < b[j]) f[i + 1][j] = 1;
            if (j < m && a[i] < b[j + 1]) f[i][j + 1] = 1;
        }
        printf("%d", f[n][m]);
    }
}

void work() {
    if (a[1] == b[1]) {
        putchar('0');
        return;
    }
    bool flag = false;
    if (a[1] > b[1]) {
        flag = true;
        std::swap(a, b);
        std::swap(n, m);
    }
    solution1::solve();
    if (flag) {
        std::swap(a, b);
        std::swap(n, m);
    }
}

i32 main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    i32 _;
    scanf("%d%d%d%d", &_, &n, &m, &q);
    for (i32 i = 1; i <= n; i++) scanf("%d", &_a[i]);
    for (i32 i = 1; i <= m; i++) scanf("%d", &_b[i]);
    a = _a;
    b = _b;
    work();
    for (i32 i = 1; i <= q; i++) {
        a = _a, b = _b;
        i32 k1, k2;
        scanf("%d%d", &k1, &k2);
        for (i32 j = 1; j <= k1; j++) {
            i32 p, v;
            scanf("%d%d", &p, &v);
            a[p] = v;
        }
        for (i32 j = 1; j <= k2; j++) {
            i32 p, v;
            scanf("%d%d", &p, &v);
            b[p] = v;
        }
        work();
    }
    std::cerr << 1.L * std::clock() / CLOCKS_PER_SEC << std::endl;
    return 0;
}