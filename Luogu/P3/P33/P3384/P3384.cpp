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

const int N = 10;

vector<int> e[N];

namespace Segtree
{
	// 	template <typename T>
	// 	struct Segtree
	// 	{
	// 	protected:
	// 		vector<T> tree = vector<int>(N << 4), sum = vector<T>(N << 4), l = vector<T>(N << 4), r = vector<T>(N << 4), add = vector<T>(N << 4);
	// 		vector<T> *arr;
	// 		int idx = 0;

	// 		void build(int u, int cl, int cr)
	// 		{
	// #define l l[u]
	// #define r r[u]
	// 			l = cl;
	// 			r = cr;
	// 			if (cl == cr)
	// 			{
	// 				tree[++idx] = arr->at(cl);
	// 				return;
	// 			}
	// 			int mid = (cl + cr) >> 1;
	// 			build(u << 1, cl, mid), build(u << 1 | 1, mid + 1, cr);
	// 			tree[u] = tree[u << 1] + tree[u << 1 | 1];
	// #undef l
	// #undef r
	// 		}
	// 		void maintain(int u)
	// 		{
	// 			if (add[u])
	// 			{
	// 				int lson = u * 2, rson = lson | 1;
	// 				add[lson] += add[u], add[rson] += add[u];
	// 				tree[lson] += (r[lson] - l[lson] + 1) * add[u];
	// 				tree[rson] += (r[rson] - l[rson] + 1) * add[u];
	// 				add[u] = 0;
	// 			}
	// 		}
	// 		T range_sum(int l, int r, int u)
	// 		{
	// #define cl this->l[u]
	// #define cr this->r[u]
	// 			if (l <= cl && cr <= r)
	// 			{
	// 				return tree[u];
	// 			}
	// 			maintain(u);
	// 			T sum = 0;
	// 			int mid = (cl + cr) >> 1;
	// 			if (l <= mid)
	// 			{
	// 				sum += range_sum(l, r, u << 1);
	// 			}
	// 			if (r > mid)
	// 			{
	// 				sum += range_sum(l, r, u << 1 | 1);
	// 			}
	// 			return sum;
	// #undef cl
	// #undef cr
	// 		}
	// 		void range_add(int u, int l, int r, int val)
	// 		{
	// #define cl this->l[u]
	// #define cr this->r[u]
	// 			if (l <= cl && cr <= r)
	// 			{
	// 				add[u] += val;
	// 				tree[u] += (cr - cl + 1) * val;
	// 				return;
	// 			}
	// 			maintain(u);
	// 			int mid = (cl + cr) >> 1;
	// 			if (l <= mid)
	// 			{
	// 				range_add(u << 1, l, r, val);
	// 			}
	// 			if (r > mid)
	// 			{
	// 				range_add(u << 1 | 1, l, r, val);
	// 			}
	// 			tree[u] = tree[u << 1] + tree[u << 1 | 1];
	// #undef cl
	// #undef cr
	// 		}

	// 	public:
	// 		Segtree(vector<T> *num)
	// 		{
	// 			arr = num;
	// 		}
	// 		void range_add(int l, int r, int val)
	// 		{
	// 			if (l > r)
	// 			{
	// 				swap(l, r);
	// 			}
	// 			range_add(1, l, r, val);
	// 		}
	// 		T range_sum(int l, int r)
	// 		{
	// 			if (l > r)
	// 			{
	// 				swap(l, r);
	// 			}
	// 			return range_sum(1, arr->size() - 1, 1);
	// 		}
	// 		void build(int n)
	// 		{
	// 			build(1, 1, n);
	// 		}
	// 	};
	template <typename T>
	struct SegTree
	{

