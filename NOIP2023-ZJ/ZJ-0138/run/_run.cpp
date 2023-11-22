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

constexpr i32 N = 100005;
constexpr i32 inf32 = i32(1e9) + 9;

i32 n, m, k, d;
Arr<S, N> a;
Arr<i64, 2 * N> f;
struct S { i32 l, r, v; };
Arr<Vec<S>, 2 * N> h;

i32 main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    i32 _;
    i32 num_tests;
    scanf("%d%d", &_, &num_tests);
    for (i32 cur_test = 1; cur_test <= num_tests; cur_test++) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        Vec<i32> hash;
        for (i32 i = 1; i <= m; i++) {
            i32 x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            a[i] = {x - y, x, v};
            hash.push_back(x - y);
            hash.push_back(x);
        }
        std::sort(hash.begin(), hash.end());
        hash.resize(std::unique(hash.begin(), hash.end()) - hash.begin());
        i32 len = hash.size();
        for (i32 i = 0; i <= len; i++) h[i].clear();
        for (i32 i = 1; i <= m; i++) {
            a[i].l = std::lower_bound(hash.begin(), hash.end(), a[i].l) - hash.begin();
            a[i].r = std::lower_bound(hash.begin(), hash.end(), a[i].r) - hash.begin();
            h[a[i].l].push_back(a[i]);
        }
        for (i32 i = 0; i <= len; i++) f[i] = 0;
        for (i32 i = 1; i < len; i++) {
            f[i + 1] = _max(f[i + 1], f[i]);
            i64 sum = 0;
            for (i32 j = i - 1; j >= 0; j--) {
                if (hash[i] - hash[j] > k) continue;
                for (auto cur : h[j])
                    if (j <= cur.l && cur.r <= i)
                        sum += cur.v;
                f[i + 1] = _max(f[i + 1], f[j] + sum - 1ll * d * (hash[i] - hash[j]));
            }
        }
        printf("%lld\n", f[len]);
    }
    std::cerr << 1.L * std::clock() / CLOCKS_PER_SEC << std::endl;
    return 0;
}