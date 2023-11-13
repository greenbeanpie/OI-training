#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct side
{
	int from, to, val;
	side(int a, int b, int c)
	{
		from = a, to = b, val = c;
	}
};

struct node
{
	int lson, rson, fa, cost, val;
};

bool operator<(const side &a, const side &b)
{
	return a.val < b.val;
}

bool operator>(const side &a, const side &b)
{
	return a.val > b.val;
}

const int N = 1e5 + 5;

int fa[N << 2], f[N << 2][22];

int find(int x)
{
	assert(x);
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector<side> e[N];

node t[N << 2];

int n, m, q, val[N];

__gnu_pbds::priority_queue<side, greater<side>> pq;

int tot = n;

void kruskal() // 难蚌，最小生成树都不会写还写重构树。
{
	pq.clear();
	for (int i = 1; i <= n * 2+1; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		t[i].val = val[i];

	}
	for (int i = 1; i <= n; i++)
	{
		for (auto i : e[i])
		{
			pq.push(i);
		}
	}
	int cnt = 0;
	while (cnt < n - 1 && pq.size())
	{
		auto now = pq.top();
		pq.pop();
		int fx = find(now.from), fy = find(now.to);
		if (fx == fy)
		{
			continue;
		}
		t[fx].fa = t[fy].fa = ++tot;
		t[tot].lson = fx, t[tot].rson = fy;
		fa[fx] = fa[fy] = tot;
		++cnt;
		t[tot].cost = max(now.val, max(t[fx].cost, t[fy].cost));
		t[tot].val = t[fx].val + t[fy].val;
	}
}

void prework()
{
	for (int i = 1; i <= tot+1; i++)
	{
		f[i][0] = t[i].fa;
	}
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j < n * 2; j++)
		{
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
}

int solve(int u, int k)
{
	// int ans = 0;
	for (int i = 20; i >= 0; i--)
	{
		if (f[u][i] && t[u].val + k >= t[f[u][i]].cost)
		{
			u = f[u][i];
			i = 20;
		}
	}
	return t[u].val + k;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
	// #ifndef CODESPACE
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// #endif
	// int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	for (int i = 1, u, v, w; i <= m; i++)
	{
		cin >> u >> v >> w;
		e[u].emplace_back(u, v, w);
		e[v].emplace_back(v, u, w);
	}
	tot = n;
	kruskal();
	prework();
	for (int i = 1; i <= q; i++)
	{
		int k, x;
		cin >> k >> x;
		cout << solve(k, x) << endl;
	}
	return 0;
}