		vector<T> tree, lazy;
		vector<T> *arr;
		int n, root = 1, n4, end;
		SegTree(vector<T> *a)
		{
			tree = vector<T>((*a).size() * 4, 0);
			lazy = vector<T>((*a).size() * 4, 0);
			arr = a;
		}
		inline void maintain(int cl, int cr, int p)
		{ // cl:current left(当前的左范围)
			int cmid = (cl + cr) / 2;
			if (cl <= cr && lazy[p])
			{
				lazy[p * 2] += lazy[p];					  // 更新下左节点的懒惰标记
				lazy[p * 2 + 1] += lazy[p];				  // 更新下右节点的懒惰标记
				tree[p * 2] += lazy[p] * (cmid - cl + 1); // 更新下左节点的和
				tree[p * 2 + 1] += lazy[p] * (cr - cmid); // 更新下右节点的和
				lazy[p] = 0;							  // 更新当前点懒惰标记
			}
		}
		inline T range_sum(int l, int r, int cl, int cr, int p)
		{
			if (l <= cl && cr <= r)
			{ // 如果当前范围在查询范围内可以直接返回不用去掉左边和右边
				return tree[p];
			}
			int mid = (cl + cr) / 2;
			T sum = 0;
			maintain(cl, cr, p);
			if (l <= mid)
			{
				sum += range_sum(l, r, cl, mid, p * 2);
			}
			if (r > mid)
			{
				sum += range_sum(l, r, mid + 1, cr, p * 2 + 1);
			}
			return sum;
		}
		inline void range_add(int l, int r, T val, int cl, int cr, int p)
		{
			if (l <= cl && cr <= r)
			{
				tree[p] += (cr - cl + 1) * val;
				lazy[p] += val;
				return;
			}
			int mid = (cl + cr) / 2;
			maintain(cl, cr, p);
			if (l <= mid)
			{
				range_add(l, r, val, cl, mid, p * 2);
			}
			if (r > mid)
			{
				range_add(l, r, val, mid + 1, cr, p * 2 + 1);
			}
			tree[p] = tree[p * 2] + tree[p * 2 + 1];
		}
		void build(int l, int r, int p)
		{
			if (l == r)
			{
				tree[p] = (*arr)[l];
				return;
			}
			int mid = (r + l) / 2;
			build(l, mid, p * 2);
			build(mid + 1, r, p * 2 + 1);

			tree[p] = tree[p * 2] + tree[p * 2 + 1];
			end = max(end, p * 2 + 1);
		}
		int range_sum(int l, int r)
		{
			return range_sum(l, r, 1, tree.size(), root);
		}
		void range_add(int l, int r, int val)
		{
			range_add(l, r, val, 1, tree.size(), root);
		}
		void build(){
			build(1, arr->size() - 1, 1);
		}
	};

};

namespace Main
{
	int size[N], dep[N], id[N], top[N], cnt = 0, fa[N], son[N], n, m, r, p, x, y, op, z, temp;
	vector<int> val = vector<int>(1), nw = vector<int>(1);
	Segtree::SegTree<int> Tree(&nw);

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
		if (dep[u] < dep[v])
		{
			swap(u, v);
		}
		res += Tree.range_sum(id[v], id[u]);
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
			Tree.range_add(id[u], id[top[u]], val);
			u = fa[top[u]];
		}
		if (dep[u] < dep[v])
		{
			swap(u, v);
		}
		Tree.range_add(id[u], id[v], val);
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
		top[u] = tp;
		id[u] = ++cnt;
		nw.push_back(val[u]);
		if (!son[u])
		{
			return;
		}
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
			cin >> temp;
			val.push_back(temp);
		}
		int u, v;
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(r, 0);
		dfs2(r, r);
		Tree.build();
		for (int i = 1; i <= m; i++)
		{
			cin >> op;
			if (op == 1)
			{
				cin >> x >> y >> z;
				add_path(id[x], id[y], z);
			}
			else if (op == 2)
			{
				cin >> x >> y;
				cout << query_path(x, y) << endl;
			}
			else if (op == 3)
			{
				cin >> x >> z;
				add_path(id[x], id[x] + size[x] - 1, z);
			}
			else if (op == 4)
			{
				cin >> x;
				cout << query_path(id[x], id[x] + size[x] - 1) << endl;
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