#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#endif
#define int long long
#define endl "\n"

struct side
{
	int u, v, l, a, nxt;
};
struct node
{
	int u, v, val;
};
struct leaf
{
	int lson, rson, father, a, l;
};
struct cmpl
{
	bool operator()(node a, node b)
	{
		return a.val > b.val;
	}
};
struct cmpa
{
	bool operator()(side a, side b)
	{
		return a.a < b.a;
	}
};

int T, n, m, u, v, l, a;
int head[2000005], f[2000005][21], mindis[2000005], fa[2000005 * 2];
vector<side> e;
vector<leaf> Tree;
extern void add_edge(int u, int v, int l, int a);
extern void dijkstra(), kruskal();
extern int find(int u);
extern void merge(int u, int v);
extern void dfs(int u = Tree.size() - 1, int dep = 0);
extern int solve(int v, int p);

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("return5.in", "r", stdin);
	freopen("return5.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
	{
		e.clear();
			e.push_back({-1, -1, -1, -1});
		int lastans = 0, q, k, s;
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v >> l >> a;
			add_edge(u, v, l, a);
			add_edge(v, u, l, a);
		}
		cin >> q >> k >> s;
		dijkstra();
		kruskal();
		dfs();
		if (q == 0 || m == 0)
		{
			continue;
		}
		int v, p;
		for (int i = 1; i <= q; i++)
		{
			cin >> v >> p;
			v = (v + k * lastans - 1) % n + 1;
			p = (p + k * lastans) % (s + 1);
			cout << (lastans = solve(v, p)) << endl;
		}
		if (T)
		{
			memset(f, 0, sizeof(f));
			memset(head, -1, sizeof(head));
		}
	}
	return 0;
}
void add_edge(int u, int v, int l, int a)
{
	side now = {u, v, l, a, head[u]};
	head[u] = e.size();
	e.push_back(now);
}
void dijkstra()
{
	bool vis[2000005] = {0};
	fill(mindis, mindis + n + 1, INT_MAX);
	mindis[0] = mindis[1] = 0;
	vis[0] = 1;
	__gnu_pbds::priority_queue<node, cmpl> q;
	q.push({0, 1, 0});
	while (q.size())
	{
		auto now = q.top();
		q.pop();
		if (now.val > mindis[now.v] || vis[now.v])
		{
			continue;
		}
		mindis[now.v] = now.val;
		vis[now.v] = 1;
		for (int i = head[now.v]; i > 0; i = e[i].nxt)
		{
			if (mindis[e[i].u] + e[i].l < mindis[e[i].v])
			{
				mindis[e[i].v] = mindis[e[i].u] + e[i].l;
				q.push({e[i].u, e[i].v, mindis[e[i].v]});
			}
		}
	}
}
void kruskal()
{
	Tree.clear();
	Tree.push_back({-1, -1, -1});
	for (int i = 1; i <= n * 2; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		Tree.push_back({0, 0, 0, INT_MAX, mindis[i]});
	}
	__gnu_pbds::priority_queue<side, cmpa> q;
	for (auto i : e)
	{
		q.push(i);
	}
	q.pop();
	int tot = 0;
	while (tot < n - 1)
	{
		auto now = q.top();
		q.pop();
		now.v = find(now.v);
		now.u = find(now.u);
		if (now.v == now.u)
		{
			continue;
		}
		merge(now.u, Tree.size());
		merge(now.v, Tree.size());
		leaf temp;
		temp.lson = now.u;
		temp.rson = now.v;
		temp.a = min(now.a, min(Tree[now.u].a, Tree[now.v].a));
		Tree[now.u].father = Tree[now.v].father = temp.father = Tree.size();
		temp.l = min(Tree[now.u].l, Tree[now.v].l);
		Tree.push_back(temp);
		tot++;
	}
}
void dfs(int u, int dep)
{
	f[u][0] = Tree[u].father;
	for (int i = 1; (1 << i) <= dep; i++)
	{
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	if (Tree[u].lson)
	{
		dfs(Tree[u].lson, dep + 1);
	}
	if (Tree[u].rson)
	{
		dfs(Tree[u].rson, dep + 1);
	}
}
int find(int u)
{
	return u == fa[u] ? u : fa[u]=find(fa[u]);
}
void merge(int u, int v)
{
	fa[find(u)] = find(v);
}
int solve(int v, int p)
{
	int now = v;
	for (int i = 20; i >= 0; i--)
	{
		if (f[now][i] && Tree[f[now][i]].a > p)
		{
			now = f[now][i];
		}
	}
	return Tree[now].l;
}