#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
ll dp[1005][1005], rew[1005][1005];
int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t, n, m, k, d, t1, t2, t3;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for(int i = 0; i <= n + 1; i++)
			for(int j = 0; j <= n; j++)
				dp[i][j] = -2e18, rew[i][j] = 0;
		for(int i = 1; i <= m; i++)
			scanf("%d%d%d", &t1, &t2, &t3), rew[t1][t2] += t3;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				rew[i][j] += rew[i][j - 1];
		dp[0][0] = 0;
		for(int i = 1; i <= n + 1; i++)
		{
			for(int j = 0; j <= k; j++)
				dp[i][0] = max(dp[i][0], dp[i - 1][j]);
			for(int j = 1; j <= k; j++)
				dp[i][j] = dp[i - 1][j - 1] - d + rew[i][j];
		}
		printf("%lld\n", dp[n + 1][0]);
	}
	return 0;
}