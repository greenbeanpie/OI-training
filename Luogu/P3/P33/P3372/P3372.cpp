#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> num;
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
	{
		int cmid = (cl + cr) / 2;
		if (cl <= cr && lazy[p])
		{
			lazy[p * 2] += lazy[p];
			lazy[p * 2 + 1] += lazy[p];
			tree[p * 2] += lazy[p] * (cmid - cl + 1);
			tree[p * 2 + 1] += lazy[p] * (cr - cmid);
			lazy[p] = 0;
		}
	}
	inline T range_sum(int l, int r, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
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
			tree[p] = (*arr)[l - 1];
			return;
		}
		int mid = (r + l) / 2;
		build(l, mid, p * 2);
		build(mid + 1, r, p * 2 + 1);

		tree[p] = tree[p * 2] + tree[p * 2 + 1];
		end = max(end, p * 2 + 1);
	}
};
inline int range_sum(SegTree<int> *st, int l, int r)
{
	return st->range_sum(l, r, 1, n, (*st).root);
}
inline void range_add(SegTree<int> *st, int l, int r, int val)
{
	st->range_add(l, r, val, 1, n, (*st).root);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3372_8.in", "r", stdin);
#endif
	scanf("%lld %lld", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%lld", &t);
		num.push_back(t);
	}
	SegTree<int> ST(&num);
	ST.build(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		int op;
		scanf("%lld", &op);
		if (op == 1)
		{
			int x, y, k;
			scanf("%lld %lld %lld", &x, &y, &k);
			range_add(&ST, x, y, k);
		}
		else
		{
			int x, y;
			scanf("%lld %lld", &x, &y);
			printf("%lld\n", range_sum(&ST, x, y));
		}
	}
	return 0;
}