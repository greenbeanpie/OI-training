#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> e[2505];
int n, m, k;
int maxinum[2505][6];
int dis[2505][2505];
void walk(int start)
{
	queue<pair<int, int>> q;
	q.push({start, -1});
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();
		if (now.second == k)
		{
			break;
		}
		for (auto i : e[now.first])
		{
			if (dis[start][i] == -1)
			{
				q.push({i, now.second + 1});
				dis[start][i] = now.second + 1;
			}
		}
	}
}
int val[2505];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("holiday3.in", "r", stdin);
	freopen("holiday3.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis, -1, sizeof(dis));
	cin >> n >> m >> k;

	for (int i = 2; i <= n; i++)
	{
		cin >> val[i];
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		walk(i);
	for (int i = 2; i <= n; i++)
	{
		int max1 = -1, max2 = -1, max3 = -1, max4 = -1, max5 = -1, max6 = -1;
		for (int j = 2; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			else if ((max1 == -1 || val[j] >= val[max1]) && dis[i][j] != -1)
			{
				max6 = max5;
				max5 = max4;
				max4 = max3;
				max3 = max2;
				max2 = max1;
				max1 = j;
			}
			else if ((max2 == -1 || val[j] >= val[max2]) && dis[i][j] != -1)
			{
				max6 = max5;
				max5 = max4;
				max4 = max3;
				max3 = max2;
				max2 = j;
			}
			else if ((max3 == -1 || val[j] >= val[max3]) && dis[i][j] != -1)
			{
				max6 = max5;
				max5 = max4;
				max4 = max3;
				max3 = j;
			}
			else if ((max4 == -1 || val[j] >= val[max4]) && dis[i][j] != -1)
			{
				max6 = max5;
				max5 = max4;
				max4 = j;
			}
			else if ((max5 == -1 || val[j] >= val[max5]) && dis[i][j] != -1)
			{
				max6 = max5;
				max5 = j;
			}
			else if ((max6 == -1 || val[j] >= val[max6]) && dis[i][j] != -1)
			{
				max6 = j;
			}
		}
		maxinum[i][0] = max1;
		maxinum[i][1] = max2;
		maxinum[i][2] = max3;
		maxinum[i][3] = max4;
		maxinum[i][4] = max5;
		maxinum[i][5] = max6;
	}
	int maxroad = -1;
	for (int i = 2; i < n; i++)
	{
		if (dis[1][i] == -1)
		{
			continue;
		}
		for (int j = i + 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (dis[1][j] == -1)
			{
				continue;
			}
			for (int a = 0; a < 6; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					int max1 = maxinum[i][a], max2 = maxinum[j][b];
					if (max1 == -1 || max2 == -1 || max1 == i || max1 == j || max2 == i || max2 == j || max1 == max2 || dis[max1][max2] == -1)
					{
						continue;
					}

					maxroad = max(maxroad, val[i] + val[j] + val[max1] + val[max2]);
				}
			}
		}
	}
	cout << maxroad;
	return 0;
}