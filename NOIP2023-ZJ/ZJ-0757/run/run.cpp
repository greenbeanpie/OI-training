#include <bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        int y[100005], v[100005];
        int n, m, k, d;
        scanf("%d%d%d%d", &n, &m, &k, &d);
        int dp[100000];
        int dps[100000];
        for (int i = 1; i <= m; i++)
        {
            int x2;
            scanf("%d", &x2);
            scanf("%d%d", &y[x2], &v[x2]);
        }
        for (int i = 1; i <= n; i++)
        {
            int ti = 0;
            if (y[i] != 0)
            {
                if (i >= y[i])
                {
                    if (y[i] <= k)
                    {
                        dp[i] = max(dp[i - y[i]] + v[i]-y[i]*d, dp[i - 1]);
                    }
                    else
                    {
                        int os = y[i] % (k + 1) + (y[i] / (k + 1)) * (k + 1);
                        if (os <= i)
                        {
                            dp[i] = max(dp[i - os] + v[i]-os*d, dp[i - 1]);
                        }
                    }
                }
            }
        }
        printf("%d\n", dp[n]);
    }
}