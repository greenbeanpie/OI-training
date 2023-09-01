#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P1171"
#define const constexpr

int dp[(1 << 21)][21];
int dis[21][21];
signed main()
{
#ifndef ONLINE_JUDGE
    freopen(problemname ".in", "r", stdin);
    freopen(problemname ".out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
        }
    }
    memset(dp, 0x3f3f3f, sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[1 + (1 << (i - 1))][i] = dis[1][i];
    }
    for (int i = 1; i <= (1 << n) - 1; i += 2)
    {
        for (int j = 0; j <= n; j++)
        {
            if ((i & (1 << (j - 1))) == 0)
            {
                continue;
            }
            for (int k = 1; k <= n; k++)
            {
                if ((i & (1 << (k - 1))) == 0)
                {
                    continue;
                }
                if (j == k)
                {
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[i ^ (1 << (j - 1))][k] + dis[k][j]);
            }
        }
    }
    int mininum = INT_MAX;
    for (int i = 2; i <= n; i++)
    {
        mininum = min(mininum, dp[(1 << n) - 1][i] + dis[i][1]);
    }
    cout << mininum << endl;
    return 0;
    return 0;
}