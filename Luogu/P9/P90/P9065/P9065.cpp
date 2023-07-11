#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mp[3005][3005], dis[3005][3005];
pair<int, int> p[9000005];
int n, m, k;
int wk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool check(int x, int y)
{
	if (x < 1 || y < 1 || x > n || y > m || mp[x][y] == 0)
	{
		return false;
	}
	return true;
}

int myhash(int x, int y)
{
	return x * 3001 + y;
}
int myhash(pair<int, int> p)
{
	return p.first * 3001 + p.second;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("dream4.in", "r", stdin);
	freopen("P9065.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	unordered_set<int> s;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
		}
	}
	int x, y;
	if(mp[1][1]==0){
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> x >> y;
		p[i] = {x, y};
		s.insert(myhash(x, y));
	}
	queue<pair<int, int>> q;
	q.push({1, 1});
	bool flag = true;
	memset(dis, 0x3f3f3f, sizeof(dis));
	dis[1][1] = 0;
	while (q.size())
	{
		auto now = q.front();
		q.pop();
		for (int i = 0; i <= 3; i++)
		{
			int tx = now.first + wk[i][0], ty = now.second + wk[i][1];
			if (check(tx, ty) && dis[tx][ty] > dis[now.first][now.second] + 1)
			{
				dis[tx][ty] = dis[now.first][now.second] + 1;
				q.push({tx, ty});
			}
		}
		if (flag && s.count(myhash(now)))
		{
			flag = false;
			for (int i = 1; i <= k; i++)
			{
				int tx = p[i].first, ty = p[i].second;
				if (mp[tx][ty])
				{
					if (mp[tx][ty] != mp[now.first][now.second] && dis[now.first][now.second] + 2 < dis[tx][ty])
					{
						dis[tx][ty] = dis[now.first][now.second] + 2;
						q.push({tx, ty});
					}
					else if(mp[tx][ty] == mp[now.first][now.second] && dis[now.first][now.second] + 1 < dis[tx][ty]){
						dis[tx][ty] = dis[now.first][now.second] + 1;
						q.push({tx, ty});
					}
				}
			}
		}
	}
	cout << ((dis[n][m]>9000000)?-1:dis[n][m]);
	return 0;
}