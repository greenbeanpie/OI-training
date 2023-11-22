#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
    r = 0; int ch = getchar(), f = 0;
    while (!isdigit(ch)) f ^= (ch == 45), ch = getchar();
    while (isdigit(ch)) (r *= 10) += ch - 48, ch = getchar();
    if (f) r = -r;
}

const int maxn = 3e3 + 5;
long long n, m, k, ans, __, _, d;
long long dp[maxn][maxn];
long long v[maxn][maxn];

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    read(__); read(_);
    while (_--) {
        memset(v, 0, sizeof v);
        read(n); read(m); read(k); read(d);
        for (int i = 1; i <= m; i++) {
            int x, y, z; read(x); read(y); read(z);
            if (y > k) continue;
            v[x][y] += z;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                v[i][j] += v[i][j - 1];
            }
        }
        memset(dp, 0xcf, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            }
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j - 1] + v[i][j] - d;
            }
        }
        ans = 0xcfcfcfcfcfcfcfcf;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, dp[n][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}