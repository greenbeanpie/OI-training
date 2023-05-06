#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[400010];
int num[400010];

signed main()
{
    memset(dp, 0xcf, sizeof(dp));
#ifndef ONLINE_JUDGE
    freopen("P1725_hack_1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    dp[0]=0;
    for (int i = 0; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i+l; j <= i+r; j++)
        {
            dp[j] = max(dp[j], dp[i] + num[j]);
        }
    }
    int maxinum = dp[n];
    for (int i = n-1 ; i > n - r; i--)
    {
        maxinum = max(maxinum, dp[i]);
    }
    cout << maxinum;
    return 0;
}
