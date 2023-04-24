#include <bits/stdc++.h>
using namespace std;
#define int long long
#define map unordered_map
#define multimap unordered_multimap

int p2[100005], n;
int LIS()
{
    int dp[100005] = {0}, ans = 0, cnt = 1;
    dp[0] = -1;
    dp[1] = p2[0];
    for (int i = 1; i < n; i++)
    {
        int temp = lower_bound(dp, dp + cnt, p2[i]) - dp;
        if (temp == cnt)
        {
            if (dp[cnt] > p2[i])
            {
                dp[cnt] = min(dp[cnt], p2[i]);
            }
            else
            {
                dp[++cnt] = p2[i];
            }
        }
        else{
            dp[temp]=min(dp[temp],p2[i]);
        }
    }

    
    return cnt;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1439_1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> n;
    int p1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p2[i];
    }
    int m[n];
    for (int i = 0; i < n; i++)
    {
        m[p1[i]] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        p2[i] = m[p2[i]];
    }
    cout << LIS();
    return 0;
}