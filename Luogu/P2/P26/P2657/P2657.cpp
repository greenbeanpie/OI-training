#include <bits/stdc++.h>
using namespace std;
#define int long long

int count(int n)
{
    int dp[10][10];
    for (int i = 0; i < 9; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < ceil(log10(r)); i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; j <= 9; k++)
            {
                if (abs(j - k) >= 2)
                {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P2657.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin >> l >> r;

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += dp[(int)(ceil(log10(b)))]
    }
    return 0;
}