#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1049.in", "r", stdin);
#endif
    int n, t;
    scanf("%lld %lld", &t, &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", v+i);
    }
    sort(v,v+n);
    int dp[t + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = t; j >=v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    cout << t-dp[t];
    return 0;
}