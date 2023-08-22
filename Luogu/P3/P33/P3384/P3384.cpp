#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3384"
#define const constexpr

const int N = 1e5 + 10;

vector<int> e[N];

namespace Segtree
{
	struct Segtree
	{
	protected:
		vector<int> tree = vector<int>(n << 4), sum = vector<int>(n << 4), l = vector<int>(n << 4), r = vector<int>(n << 4);
		vector<int> *arr;
		int idx = 0;
		void build(int u, int l, int r)
		{
			l[u] = l;
			r[u] = r;
			if (l == r)
			{
				tree[++idx] = *arr[l];
			}
			int mid = (l + r) >> 1;
			build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
			tree[u] = tree[u << 1] + tree[u << 1 | 1];
		}
		void maintain(int u)
		{
			if (add[u])
			{
				int lson = u * 2, rson = lson | 1;
				add[lson] += add[u], add[rson] += add[u];
				tree[lson] += (r[lson] - l[lson] + 1) * add[u];
				tree[rson] += (r[rson] - l[rson] + 1) * add[u];
				add[u] = 0;
			}
		}
		int range_sum(int cl, int cr, int u)
		{
			if (cl <= l[u] && r[u] <= cr)
			{
				return tree[u];
			}
			maintain(u);
			int sum = 0;
			int mis = (l[u] + r[u]) >> 1;
			if (l[u] <= mid)
			{
				sum += range_sum(cl, cr, u << 1);
			}
			if (r[u] > mid)
			{
				res += query(cl, cr, u << 1 | 1);
			}
			return sum;
		}
		void range_add(int u, int cl, int cr, int val)
		{
			int l = l[u], r = r[u];
			if (cl <= l && r <= cr)
			{
				add[u] += val;
				tree[u] += (r - l + 1) * val;
				return;
			}
			maintain(u);
			int mid = (l + r) >> 1;
			if (l <= mid)
			{
				add_path(u << 1, cl, cr, val);
			}
			if (r > mid)
			{
				add_path(u << 1 | 1, cl, cr, val);
			}
			tree[u] = tree[u << 1] + tree[u << 1 | 1];
		}
	public:
		void range_add(int l,int r,int val){
			range_add(1,l,r,val);
		}
		int range_sum(int l,int r){
			return range_sum(l,r,1);
		}
	};
};

namespace Main
{
	int val[N], size[N], dep[N], id[N], top[N], cnt = 0, fa[N], son[N],n, m, r, p,x,y,op,k;
	Segtree::Segtree Tree;

	int query_path(int u, int v)
	{
		int res = 0;
		while (top[u] != top[v])
		{
			if (dep[top[u]] < dep[top[v]])
			{
				swap(u, v);
			}
			res += Tree.range_sum(id[top[u]], id[u]);
			u = fa[top[u]];
		}
		if (dep < dep[v])
		{
			swap(u, v);
		}
		res += Tree.query(id[u], id[v]);
		return res;
	}
	void add_path(int u, int v, int val)
	{
		while (top[u] != top[v])
		{
			if (dep[top[u]] < dep[top[v]])
			{
				swap(u, v);
			}
			Tree.range_add(id[u],id[top[u]],val);
			u=fa[top[u]];
		}
		range_add(id[u],id[v],val);
	}

	void dfs1(int u, int father)
	{
		size[u] = 1;
		dep[u] = dep[father] + 1;
		fa[u] = father;
		for (int i : e[u])
		{
			if (i == father)
				continue;
			dfs1(i, u);
			size[u] += size[i];
			if (size[i] > size[son[u]])
			{
				son[u] = i;
			}
		}
	}
	void dfs2(int u, int tp)
	{
		id[u] = ++cnt;
		if (!son[u])
			return;
		dfs2(son[u], tp);
		for (auto i : e[u])
		{
			if (i != fa[u] && i != son[u])
			{
				dfs2(i, i);
			}
		}
	}
	int main()
	{
		
		cin >> n >> m >> r >> p;
		for (int i = 1; i <= n; i++)
		{
			cin >> val[i];
		}
		int u, v;
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1, 0);
		dfs2(1, 1);
		build(1, 1, n);
		cin >> m;
		for(int i=1;i<=m;i++){
			cin >> op;
			switch(op){
				case 1:
					cin >> x >> y >> z;
					add_path(x,y,z);
					break;
				case 2:
					cin >> x >> y;
					cout << query_path(x,y) << endl;
					break;
				case 3:
					cin >> x >> z;
					add_path(x,x+size[x]-1,z);
					break;
				case 4:
					cin >> x;
					cout << query_path(x,x+size[x]-1) << endl;
					break;
			}
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}