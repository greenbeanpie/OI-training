#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5, M = 21;
template <typename T>
struct Segtree
{
	struct node
	{
		int l, r, min, max;
		T val, lazy_add, lazy_mul;
		node *son[2];
		node()
		{
			l = r = val = lazy_add = min = max = 0;
			lazy_mul = 1;
			son[0] = son[1] = nullptr;
		}
	};

	node *root;

	vector<T> *arr;

	Segtree(vector<T> &a)
	{
		arr = &a;
	}

	void build(int l, int r, node *p)
	{
		p->l = l, p->r = r;
		if (l == r)
		{
			p->val = arr->at(l);
			p->max = p->min = p->val;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, p->son[0] = new node);
		build(mid + 1, r, p->son[1] = new node);
		p->val = p->son[0]->val + p->son[1]->val;
		p->max = max(p->son[0]->max, p->son[1]->max);
		p->min = min(p->son[0]->min, p->son[1]->min);
		// p->val %= P;
	}
	void build()
	{
		return build(1, arr->size() - 1, root = new node);
	}
	void maintain(node *p)
	{
		p->son[0]->lazy_mul = (p->son[0]->lazy_mul * p->lazy_mul);
		p->son[1]->lazy_mul = (p->son[1]->lazy_mul * p->lazy_mul);
		p->son[0]->lazy_add = (p->son[0]->lazy_add * p->lazy_mul + p->lazy_add);
		p->son[1]->lazy_add = (p->son[1]->lazy_add * p->lazy_mul + p->lazy_add);
		p->son[0]->val = (p->son[0]->val * p->lazy_mul + p->lazy_add * (p->son[0]->r - p->son[0]->l + 1));
		p->son[1]->val = (p->son[1]->val * p->lazy_mul + p->lazy_add * (p->son[1]->r - p->son[1]->l + 1));
		p->lazy_mul = 1;
		p->lazy_add = 0;
	}
	void update(node *p)
	{
		p->val = p->son[0]->val + p->son[1]->val;
		// p->val %= P;
	}
	void add(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_add += val;
			p->val += (p->r - p->l + 1) * val;
			// p->lazy_add %= P;
			// p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			add(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			add(l, r, val, p->son[1]);
		}
		update(p);
	}
	void add(int l, int r, int val)
	{
		return add(l, r, val, root);
	}
	void mul(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_mul *= val;
			p->lazy_add *= val;
			p->val *= val;
			// p->lazy_mul %= P;
			// p->lazy_add %= P;
			// p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			mul(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			mul(l, r, val, p->son[1]);
		}
		update(p);
	}
	void mul(int l, int r, T val)
	{
		return mul(l, r, val, root);
	}
	int query_sum(int l, int r, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			return p->val;
		}
		maintain(p);
		int res = 0;
		if (p->son[0]->r >= l)
		{
			res += query_sum(l, r, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			res += query_sum(l, r, p->son[1]);
		}
		return res;
	}
	int query_sum(int l, int r)
	{
		return query_sum(l, r, root);
	}
	int query_min(int l, int r, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			return p->min;
		}
		// maintain(p);
		int res = 998244353;
		if (p->son[0]->r >= l)
		{
			res = min(res, query_min(l, r, p->son[0]));
		}
		if (p->son[1]->l <= r)
		{
			res = min(res, query_min(l, r, p->son[1]));
		}
		return res;
	}
	int query_min(int l, int r)
	{
		if (l > r)
		{
			return 998244353;
		}
		return query_min(l, r, root);
	}
	int query_max(int l, int r, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			return p->max;
		}
		// maintain(p);
		int res = 0;
		if (p->son[0]->r >= l)
		{
			res = max(query_max(l, r, p->son[0]), res);
		}
		if (p->son[1]->l <= r)
		{
			res = max(query_max(l, r, p->son[1]), res);
		}
		return res;
	}
	int query_max(int l, int r)
	{
		if (l > r)
		{
			return -1;
		}
		return query_max(l, r, root);
	}
};

vector<int> val = vector<int>(N, 0);

Segtree<int> Tree(val);

int fa[N], siz[N], top[N], id[N], son[N], dep[N];

struct node
{
	int to, val;
	node(int a, int b)
	{
		to = a, val = b;
	}
};

vector<node> e[N];

void dfs1(int u, int father = 0)
{
	fa[u] = father;
	dep[u] = dep[father] + 1;
	siz[u] = 1;
	for (auto i : e[u])
	{
		if (i.to != father)
		{
			dfs1(i.to, u);
			siz[u] += siz[i.to];
			if (siz[i.to] > siz[son[u]])
			{
				son[u] = i.to;
			}
		}
	}
}

void dfs2(int u, int father = 0, int tp = 1)
{
	static int cnt = 0;
	static bitset<N> vis;
	vis[u] = 1;
	top[u] = tp;
	id[u] = ++cnt;
	if (son[u] != 0)
	{
		dfs2(son[u], u, tp);
	}
	for (auto i : e[u])
	{
		if (i.to == son[u])
		{
			val[id[i.to]] = i.val;
		}
		else if (!vis[i.to])
		{
			dfs2(i.to, u, i.to);
			val[id[i.to]] = i.val;
		}
	}
}

int query_min(int u, int v)
{
	int mininum = 998244353;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
		{
			swap(u, v);
		}
		mininum = min(mininum, Tree.query_min(id[top[u]], id[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])
	{
		swap(u, v);
	}
	mininum = min(mininum, Tree.query_min(id[v] + 1, id[u]));
	return mininum;
}

int query_max(int u, int v)
{
	int maxinum = 0;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
		{
			swap(u, v);
		}
		maxinum = max(maxinum, Tree.query_max(id[top[u]], id[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])
	{
		swap(u, v);
	}
	maxinum = max(maxinum, Tree.query_max(id[v] + 1, id[u]));
	return maxinum;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("SP3978.in", "r", stdin);
	freopen("SP3978.out", "w", stdout);
#endif
	int n, q;
	cin >> n;
	for (int i = 1, u, v, val; i < n; i++)
	{
		cin >> u >> v >> val;
		e[u].emplace_back(v, val);
		e[v].emplace_back(u, val);
	}
	dfs1(1);
	dfs2(1);
	Tree.build();
	cin >> q;
	for (int i = 1, u, v; i <= q; i++)
	{
		cin >> u >> v;
		cout << query_min(u, v) << " " << query_max(u, v) << endl;
	}
	return 0;
}
