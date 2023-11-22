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

constexpr i32 N = 100005;

i32 n, m;
struct Op { i32 t, x, y; };
Arr<Op, N> ops;
Arr<std::pair<i32, i32>, N> h;
Arr<i32, N * 2> par, tag;
i32 get_par(i32 x) {
    while (x != par[x])
        x = par[x] = par[par[x]];
    return x;
}
void merge(i32 x, i32 y) {
    x = get_par(x);
    y = get_par(y);
    if (x != y) par[y] = x;
}

i32 main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    i32 _, num_tests;
    scanf("%d%d", &_, &num_tests);
    for (i32 cur_test = 1; cur_test <= num_tests; cur_test++) {
        scanf("%d%d", &n, &m);
        for (i32 i = 1; i <= m; i++) {
            static Arr<char, 10> str;
            scanf("%s", str.begin());
            if (str[0] == '+') {
                i32 x, y;
                scanf("%d%d", &x, &y);
                ops[i] = {2, x, y};
            }
            else if (str[0] == '-') {
                i32 x, y;
                scanf("%d%d", &x, &y);
                ops[i] = {3, x, y};
            }
            else {
                i32 x;
                scanf("%d", &x);
                ops[i] = {str[0] == 'F' ? -1 : str[0] == 'T' ? 1 : 0, x, 0};
                assert(ops[i].t < 2);
            }
        }
        for (i32 i = 1; i <= n; i++) h[i] = {0, i};
        for (i32 i = 1; i <= m; i++) {
            if (ops[i].t == 2)
                h[ops[i].x] = {h[ops[i].y].first, h[ops[i].y].second};
            else if (ops[i].t == 3)
                h[ops[i].x] = {h[ops[i].y].first, -h[ops[i].y].second};
            else
                h[ops[i].x] = {1, ops[i].t};
        }
        for (i32 i = 1; i <= 2 * n; i++) {
            par[i] = i;
            tag[i] = 0;
        }
        i32 ans = 0;
        for (i32 i = 1; i <= n; i++)
        if (h[i].first == 0) {
            i32 id = h[i].second;
            if (id < 0) {
                merge(i, -id + n);
                merge(i + n, -id);
            }
            else {
                merge(i, id);
                merge(i + n, id + n);
            }
        }
        for (i32 i = 1; i <= n; i++)
        if (h[i].first == 1) {
            if (h[i].second == 0) {
                tag[get_par(i)] = 1;
                tag[get_par(i + n)] = 1;
            }
        }
        for (i32 i = 1; i <= n; i++)
            ans += tag[get_par(i)] || tag[get_par(i + n)] || get_par(i) == get_par(i + n);
        printf("%d\n", ans);
    }
    std::cerr << 1.L * std::clock() / CLOCKS_PER_SEC << std::endl;
    return 0;
}