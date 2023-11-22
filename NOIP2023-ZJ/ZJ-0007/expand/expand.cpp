#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int c, n, m, q;
int a[N], b[N], A[N], B[N], f[2010][2010];

inline bool solve() {
    if (1ll * (a[1] - b[1]) * (a[n] - b[m]) <= 0)
        return 0;
    if (c > 7) return 1ll * (a[1] - b[1]) * (a[n] - b[m]) > 0;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (1ll * (a[i] - b[j]) * (a[1] - b[1]) > 0)
                f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
    return f[n][m];
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i], A[i] = a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i], B[i] = b[i];
    cout << solve();
    while (q--) {
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
            a[i] = A[i];
        for (int i = 1; i <= m; i++)
            b[i] = B[i];
        int ka, kb; cin >> ka >> kb;
        while (ka--) {
            int p, v; cin >> p >> v;
            a[p] = v;
        }
        while (kb--) {
            int p, v; cin >> p >> v;
            b[p] = v;
        }
        cout << solve();
    }
    cout << endl;
    return 0;
}