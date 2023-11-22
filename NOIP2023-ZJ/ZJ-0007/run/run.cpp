#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int c, t;
ll n, m, k, d, a[2010][2010], f[2010][2010], F[2010];

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    if (c == 17 || c == 18) {
        while (t--) {
            cin >> n >> m >> k >> d;
            ll ans = 0;
            for (int i = 1; i <= m; i++) {
                ll x, y, v;
                cin >> x >> y >> v;
                if (y <= k)
                    ans += max(0ll, v - y * d);
            }
            cout << ans << endl;
        }
        return 0;
    }
    while (t--) {
        cin >> n >> m >> k >> d;
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        memset(F, 0, sizeof F);
        for (int i = 1; i <= m; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            a[x][y] += v;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < k; j++)
                a[i][j + 1] += a[i][j];
        for (int i = 1; i <= k; i++)
            for (int j = i; j <= n; j++)
                f[j][i] = f[j - 1][i - 1] + a[j][i] - d;
        F[0] = 0;
        F[1] = max(f[1][1], 0ll);
        for (int i = 2; i <= n; i++) {
            F[i] = F[i - 1];
            for (int j = 1; j <= k && j <= i; j++) {
                if (i > j)
                    f[i][j] += F[i - j - 1];
                F[i] = max(F[i], f[i][j]);
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, F[i]);
        cout << ans << endl;
    }
    return 0;
}