#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long

const int N = 1e5 + 5;

struct node
{
	int to, val;
	node(int a, int b)
	{
		to = a, val = b;
	}
	node()
	{
		to = val = 0;
	}
};

bool operator>(node a, node b)
{
	return a.val > b.val;
}

vector<node> e[N];

int dis[N];

__gnu_pbds::priority_queue<node, greater<node>> q;

bitset<N> vis;

void dijkstra(int u)
{
	q.push({u, 0});
	while (q.size())
	{
		auto now = q.top();
		q.pop();
		if (vis[now.to])
		{
			continue;
		}
		vis[now.to] = 1;
		dis[now.to] = min(dis[now.to], now.val);
		for (auto i : e[now.to])
		{
			if (dis[now.to] + i.val < dis[i.to])
			{
				dis[i.to] = dis[now.to] + i.val;
				if (!vis[i.to])
				{
					q.push({i.to, dis[i.to]});
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 1, u, v, val; i <= m; i++)
	{
		cin >> u >> v >> val;
		e[u].emplace_back(v, val);
		// e[v].emplace_back(u, val);
	}
	// memset(dis, 0x3f3f3f, sizeof(dis));
	fill(dis + 1, dis + n + 1, LLONG_MAX>>1);
	dis[s] = 0;
	dijkstra(s);
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	return 0;
}