#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifndef ONLINE_JUDGE
#ifndef CODESPACE
#pragma GCC optimize(2)
#endif
#endif
int n, m, mod = 571373;
vector<int> num;
template <typename T>
struct SegTree
{
	vector<T> tree, lazy_add, lazy_mul;
	vector<T> *arr;
	int n, root = 1, n4, end;
	SegTree(vector<T> *a)
	{
		tree = vector<T>((*a).size() * 4, 0);
		lazy_add = vector<T>((*a).size() * 4, 0);
		lazy_mul = vector<T>((*a).size() * 4, 1);
		arr = a;
	}
	inline void maintain(int cl, int cr, int p)
	{ // cl:current left(当前的左范围)
		int cmid = (cl + cr) / 2;
		if (cl > cr)
		{
			return;
		}
		lazy_mul[p * 2] *= lazy_mul[p];
		lazy_mul[p * 2] %= mod;
		lazy_mul[p * 2 + 1] *= lazy_mul[p];
		lazy_mul[p * 2 + 1] %= mod;
		lazy_add[p * 2] = (lazy_add[p * 2] * lazy_mul[p] + lazy_add[p]) % mod;
		lazy_add[p * 2 + 1] = (lazy_add[p * 2 + 1] * lazy_mul[p] + lazy_add[p]) % mod;
		tree[p * 2] = (tree[p * 2] * lazy_mul[p] + lazy_add[p] * (cmid - cl + 1)) % mod;
		tree[p * 2 + 1] = (tree[p * 2 + 1] * lazy_mul[p] + lazy_add[p] * (cr - cmid)) % mod;
		lazy_mul[p] = 1;
		lazy_add[p] = 0;
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
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}
	inline void range_mul(int l, int r, T val, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
			tree[p] *= val;
			lazy_add[p] *= val;
			lazy_mul[p] *= val;
			return;
		}
		int mid = (cl + cr) / 2;
		maintain(cl, cr, p);
		if (l <= mid)
		{
			range_mul(l, r, val, cl, mid, p * 2);
		}
		if (r > mid)
		{
			range_mul(l, r, val, mid + 1, cr, p * 2 + 1);
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
inline void range_mul(SegTree<int> *st, int l, int r, int val)
{
	st->range_mul(l, r, val, 1, n, (*st).root);
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
	freopen("P3373.in", "r", stdin);
#endif

	// cin >> n >> m;
	scanf("%lld %lld %lld", &n, &m, &mod);

	for (int i = 0; i < n; i++)
	{
		int t;
		// cin >> t;
		scanf("%lld", &t);
		num.push_back(t);
	}
	SegTree<int> ST(&num);
	ST.build(1, n, 1);
	int tot = 0;
	for (int i = 0; i < m; i++)
	{
		int op;
		// cin >> op;
		scanf("%lld", &op);
		if (op == 1)
		{
			int x, y, k;
			// cin >> x >> y >> k;
			scanf("%lld %lld %lld", &x, &y, &k);
			range_mul(&ST, x, y, k);
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
			++tot;
			int x, y;
			// cin >> x >> y;
			scanf("%lld %lld", &x, &y);
			printf("%lld\n", range_sum(&ST, x, y) % mod);
		}
	}
	return 0;
}