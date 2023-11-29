#include <bits/stdc++.h>
using namespace std;

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

const int N = 3e3 + 5;

vector<node> e[N];

queue<node> q;

int cnt[N];

bitset<N> vis;

int dis[N];

bool spfa(int u)
{
	vis.reset();
	memset(dis, 0x3f3f3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[u] = 0;
	q.emplace(1, 0);
	while (q.size())
	{
		auto now = q.front();
		q.pop();
		vis[now.to] = 0;
		// ++cnt[now.to];
		for (auto i : e[now.to])
		{
			if (dis[now.to] + i.val < dis[i.to])
			{

				dis[i.to] = dis[now.to] + i.val;
				if (!vis[i.to])
				{
					if (++cnt[i.to] > N)
					{
						return 1;
					}
					vis[i.to] = 1;
					q.emplace(i.to, dis[i.to]);
				}
			}
		}
	}
	return 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			e[i].clear();
		}
		queue<node> q1;
		swap(q, q1);
		for (int i = 1, u, v, val; i <= m; i++)
		{
			cin >> u >> v >> val;
			if (val >= 0)
			{
				e[u].emplace_back(v, val);
				e[v].emplace_back(u, val);
			}
			else
			{
				e[u].emplace_back(v, val);
			}
		}
		cout << (spfa(1) ? "YES" : "NO") << endl;
	}
	return 0;
}