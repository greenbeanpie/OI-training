#include<bits/stdc++.h>
using namespace std;

int c, T;
int n, m, k, d;
int last;
long long dp[1005][1005];

struct task
{
	long long x, y, v;
	const bool operator < (const task a) const
	{
		return x < a.x;
	}
}a[100005];

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> m >> k >> d;
		memset(dp, -63, sizeof(dp));
		for (int i = 0; i <= n; i++)
		{
			dp[i][0] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].v;
		}
		sort(a + 1, a + m + 1);
		int len = 1;
		for (int time = 1; time <= n; time++)
		{
			for (int i = 0; i <= k; i++)
			{
				if (i >= time) break;
				dp[time][0] = max(dp[time][0], dp[time - 1][i]);
			}
			for (int i = 1; i <= k; i++)
			{
				if (i > time) break;
				dp[time][i] = max(dp[time][i], dp[time - 1][i - 1] - d);
			}
			while (time == a[len].x)
			{
				for (int i = a[len].y; i <= k; i++)
				{
					dp[time][i] += a[len].v;
				}
				len++;
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				if (j > i) break;
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
