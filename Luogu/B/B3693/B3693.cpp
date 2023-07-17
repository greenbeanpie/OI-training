#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 1e3 + 5;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B3693.in", "r", stdin);
    freopen("B3693.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int sum[N][N];
        memset(sum,0,sizeof(sum));
        int n, m, q;
        cin >> n >> m >> q;
        int t;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> t;
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + t;
            }
        }
        int u, v, x, y, ans = 0;
        for (int i = 1; i <= q; i++)
        {
            cin >> u >> v >> x >> y;
            ans ^= (sum[x][y] - sum[x][v - 1] - sum[u - 1][y] + sum[u - 1][v - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}