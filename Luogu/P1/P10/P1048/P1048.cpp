#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int c, v;
};
bool cmp(node a, node b)
{
    return a.v < b.v;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1048.in", "r", stdin);
#endif
    int n, t;
    scanf("%lld %lld", &t, &n);
    node d[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &(d[i].v), &(d[i].c));
    }
    sort(d, d + n, cmp);
    int dp[t + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = t; j >= d[i].v; j--)
        {
            dp[j] = max(dp[j], dp[j - d[i].v] + d[i].c);
        }
    }
    cout << dp[t];
    return 0;
}