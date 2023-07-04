#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2)
#endif
int n, m;
vector<int> num;
template <typename T>
struct SegTree
{

	vector<T> tree, lazy_add, lazy_mdf;
	vector<bool> is_mdf;
	vector<T> *arr;
	int n, root = 1, n4, end;
	SegTree(vector<T> *a)
	{
		tree = vector<T>(a->size() * 4, 0);
		lazy_add = vector<T>(a->size() * 4, 0);
		lazy_mdf = vector<T>(a->size() * 4, 0);
		is_mdf = vector<bool>(a->size() * 4, 0);
		arr = a;
	}
	inline void maintain(int cl, int cr, int p)
	{

		int cmid = (cl + cr) / 2;
		if (cl <= cr)
		{
			if (is_mdf[p])
			{
				lazy_mdf[p * 2] = lazy_mdf[p];
				lazy_mdf[p * 2 + 1] = lazy_mdf[p];
				tree[p * 2] = lazy_mdf[p] * (cmid - cl + 1);
				tree[p * 2 + 1] = lazy_mdf[p] * (cr - cmid);
				lazy_add[p] = lazy_add[p * 2] = lazy_add[p * 2 + 1] = 0;
				lazy_mdf[p] = 0;
				is_mdf[p * 2] = is_mdf[p * 2 + 1] = true;
				is_mdf[p] = false;
			}
			else if (lazy_add[p])
			{
				lazy_add[p * 2] += lazy_add[p];
				lazy_add[p * 2 + 1] += lazy_add[p];
				tree[p * 2] += lazy_add[p] * (cmid - cl + 1);
				tree[p * 2 + 1] += lazy_add[p] * (cr - cmid);
				lazy_add[p] = 0;
			}
		}
	}
	inline T range_max(int l, int r, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
			return tree[p];
		}
		int mid = (cl + cr) / 2;
		T maxx = 0;
		maintain(cl, cr, p);
		if (l <= mid)
		{
			maxx = max(maxx, range_max(l, r, cl, mid, p * 2));
		}
		if (r > mid)
		{
			maxx = max(maxx, range_max(l, r, mid + 1, cr, p * 2 + 1));
		}
		return maxx;
	}
	inline void range_add(int l, int r, T val, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
			tree[p] += (cr - cl + 1) * val;
			lazy_add[p] += val;
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
		tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
	}
	inline void range_mdf(int l, int r, T val, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
			tree[p] = (cr - cl + 1) * val;
			lazy_mdf[p] = val;
			return;
		}
		int mid = (cl + cr) / 2;
		maintain(cl, cr, p);
		if (l <= mid)
		{
			range_mdf(l, r, val, cl, mid, p * 2);
		}
		if (r > mid)
		{
			range_mdf(l, r, val, mid + 1, cr, p * 2 + 1);
		}
		tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
	}
	void build(int l, int r, int p)
	{
		if (l == r)
		{
			tree[p] = (*arr)[l - 1];
			return;
		}
		int mid = (r + l) / 2;
		build(l, mid, p * 2);
		build(mid + 1, r, p * 2 + 1);

		tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
		end = max(end, p * 2 + 1);
	}
};
inline int range_max(SegTree<int> *st, int l, int r)
{
	return st->range_max(l, r, 1, n, (*st).root);
}
inline void range_add(SegTree<int> *st, int l, int r, int val)
{
	st->range_add(l, r, val, 1, n, (*st).root);
}
inline void range_mdf(SegTree<int> *st, int l, int r, int val)
{
	st->range_mdf(l, r, val, 1, n, (*st).root);
}
/*public:
		T range_sum(int l, int r)
		{
			return range_sum(l, r, 0, end, root);
		}
		void range_add(int l, int r, int val)
		{
			range_add(l, r, val, 0, end, root);
		}
};*/

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3372_8.in", "r", stdin);
#endif

	// cin >> n >> m;
	scanf("%lld %lld", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int t;
		// cin >> t;
		scanf("%lld", &t);
		num.push_back(t);
	}
	SegTree<int> ST(&num);
	ST.build(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		int op;
		// cin >> op;
		scanf("%lld", &op);
		if (op == 1)
		{
			int x, y, k;
			scanf("%lld %lld %lld", &x, &y, &k);
			range_mdf(&ST, x, y, k);
		}
		else if (op == 2)
		{
			int x, y, k;
			// cin >> x >> y >> k;
			scanf("%lld %lld %lld", &x, &y, &k);
			range_add(&ST, x, y, k);
		}
		else
		{
			int x, y;
			// cin >> x >> y;
			scanf("%lld %lld", &x, &y);
			printf("%lld\n", range_max(&ST, x, y));
		}
	}
	return 0;
}