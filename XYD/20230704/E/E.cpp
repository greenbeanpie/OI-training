#include <bits/stdc++.h>
using namespace std;
#define int long long
int wk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;
struct node
{
	int x, y, dis;
};
bool operator<(node a, node b)
{
	return a.dis < b.dis;
}
bool check(int x)
{
	if (x > 0 && x <= n)
	{
		return true;
	}
	return false;
}
signed main()
{

	while (cin >> n && n)
	{
		int mp[n + 1][n + 1];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> mp[i][j];
			}
		}
		pair<int, int> min_dis[n + 1][n + 1];
		memset(min_dis, 0x3f3f3f, sizeof(min_dis));
		priority_queue<node> q;
		q.push({0, 0, 0});
		while (!q.empty())
		{
			node now = q.top();
			q.pop();
			if (min_dis[now.x][now.y] <= now.dis)
			{
				continue;
			}
			min_dis[now.x][now.y].first = now.dis;
			for (int i = 0; i < 4; i++)
			{
				int tx = now.x + wk[i][0], ty = now.x + wk[i][1];
				if (check(tx) && check(ty))
				{
					if (min_dis[tx][ty].second > now.dis + mp[tx][ty])
					{
						min_dis[tx][ty].first = now.dis + mp[tx][ty];
						min_dis[tx][ty].second = 1;
					}
					else if(min_dis[tx][ty].second== now.dis + mp[tx][ty]){
						min_dis[tx][ty].second++;
					}
				}
			}
		}
	}
	return 0;
}