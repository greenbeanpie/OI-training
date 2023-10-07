#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 30, M = 60;

int n, m;

struct Solver
{
	int w[N + 5][M + 5];
	int dp[2][N + 5][N + 5][M + 5][M + 5];

	void read()
	{
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++)
				scanf("%d", &w[i][j]);
		return ;
	}
	void update(int& x, int y)
	{
		x = max(x, y);
		return ;
	}
	void solve()
	{
		memset(dp, -0x3f, sizeof(dp));
		dp[0][0][0][0][0] = 0;
		for (int i = 0; i < n; i++)
		{
			int p = (i & 1) ^ 1;
			memset(dp[p], -0x3f, sizeof(dp[p]));
			for (int x1 = 0; x1 <= n; x1++)
			for (int x2 = 0; x2 <= x1; x2++)
			for (int x3 = 0; x3 <= m - x1; x3++)
			for (int x4 = 0; x4 <= x3; x4++)
			{
				int val = dp[i & 1][x1][x2][x3][x4];
				if (val < 0)
					continue;
				for (int deg = 0; deg <= m - x1 - x3; deg++)
				{
					if (deg)
						update(dp[(i & 1) ^ 1][x1 + 1][x2][x3 + deg - 1][x4], 
							val + w[i + 1][deg]);
					
					if (deg)
						update(dp[(i & 1) ^ 1][x1 + 1][x2 + 1][x3 + deg - 1][x4 + deg - 1], 
							val + w[i + 1][deg]);

					update(dp[(i & 1) ^ 1][x1][x2][x3 + deg][x4], 
						val + w[i + 1][deg]);
				}
			}
		}
		return ;
	}
	int get(int x1, int x2, int x3, int x4)
	{
		return dp[n & 1][x1][x2][x3][x4];
	}
} dp[2];

int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 2; i++)
		dp[i].read();
	
	for (int i = 0; i < 2; i++)
		dp[i].solve();

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;

		int x1 = i, y1 = i;
		for (int x2 = 0, y2 = i; x2 <= i; x2++, y2--)
		for (int x3 = 0, y3 = 0; x3 <= m - i; x3++, y3++)
		for (int x4 = 0; x4 <= x3; x4++)
		for (int y4 = 0; y4 <= y3; y4++)
		{
			if (x3 > min(x4 + y4, m - i))
				continue;
			ans = max(ans, dp[0].get(x1, x2, x3, x4) + dp[1].get(y1, y2, y3, y4));
		}

		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}
