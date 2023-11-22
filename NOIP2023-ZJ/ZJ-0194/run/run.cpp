#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1010, M = 100010, inf = 0x3f3f3f3f;
int C, T, ans;
int n, m, k, d;
int x[M], y[M], c[M];
int f[N][N];
vector<pii> Gift[N];
void Max(int &x, int y) {
    if (x < y)
        x = y;
    return;
}
signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%lld%lld", &C, &T);
    for (int __ = 1; __ <= T; ++__) {
        ans = 0;
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for (int i = 1; i <= m; ++i)
            scanf("%lld%lld%lld", x + i, y + i, c + i);
        if (C <= 9) {
            for (int i = 1; i <= n; ++i)
                Gift[i].clear();
            for (int i = 1; i <= m; ++i)
                Gift[x[i]].push_back(mkp(y[i], c[i]));
            memset(f, 0, sizeof f);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    f[i][j] = f[i - 1][j - 1] - d;
                    for (pii x : Gift[i])
                        if (j >= x.first)
                            f[i][j] += x.second;
                }
                for (int j = 0; j <= k; ++j)
                    Max(f[i][0], f[i - 1][j]);
            }
            for (int i = 0; i <= k; ++i)
                Max(ans, f[n][i]);
            printf("%lld\n", ans);
        }
        else if (C == 17 || C == 18) {
            for (int i = 1; i <= m; ++i) {
                if (y[i] <= k)
                    ans += max(0ll, c[i] - d * y[i]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}