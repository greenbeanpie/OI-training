#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int maxn = 100005;

int c, T, n, m, k, d;

struct node
{
	int x, y, v;
	bool operator<(const node& rhs) const
	{
		return x < rhs.x;
	}
} a[maxn];

i64 f[2][maxn];

i64 tre[maxn * 8], tag[maxn * 8];

int read()
{
	int res = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		res = (res << 3) + (res << 1) + (ch & 15);
	return res;
}

void update(i64& x, i64 y)
{
	if (x < y)
		x = y;
}

void push_down(int root)
{
	if (tag[root])
	{
		tre[root << 1] += tag[root];
		tag[root << 1] += tag[root];
		tre[root << 1 | 1] += tag[root];
		tag[root << 1 | 1] += tag[root];
		tag[root] = 0;
	}
}

void build(int root, int l, int r)
{
	tre[root] = -(1ll << 60);
	tag[root] = 0;
	if (l < r)
	{
		int mid = l + r >> 1;
		build(root << 1, l, mid);
		build(root << 1 | 1, mid + 1, r);
	}
}

void assign(int root, int l, int r, int x, i64 v)
{
	if (l == r)
	{
		tre[root] = v;
		return;
	}
	int mid = l + r >> 1;
	push_down(root);
	if (x <= mid)
		assign(root << 1, l, mid, x, v);
	else
		assign(root << 1 | 1, mid + 1, r, x, v);
	tre[root] = max(tre[root << 1], tre[root << 1 | 1]);
}

void update(int root, int l, int r, int x, int y, i64 v)
{
	if (l > y || r < x)
		return;
	if (x <= l && r <= y)
	{
		tre[root] += v;
		tag[root] += v;
		return;
	}
	int mid = l + r >> 1;
	push_down(root);
	update(root << 1, l, mid, x, y, v);
	update(root << 1 | 1, mid + 1, r, x, y, v);
	tre[root] = max(tre[root << 1], tre[root << 1 | 1]);
}

i64 query(int root, int l, int r, int x)
{
	if (l == r)
		return tre[root];
	int mid = l + r >> 1;
	push_down(root);
	if (x <= mid)
		return query(root << 1, l, mid, x);
	else
		return query(root << 1 | 1, mid + 1, r, x);
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run1.out", "w", stdout);
	c = read(), T = read();
	while (T--)
	{
		n = read(), m = read(), k = read(), d = read();
		for (int i = 1; i <= m; ++i)
		{
			a[i] = (node) { read(), read(), read() };
			if (a[i].y > k)
				--i, --m;
		}
		sort(a + 1, a + m + 1);
//		if (n <= 1e5)
//		{
			build(1, 0, n + k);
			int ql = n, qr = n + k;
			assign(1, 0, n + k, ql, 0);
			for (int i = 1, j = 1; i <= n; ++i)
			{
				assign(1, 0, n + k, --ql, tre[1]);
				assign(1, 0, n + k, qr--, -(1ll << 60));
				update(1, 0, n + k, ql + 1, qr, -d);
				while (j <= m && i == a[j].x)
				{
					update(1, 0, n + k, ql + a[j].y, qr, a[j].v);
					++j;
				}
			}
			printf("%lld\n", tre[1]);
//			continue;
//		}
//		if (17 <= c && c <= 18)
//		{
//			i64 ans = 0;
//			for (int i = 1; i <= m; ++i)
//				ans += max(0ll, a[i].v - (i64)a[i].y * d);
//			printf("%lld\n", ans);
//			continue;
//		}
//		for (int j = 1; j <= k; ++j)
//			f[0][j] = -(1ll << 60);
//		f[0][0] = 0;
//		for (int i = 1; i <= m; ++i)
//		{
//			for (int j = 0; j <= k; ++j)
//				f[i & 1][j] = -(1ll << 60);
//			if (a[i].x == a[i - 1].x)
//			{
//				for (int j = 0; j <= k; ++j)
//					update(f[i & 1][j], f[i - 1 & 1][j] + (j >= a[i].y) * a[i].v);
//			}
//			else
//			{
//				for (int j = 0; j <= k; ++j)
//				{
//					update(f[i & 1][0], f[i - 1 & 1][j]);
//					if (j + a[i].x - a[i - 1].x <= k)
//						update(f[i & 1][j + a[i].x - a[i - 1].x], f[i - 1 & 1][j] + (j + a[i].x - a[i - 1].x >= a[i].y) * a[i].v - (i64)(a[i].x - a[i - 1].x) * d);
//				}
//				for (int j = 0; j <= min(k, a[i].x - a[i - 1].x - 1); ++j)
//					update(f[i & 1][j], f[i & 1][0] + (j >= a[i].y) * a[i].v - (i64)j * d);
//			}
//		}
//		i64 ans = 0;
//		for (int i = 0; i <= k; ++i)
//			update(ans, f[m & 1][i]);
//		printf("%lld\n", ans);
	}
//	fprintf(stderr, "used:%.2lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
	return 0;
}