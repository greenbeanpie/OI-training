#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, m, tag[N], col[N], cnt, now[N], flag, ans, vis[N], viss[N], visss[N];
vector< pair<int, int> > G[N];
queue<int> q;
int val[N];
vector<int> vec;

void ad(int x, int y, int z)
{
	G[x].emplace_back(y, z);
	G[y].emplace_back(x, z);
}

void add(int x)
{
	if (visss[x])
	return;
	visss[x] = 1;
	q.push(x);
}

void dfs(int x)
{
	if (vis[x])
	return;
	vis[x] = 1;
	if (now[col[x]] == x)
	{
		add(col[x]);
	}
	if (x <= n)
	{
		add(x);
	}
	for (auto i : G[x])
	{
		dfs(i.first);
	}
}

void dfss(int x, int _)
{
	if (val[x] != -1)
	{
		if (val[x] != _)
		{
			add(col[x]);
		}
	}
	if (vis[x])
	return;
	vis[x] = 1;
	val[x] = _;
	vec.push_back(x);
	for (auto i : G[x])
	{
		dfss(i.first, _ ^ i.second);
	}
}

void solve()
{
	ans = cnt = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		now[i] = i;
		++cnt;
		col[cnt] = i;
	}
	for (int i = 1;i <= m;i++)
	{
		char opt;
		cin >> opt;
		if (opt == '+' || opt == '-')
		{
			int x, y;
			cin >> x >> y;
			if (x == y)
			{
				ad(now[x], cnt + 1, opt == '-');
				now[x] = ++cnt;
				col[cnt] = x;
				continue;
			}
			now[x] = ++cnt;
			col[cnt] = x;
			ad(now[y], now[x], opt == '-');
			continue;
		}
		int x;
		cin >> x;
		if (opt != 'U')
		{
			now[x] = ++cnt;
			col[cnt] = x;
		}
		else
		{
			now[x] = ++cnt;
			col[cnt] = x;
			tag[cnt] = 1;
		}
	}
	for (int i = 1;i <= cnt;i++)
	val[i] = -1;
	for (int i = 1;i <= n;i++)
	if (now[i] != i && G[i].size() > 0)
	{
		ad(i, now[i], 0);
	}
	for (int i = n + 1;i <= cnt;i++)
	if (tag[i])
	{
		dfs(i);
	}
	for (int i = 1;i <= cnt;i++)
	vis[i] = 0;
	for (int i = 1;i <= n;i++)
	{
		vector<int>().swap(vec);
		dfss(i, 0);
		for (auto j : vec)
		{
			val[j] = -1;
		}
	}
	for (int i = 1;i <= cnt;i++)
	vis[i] = viss[i] = 0, val[i] = -1;
	while (!q.empty())
	{
		int o = q.front();
		q.pop();
		if (viss[o])
		continue;
		viss[o] = 1;
		if (o <= n)
		ans++;
		dfs(o);
	}
	for (int i = 1;i <= cnt;i++)
	{
		vis[i] = 0;
		tag[i] = 0;
		viss[i] = 0;
		visss[i] = 0;
		now[i] = 0;
		vector< pair<int, int> >().swap(G[i]);
	}
	cnt = 0;
	cout << ans << '\n';
}

signed main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int id, t;
	cin >> id >> t;
	while (t--)
	{
		solve();
	}
}
