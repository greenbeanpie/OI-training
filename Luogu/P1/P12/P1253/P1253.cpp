#include <bits/stdc++.h>
#define y1 y114514
#define int long long

using namespace std;

const int INF = 1145141919810;
const int N = 1e6 + 10;

long long a[N], tree[4 * N], lazy_add[4 * N], lazy_mdf[4 * N];
int n, m;

void build(int cl, int cr, int p)
{
	if (cl == cr)
	{
		lazy_mdf[p] = INF;
		tree[p] = a[cl];
		return;
	}
	int mid = (cl + cr) / 2;
	build(cl, mid, p * 2);
	build(mid + 1, cr, p * 2 + 1);
	tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
	lazy_mdf[p] = INF;
}

void range_add(int l, int r, long long c, int cl, int cr, int p)
{
	if (l <= cl && r >= cr)
	{
		tree[p] += c;
		if (lazy_mdf[p] == INF)
			lazy_add[p] += c;
		else
			lazy_mdf[p] += c;
		return;
	}
	int mid = (cl + cr) / 2;
	if (lazy_mdf[p] != INF)
	{
		tree[p * 2] = lazy_mdf[p];
		tree[2 * p + 1] = lazy_mdf[p];
		lazy_add[2 * p] = 0;
		lazy_add[2 * p + 1] = 0;
		lazy_mdf[2 * p] = lazy_mdf[p];
		lazy_mdf[2 * p + 1] = lazy_mdf[p];
		lazy_mdf[p] = INF;
	}
	if (lazy_add[p])
	{
		tree[p * 2] += lazy_add[p];
		tree[p * 2 + 1] += lazy_add[p];
		if (lazy_mdf[2 * p] == INF)
		{
			lazy_add[2 * p] += lazy_add[p];
		}
		else
		{
			lazy_mdf[2 * p] += lazy_add[p];
		}
		if (lazy_mdf[2 * p + 1] == INF)
		{
			lazy_add[2 * p + 1] += lazy_add[p];
		}
		else
		{
			lazy_mdf[2 * p + 1] += lazy_add[p];
		}
		lazy_add[p] = 0;
	}
	if (l <= mid)
	{
		range_add(l, r, c, cl, mid, p * 2);
	}
	if (r > mid)
	{
		range_add(l, r, c, mid + 1, cr, p * 2 + 1);
	}
	tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
}

void range_mdf(int l, int r, long long c, int s, int t, int p)
{

	if (l <= s && r >= t)
	{
		tree[p] = c;
		lazy_mdf[p] = c;
		lazy_add[p] = 0;
		return;
	}

	int mid = (s + t) / 2;
	if (lazy_mdf[p] != INF)
	{
		tree[p * 2] = lazy_mdf[p];
		tree[2 * p + 1] = lazy_mdf[p];
		lazy_add[2 * p] = 0;
		lazy_add[2 * p + 1] = 0;
		lazy_mdf[2 * p] = lazy_mdf[p];
		lazy_mdf[2 * p + 1] = lazy_mdf[p];
		lazy_mdf[p] = INF;
	}
	if (lazy_add[p])
	{
		tree[p * 2] += lazy_add[p];
		tree[p * 2 + 1] += lazy_add[p];
		if (lazy_mdf[2 * p] == INF)
		{
			lazy_add[2 * p] += lazy_add[p];
		}
		else
		{
			lazy_mdf[2 * p] += lazy_add[p];
		}
		if (lazy_mdf[2 * p + 1] == INF)
		{
			lazy_add[2 * p + 1] += lazy_add[p];
		}
		else
		{
			lazy_mdf[2 * p + 1] += lazy_add[p];
		}
		lazy_add[p] = 0;
	}

	if (l <= mid)
	{
		range_mdf(l, r, c, s, mid, p * 2);
	}
	if (r > mid)
	{
		range_mdf(l, r, c, mid + 1, t, p * 2 + 1);
	}
	tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
}

int range_max(int l, int r, int s, int t, int p)
{
	if (l <= s && r >= t)
	{
		return tree[p];
	}

	int mid = (s + t) / 2;
	int maxx = -1e18;
	if (lazy_mdf[p] != INF)
	{
		tree[p * 2] = lazy_mdf[p], tree[2 * p + 1] = lazy_mdf[p];
		lazy_add[2 * p] = 0, lazy_add[2 * p + 1] = 0;
		lazy_mdf[2 * p] = lazy_mdf[p], lazy_mdf[2 * p + 1] = lazy_mdf[p];
		lazy_mdf[p] = INF;
	}
	if (lazy_add[p])
	{
		tree[p * 2] += lazy_add[p];
		tree[p * 2 + 1] += lazy_add[p];
		if (lazy_mdf[2 * p] == INF)
		{
			lazy_add[2 * p] += lazy_add[p];
		}
		else
		{
			lazy_mdf[2 * p] += lazy_add[p];
		}
		if (lazy_mdf[2 * p + 1] == INF)
		{
			lazy_add[2 * p + 1] += lazy_add[p];
		}
		else
		{
			lazy_mdf[2 * p + 1] += lazy_add[p];
		}
		lazy_add[p] = 0;
	}
	if (l <= mid)
	{
		maxx = max(maxx, range_max(l, r, s, mid, p * 2));
	}
	if (r > mid)
	{
		maxx = max(maxx, range_max(l, r, mid + 1, t, p * 2 + 1));
	}
	return maxx;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1253_6.in", "r", stdin);
	freopen("P1253.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int op, x, y, z;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	while (m--)
	{
		cin >> op >> x >> y;
		if (op == 1)
		{
			cin >> z;
			range_mdf(x, y, z, 1, n, 1);
		}
		else if (op == 2)
		{
			cin >> z;
			range_add(x, y, z, 1, n, 1);
		}
		else if (op == 3)
		{
			cout << range_max(x, y, 1, n, 1) << endl;
		}
	}

	return 0;
}