#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P3859.in", "r", stdin);
    freopen("P3859.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int r[m], v[m], t[m], close[n];

    for (int i = 0; i < n; i++)
    {
        cin >> close[i];
    }
    for (int i = 1; i < n; i++)
    {
        close[i] = min(close[i], close[i - 1]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> r[i] >> v[i] >> t[i];
    }
    if (close[0] == 0)
    {
        cout << 0;
        return 0;
    }
    int dp[close[0]] = {0};
    for (int i = 1; i < close[0]; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j < m; j++)
        {

            if (close[r[j]] > i && t[j] <= i)
            {
                dp[i] = max(dp[i], dp[i - t[j]] + v[j]);
            }
        }
    }
    cout << dp[close[0] - 1];

    return 0;
}