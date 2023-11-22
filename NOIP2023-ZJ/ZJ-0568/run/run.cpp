#include <bits/stdc++.h>

template<class T>
void read(T & x) {
    x = 0;
    bool f = false;
    char c = getchar();
    while (!isdigit(c)) f |= (c == '-'), c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    x = (f ? -x : x);
}

void read(std::string & x) {
    x = "";
    char c = getchar();
    while (!isgraph(c)) c = getchar();
    while (isgraph(c)) x += c, c = getchar();
}

using ll = long long;

constexpr int N = 1e3 + 10;

int n, m, k, d;

std::vector<std::pair<int, int>> a[N];
ll f[N][N];

signed main() {
    std::freopen("run.in", "r", stdin);
    std::freopen("run.out", "w", stdout);

    int test_case, T;
    read(test_case);
    read(T);

    while (T --) {
        read(n);
        read(m);
        read(k);
        read(d);

        for (int i = 1; i <= n; ++ i) {
            a[i].clear();
        }

        for (int i = 1; i <= m; ++ i) {
            int x, y, z;
            read(x);
            read(y);
            read(z);
            a[x].emplace_back(y, z);
        }

        // for (const auto & t : a[4]) {
        //     printf("%d %d\n", t.first, t.second);
        // }
        // puts("");

        std::memset(f, 0, sizeof(f));

        f[0][0] = 0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = std::min(i - 1, k); j >= 0; -- j) {
                f[i][0] = std::max(f[i][0], f[i - 1][j]);
            }
            for (int j = std::min(i, k); j >= 1; -- j) {
                f[i][j] = f[i - 1][j - 1] - d;
            }

            for (const auto & t : a[i]) {
                for (int j = t.first; j <= std::min(i, k); ++ j) {
                    f[i][j] += t.second;
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i <= k; ++ i) {
            ans = std::max(ans, f[n][i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3

*/
/*
2
*/
