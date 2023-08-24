#include <bits/stdc++.h>
typedef long long ll;
constexpr int maxn = 1e5 + 10;
using namespace std;

ll n, T, r, mod;
ll id[maxn], nw[maxn], w[maxn], cnt;
ll dep[maxn], son[maxn], fa[maxn], top[maxn], sz[maxn];
vector<int> e[maxn];

struct Tree
{

	int l, r;
	ll add, sum;

#define l(u) tr[u].l
#define r(u) tr[u].r
#define add(u) tr[u].add
#define sum(u) tr[u].sum

#define mid ((l(u) + r(u)) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)

} tr[maxn << 2];

void pushup(int u) { sum(u) = sum(lc) + sum(rc); }

void pushdown(int u)
{
	if (add(u))
	{
		add(lc) = (add(lc) + add(u)) % mod;
		add(rc) = (add(rc) + add(u)) % mod;
		sum(lc) = (sum(lc) + add(u) * (mid - l(u) + 1)) % mod;
		sum(rc) = (sum(rc) + add(u) * (r(u) - mid)) % mod;
		add(u) = 0;
	}
}

void build(int u, int x, int y)
{
	l(u) = x, r(u) = y, add(u) = 0;
	if (x == y)
	{
		sum(u) = nw[x] % mod;
		return;
	}

	build(lc, x, mid);
	build(rc, mid + 1, y);

	pushup(u);
}

void update(int u, int l, int r, int k)
{
	if (l(u) >= l && r(u) <= r)
	{
		add(u) = (add(u) + k) % mod;
		sum(u) = (sum(u) + k * (r(u) - l(u) + 1)) % mod;
		return;
	}

	pushdown(u);
	if (mid >= l)
		update(lc, l, r, k);
	if (mid < r)
		update(rc, l, r, k);
	pushup(u);
}

ll query(int u, int l, int r)
{
	if (l(u) >= l && r(u) <= r)
		return sum(u);

	pushdown(u);
	ll res = 0;

	if (mid >= l)
		res = (res + query(lc, l, r)) % mod;
	if (mid < r)
		res = (res + query(rc, l, r)) % mod;

	return res;
}

void update_path(int u, int v, int k)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		update(1, id[top[u]], id[u], k);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])
		swap(u, v);
	update(1, id[v], id[u], k);
}

ll query_path(int u, int v)
{
	ll res = 0;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		res = (res + query(1, id[top[u]], id[u])) % mod;
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])
		swap(u, v);
	res = (res + query(1, id[v], id[u])) % mod;
	return res;
}

void update_tree(int u, int k) { update(1, id[u], id[u] + sz[u] - 1, k); }

ll query_tree(int u) { return query(1, id[u], id[u] + sz[u] - 1) % mod; }

void dfs1(int u, int father, int depth)
{
	dep[u] = depth, fa[u] = father, sz[u] = 1;
	for (auto v : e[u])
	{
		if (v == father)
			continue;
		dfs1(v, u, depth + 1);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v])
			son[u] = v;
	}
}

void dfs2(int u, int t)
{
	id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;
	if (!son[u])
		return;
	dfs2(son[u], t);
	for (auto v : e[u])
	{
		if (v == son[u] || v == fa[u])
			continue;
		dfs2(v, v);
	}
}

int main()
{
#define problemname "P3384"
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname "_TJ.out", "w", stdout);
#endif
	cin >> n >> T >> r >> mod;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int x, y, i = 1; i < n; ++i)
	{
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs1(r, 0, 1);
	dfs2(r, r);
	build(1, 1, n);

	int opt, x, y, z;
	while (T--)
	{
		cin >> opt >> x;
		if (opt == 1)
		{
			cin >> y >> z;
			update_path(x, y, z);
		}
		if (opt == 2)
		{
			cin >> y;
			cout << query_path(x, y) % mod << '\n';
		}
		if (opt == 3)
		{
			cin >> z;
			update_tree(x, z);
		}
		if (opt == 4)
		{
			cout << query_tree(x) % mod << '\n';
		}
	}

	return 0;
}