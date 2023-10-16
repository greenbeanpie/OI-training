#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#define SIZE 50010
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
using namespace std;
int n, m, x, y;
struct SegmentTree
{
	int sum, lmax, rmax, dat;
} tr[SIZE << 2];

inline int rin()
{
	int f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
		x = x * 10 + ch - '0', ch = getchar();
	return f * x;
}
inline void Update(int p)
{
	tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
	tr[p].lmax = max(tr[p << 1].lmax, tr[p << 1].sum + tr[p << 1 | 1].lmax);
	tr[p].rmax = max(tr[p << 1 | 1].rmax, tr[p << 1 | 1].sum + tr[p << 1].rmax);
	tr[p].dat = max(max(tr[p << 1].dat, tr[p << 1 | 1].dat), tr[p << 1].rmax + tr[p << 1 | 1].lmax);
}
inline void Build(int p, int l, int r)
{
	if (l == r)
	{
		tr[p].dat = tr[p].sum = tr[p].lmax = tr[p].rmax = rin();
		return;
	}
	int mid = (l + r) >> 1;
	Build(lson);
	Build(rson);
	Update(p);
}
inline SegmentTree Query(int p, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
		return tr[p];
	int mid = (l + r) >> 1;
	if (ql > mid)
		return Query(rson, ql, qr);
	if (qr <= mid)
		return Query(lson, ql, qr);
	else
	{
		SegmentTree ans, a, b;
		a = Query(lson, ql, qr);
		b = Query(rson, ql, qr);
		ans.sum = a.sum + b.sum;
		ans.dat = max(a.dat, a.rmax + b.lmax), ans.dat = max(ans.dat, b.dat);
		ans.lmax = max(a.lmax, a.sum + b.lmax);
		ans.rmax = max(b.rmax, b.sum + a.rmax);
		return ans;
	}
}

int main()
{
	n = rin();
	Build(1, 1, n);
	m = rin();
	for (int i = 1; i <= m; i++)
	{
		x = rin(), y = rin();
		printf("%d\n", Query(1, 1, n, x, y).dat);
	}

	return 0;
}