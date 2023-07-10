#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[20], c[20][20];
int popcount(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n & 1)
		{
			cnt++;
		}
		n >>= 1;
	}
	return cnt;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P4941.in", "r", stdin);
	freopen("P4941.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int dp[1 << n][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int x, y, t;
	for (int i = 1; i <= k; i++)
	{
		cin >> x >> y >> t;
		if (x == y)
		{
			a[x] += t;
		}
		else
		{
			c[x][y] += t;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[1 << (i - 1)][i] = a[i];
		ans = max(ans, dp[1 << (i - 1)][i]);
	}

	for (int i = 1; i <= (1 << n) - 1; i++)
	{
		int t = popcount(i);
		if (t > m || t == 1)
		{
			continue;
		}
		for (int j = 1; j <= n; j++)
		{
			if ((i & (1 << (j - 1))) == 0)
			{
				continue;
			}
			for (k = 1; k <= n; k++)
			{
				if (i & (1 << (k - 1)) && j != k)
				{
					dp[i][j] = max(dp[i][j], dp[i - (1 << (j - 1))][k] + c[k][j] + a[j]);
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}