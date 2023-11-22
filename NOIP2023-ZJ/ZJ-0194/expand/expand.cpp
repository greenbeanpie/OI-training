#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int C, n, m, q;
int a[N], b[N], aa[N], bb[N];
bool dp[N][N];
bool Dp() {
    if (a[1] == b[1] || a[n] == b[m])
        return 0;
    if (a[1] > b[1] && a[n] < b[m] || a[1] < b[1] && a[n] > b[m])
        return 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = 0;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[1] > b[1]) {
                if (a[i + 1] > b[j])
                    dp[i + 1][j] |= dp[i][j];
                if (a[i] > b[j + 1])
                    dp[i][j + 1] |= dp[i][j];
            }
            else {
                if (a[i + 1] < b[j])
                    dp[i + 1][j] |= dp[i][j];
                if (a[i] < b[j + 1])
                    dp[i][j + 1] |= dp[i][j];
            }
        }
    return dp[n][m];
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &C, &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), aa[i] = a[i];
    for (int i = 1; i <= m; ++i)
        scanf("%d", b + i), bb[i] = b[i];
    putchar(Dp() + '0');
    for (int __ = 1, k1, k2, pos, val; __ <= q; ++__) {
        scanf("%d%d", &k1, &k2);
        for (int i = 1; i <= k1; ++i) {
            scanf("%d%d", &pos, &val);
            a[pos] = val;
        }
		for (int i = 1; i <= k2; ++i) {
            scanf("%d%d", &pos, &val);
            b[pos] = val;
        }
        putchar(Dp() + '0');
        for (int i = 1; i <= n; ++i)
            a[i] = aa[i];
        for (int i = 1; i <= m; ++i)
            b[i] = bb[i];
    }
    return 0;
}