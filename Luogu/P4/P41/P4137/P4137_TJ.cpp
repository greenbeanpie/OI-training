#include <bits/stdc++.h>
#define ri register int
#define getchar() (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++
#define N 200005
#define B 448
using namespace std;
#define problemname "P4137"
char ou[1 << 22], buf[1 << 22], *p1 = buf, *p2 = buf;
int n, m, s, a[N], bel[N], cnt[N], tmp[N], ans[N], L[N / B + 5], R[N / B + 5], p3 = -1;
struct query
{
	int l, r, id;
	inline bool operator<(const query &x) const
	{
		return bel[l] ^ bel[x.l] ? bel[l] < bel[x.l] : r > x.r;
	}
} q[N];
template <typename T>
inline void read(T &x)
{
	register T c = getchar();
	for (; c < 48 || 57 < c;)
		c = getchar();
	for (; 48 <= c && c <= 57; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
}
template <typename T>
inline void print(const T x)
{
	if (x > 9)
		print(x / 10);
	ou[++p3] = x % 10 | 48;
	if (p3 > (1 << 21))
		fwrite(ou, 1, p3 + 1, stdout), p3 = -1;
}
inline int mnn(const int a, const int b)
{
	return a < b ? a : b;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname "_TJ.out", "w", stdout);
#endif
	read(n), read(m);
	for (ri i = 1; i <= n; ++i)
	{
		read(a[i]), bel[i] = (i - 1) / B + 1;
		if (a[i] <= n + 1)
			++cnt[a[i]];
	}
	while (cnt[s])
		++s;
	for (ri i = 1; i <= m; ++i)
		read(q[i].l), read(q[i].r), q[i].id = i;
	for (ri i = 1; i < bel[n]; ++i)
		L[i] = R[i - 1] + 1, R[i] = i * B;
	L[bel[n]] = R[bel[n] - 1] + 1, R[bel[n]] = n, sort(q + 1, q + 1 + m);
	for (ri k = 1, i = 1, l, r, p; k <= bel[n]; ++k)
	{
		l = L[k], r = n, p = s;
		for (ri t; bel[q[i].l] == k; ++i)
		{
			if (bel[q[i].r] == k)
			{
				ri t = 0;
				for (ri j = q[i].l; j <= q[i].r; ++j)
					if (a[j] <= n + 1)
						++tmp[a[j]];
				while (tmp[t])
					++t;
				ans[q[i].id] = t;
				for (ri j = q[i].l; j <= q[i].r; ++j)
					if (a[j] <= n + 1)
						--tmp[a[j]];
				continue;
			}
			for (; r > q[i].r; --r)
				if (a[r] <= n + 1 && !--cnt[a[r]])
					p = mnn(p, a[r]);
			t = p;
			for (; l < q[i].l; ++l)
				if (a[l] <= n + 1 && !--cnt[a[l]])
					t = mnn(t, a[l]);
			ans[q[i].id] = t;
			while (l > L[k])
			{
				--l;
				if (a[l] <= n + 1)
					++cnt[a[l]];
			}
		}
		while (r < n)
		{
			++r;
			if (a[r] <= n + 1)
				++cnt[a[r]];
		}
		for (; l < L[k + 1]; ++l)
			if (a[l] <= n + 1 && !--cnt[a[l]])
				s = mnn(s, a[l]);
	}
	for (ri i = 1; i <= m; ++i)
		print(ans[i]), ou[++p3] = '\n';
	fwrite(ou, 1, p3 + 1, stdout);
	return 0;
}