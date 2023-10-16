#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e4 + 2;

int n, a[N], m, l, r;

#define mid (d[idx].l + d[idx].r >> 1)
#define ls (idx << 1)
#define rs (idx << 1 | 1)

struct SegTree
{
	int l, r, sum, val, lval, rval;
} d[N << 2];

SegTree push_up(SegTree F, SegTree L, SegTree R)
{
	F.sum = L.sum + R.sum;
	F.val = max(L.rval + R.lval, max(L.val, R.val));
	F.lval = max(L.lval, L.sum + R.lval);
	F.rval = max(R.rval, R.sum + L.rval);
	return F;
}

void build(int l, int r, int idx)
{
	d[idx] = {l, r, 0, 0, 0, 0};
	if (l == r)
	{
		d[idx].lval = d[idx].rval = d[idx].val = d[idx].sum = a[l];
		return;
	}
	build(l, mid, ls), build(mid + 1, r, rs);
	d[idx] = push_up(d[idx], d[ls], d[rs]);
}

SegTree query(int l, int r, int idx)
{
	if (l <= d[idx].l && d[idx].r <= r)
		return d[idx];
	if (l <= mid)
		return query(l, r, ls);
	if (r > mid)
		return query(l, r, rs);
	SegTree t;
	return (t = push_up(t, query(l, r, ls), query(l, r, rs)));
}

int main()
{
#ifndef ONLINE_JUDGE
	FileIO("SP1043");
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, n, 1);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		cout << query(l, r, 1).val << '\n';
	}

	return 0;
}
