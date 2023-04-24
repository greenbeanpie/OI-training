#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B1274.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int num[n + 1];
    num[0]=0;
    int sum[n + 1][n + 1];
    int dp[n+1][n+1];
    memset(sum,0,sizeof(sum));
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum[1][i] = sum[1][i - 1] + num[i];
        dp[i][i] = 0;
        for (int j = 2; j <= i; j++)
        {
            sum[j][i] = sum[1][i] - sum[1][j - 1];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; i + j - 1 <= n; j++)
        {
            int e = i + j - 1;
            for (int k = j; k < e; k++)
            {
                dp[j][e] = min(dp[j][e], dp[j][k] + sum[j][k] + dp[k + 1][e] + sum[k + 1][e]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}