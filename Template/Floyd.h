#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
int dis[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	// fill(dis[0], dis[0] + 105 * 105, INT_MAX);
	memset(dis, 0x3f3f3f, sizeof(dis));
	for (int i = 1, u, v, val; i <= m; i++)
	{
		cin >> u >> v >> val;
		dis[u][v] = dis[v][u] = val;
	}
	for (int i = 1; i <= n;i++){
		dis[i][i] = 0;
	}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					dis[j][k] = dis[k][j] = min(dis[j][k], dis[j][i] + dis[i][k]);
				}
			}
		}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}