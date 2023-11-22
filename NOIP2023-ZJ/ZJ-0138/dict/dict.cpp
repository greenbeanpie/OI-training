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

constexpr i32 N = 3003;

i32 n, m;
Vec<Str> hash;
Arr<Str, N> a, b;
Arr<i32, 2 * N> cnt;

i32 main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    std::cin >> n >> m;
    for (i32 i = 1; i <= n; i++) {
        std::cin >> a[i];
        Arr<i32, 26> cur {};
        for (i32 j = 0; j < m; j++) cur[a[i][j] - 'a']++;
        a[i] = "";
        for (i32 j = 0; j < 26; j++)
        for (i32 k = 0; k < cur[j]; k++)
            a[i] += 'a' + j;
        b[i] = a[i];
        std::reverse(b[i].begin(), b[i].end());
        hash.push_back(a[i]);
        hash.push_back(b[i]);
    }
    std::sort(hash.begin(), hash.end());
    hash.resize(std::unique(hash.begin(), hash.end()) - hash.begin());
    for (i32 i = 1; i <= n; i++) {
        i32 p = std::lower_bound(hash.begin(), hash.end(), b[i]) - hash.begin() + 1;
        cnt[p]++;
    }
    for (i32 i = hash.size(); i >= 1; i--) cnt[i - 1] += cnt[i];
    for (i32 i = 1; i <= n; i++) {
        i32 p = std::lower_bound(hash.begin(), hash.end(), a[i]) - hash.begin() + 1;
        bool flag = true;
        for (i32 j = 1; j < m; j++) flag &= a[i][j - 1] == a[i][j];
        i32 cur = cnt[p + 1];
        cur -= !flag;
        printf("%d", cur == n - 1 ? 1 : 0);
    }
    std::cerr << 1.L * std::clock() / CLOCKS_PER_SEC << std::endl;
    return 0;
}