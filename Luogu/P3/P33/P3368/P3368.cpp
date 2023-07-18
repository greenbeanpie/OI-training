#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> num;
template <typename T>
struct SegTree
{

	vector<T> tree, lazy_add;
	vector<T> *arr;
	int n, root = 1, n4, end;
	SegTree(vector<T> a)
	{
		tree = vector<T>(a.size() * 4, 0);
		lazy_add = vector<T>(a.size() * 4, 0);
		arr = &a;
	}
	void maintain(int cl, int cr, int p)
	{ // cl:current left(当前的左范围)
		int cmid = cl + (cr - cl) / 2;
		if (cl >= cr && lazy_add[p])
		{
			lazy_add[p * 2] += lazy_add[p];				  // 更新下左节点的懒惰标记
			lazy_add[p * 2 + 1] += lazy_add[p];			  // 更新下右节点的懒惰标记
			tree[p * 2] += lazy_add[p] * (cmid - cl + 1); // 更新下左节点的和
			tree[p * 2 + 1] += lazy_add[p] * (cr - cmid); // 更新下右节点的和
			lazy_add[p] = 0;							  // 更新当前点懒惰标记
		}
	}
	T range_sum(int l, int r, int cl, int cr, int p)
	{
		if (l <= cl && cl <= r)
		{ // 如果当前范围在查询范围内可以直接返回不用去掉左边和右边
			return tree[p];
		}
		int mid = cl + (cr - cl) / 2;
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
	void range_add(int l, int r, T val, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
			tree[p] += (cr - cl + 1) * val;
			lazy_add[p] += val;
			return;
		}
		int mid = cl + (cr - cl) / 2;
		maintain(l, r, p);
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
		int mid = l + (r - l) / 2;
		build(l, mid, p * 2);
		build(mid + 1, r, p * 2 + 1);

		tree[p] = tree[p * 2] + tree[p * 2 + 1];
		end = max(end, p * 2 + 1);
	}
};
int range_sum(SegTree<int> st, int l, int r)
{
	return st.range_sum(l, r, l, r, st.root);
}
void range_add(SegTree<int> *st, int l, int r, int val)
{
	st->range_add(l, r, val, l, r, (*st).root);
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
	freopen("P3368.in", "r", stdin);
	freopen("P3368.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		num.push_back(t);
	}
	SegTree<int> ST(num);
	ST.build(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			range_add(&ST, x, y, k);
		}
		else
		{
			int x;
			cin >> x;
			cout << range_sum(ST, x, x) << endl;
		}
	}
	return 0;
}