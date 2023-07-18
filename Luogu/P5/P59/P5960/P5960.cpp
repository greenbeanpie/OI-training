#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

const int N = 5e3 + 5;
struct node
{
	int to, val;
};
bool operator<(node a, node b)
{
	return a.val < b.val;
}
vector<node> e[N];
int dis[N], vis[N], n, m;
extern bool spfa();

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P5980.in", "r", stdin);
	freopen("P5980.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int u, v, val;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> val; // x_{c1}-x_{c2} \le y_1 = x_{c1} \le y_1+x_{c2}
		e[v].push_back({u, val});
	}
	for (int i = 1; i <= n; i++)
	{
		e[0].push_back({i, 0});
	}
	memset(dis, 0x3f3f3f, sizeof(dis));
	spfa();
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}

	return 0;
}

bool spfa()
{
	queue<node> q;
	q.push({0, -1});
	dis[0] = 0;
	vis[0] = 1;
	while (!q.empty())
	{
		
		auto now = q.front();
		vis[now.to]=0;
		if (now.val >= n)
		{
			cout << "NO";
			exit(0);
		}
		q.pop();
		for (auto i : e[now.to])
		{
			if (dis[i.to] > dis[now.to] + i.val)
			{
				dis[i.to] = dis[now.to] + i.val;
				if (!vis[i.to])
				{
					vis[i.to]=1;
					q.push({i.to, now.val + 1});
				}
			}
		}
	}
	return 1;
}