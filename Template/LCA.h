#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

vector<int> e[N];
int f[N][21], dep[N];

int n, m, s;

void dfs(int u, int d = 1, int fa = 0)
{
	dep[u] = d;
	f[u][0] = fa;
	for (int i : e[u])
	{
		if (i != fa)
		{
			dfs(i, d + 1, u);
		}
	}
}

void prework(int u)
{
	dfs(u);
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
}

int LCA(int u, int v)
{
	if (dep[u] < dep[v])
	{
		swap(u, v);
	}
	if (dep[u] > dep[v])
	{
		for (int i = 20; i >= 0; i--)
		{
			if (dep[v] <= dep[f[u][i]])
			{
				u = f[u][i];
			}
		}
	}

	if (u == v)
	{
		return u;
	}

	for (int i = 20; i >= 0; i--)
	{
		if (f[u][i] != f[v][i])
		{
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1, u, v; i < n; i++)
	{
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	prework(s);
	for (int i = 1, u, v; i <= m; i++)
	{
		cin >> u >> v;
		cout << LCA(u, v) << endl;
	}
	return 0;
}