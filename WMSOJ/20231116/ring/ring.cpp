#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;

struct Segtree
{
	static constexpr int n = N;
	struct node
	{
		int val = 0, lazy = 0;
	} tree[N << 2];
	void maintain(int p)
	{
		if (tree[p].lazy)
		{
			tree[p << 1].val += tree[p].lazy;
			tree[p << 1].lazy += tree[p].lazy;
			tree[(p << 1) | 1].val += tree[p].lazy;
			tree[(p << 1) | 1].lazy += tree[p].lazy;
		}
	}
	void range_add(int l, int r, int cl, int cr, int p, int val)
	{
		if (l <= cl && cr <= r)
		{
			tree[p].lazy += val;
			tree[p].val += val;
			return;
		}
		int mid = (cl + cr) >> 1;
		if (mid >= l)
		{
			range_add(l, r, cl, mid, p << 1, val);
		}
		if (mid < r)
		{
			range_add(l, r, mid + 1, cr, (p << 1 | 1), val);
		}
		tree[p].val = tree[p << 1].val + tree[(p << 1) | 1].val;
	}
	void range_add(int l, int r, int val)
	{
		return range_add(l, r, 1, n, 1, val);
	}
	int range_query(int l, int r, int cl, int cr, int p)
	{
		if (l <= cl && cr <= r)
		{
			return tree[p].val;
		}
		maintain(p);
		int mid = (cl + cr) >> 1;
		int res = 0;
		if (mid >= l)
		{
			res += range_query(l, r, cl, mid, p << 1);
		}
		if (mid < r)
		{
			res += range_query(l, r, mid + 1, cr, (p << 1 | 1));
		}
		return res;
	}
	int range_query(int l, int r)
	{
		return range_query(l, r, 1, n, 1);
	}
} Tree;

pair<int, int> a[N];
int b[N << 1], delta[N];
set<pair<int, int>> s;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "W", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].first >> a[i].second;
		b[i << 1] = a[i].first;
		b[(i << 1) - 1] = a[i].second;
	}
	sort(b + 1, b + 1 + (n << 1));
	int tot = unique(b + 1, b + 1 + (n << 1)) - b;
	for (int i = 1; i <= m; i++)
	{
		a[i].first = lower_bound(b + 1, b + tot, a[i].first) - b;
		a[i].second = lower_bound(b + 1, b + 1 + tot, a[i].second) - b;
		if (a[i].first > a[i].second)
		{
			++delta[a[i].first];
			--delta[m];
			++delta[1];
			--delta[a[i].second];
		}
		else
		{
			++delta[a[i].first];
			--delta[a[i].second];
		}
	}
	int now = 0;
	for (int i = 1; i <= n; i++)
	{
		now += delta[i];
		s.insert({now, i});
		if (!now)
		{
			cout << "Impossible";
			return 0;
		}
	}
	for(int i:s){
	}
	return 0;
}