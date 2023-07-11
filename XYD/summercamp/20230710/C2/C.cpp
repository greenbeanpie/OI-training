#include <bits/stdc++.h>

const int N = 1005;
const int M = 205;
const int MOD = 1e9 + 7;

int n, m, k, v = 1;
int f[2][M][M][2];
char a[N], b[M];

int add(int x, int y)
{
	return (x += y) >= MOD ? x -= MOD : x;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", a + 1, b + 1);

	f[0][0][0][0] = f[1][0][0][0] = 1;
	for (int i = 1; i <= n; ++i, v ^= 1)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int p = 1; p <= k; ++p)
			{
				if (a[i] == b[j])
				{
					f[v][j][p][0] = add(f[v ^ 1][j][p][0], f[v ^ 1][j][p][1]);
					f[v][j][p][1] = add(f[v ^ 1][j - 1][p][1],
										add(f[v ^ 1][j - 1][p - 1][0], f[v ^ 1][j - 1][p - 1][1]));
				}
				else
				{
					f[v][j][p][0] = add(f[v ^ 1][j][p][0], f[v ^ 1][j][p][1]);
					f[v][j][p][1] = 0;
				}
			}
		}
	}

	printf("%d\n", add(f[n & 1][m][k][0] , f[n & 1][m][k][1]));
	return 0;
}