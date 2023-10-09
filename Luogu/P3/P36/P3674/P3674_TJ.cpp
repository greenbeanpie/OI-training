#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;
#define getc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read()
{
#define num ch - '0'
	char ch;
	bool flag = 0;
	int res;
	while (!isdigit(ch = getc()))
		(ch == '-') && (flag = true);
	for (res = num; isdigit(ch = getc()); res = res * 10 + num)
		;
	(flag) && (res = -res);
#undef num
	return res;
}
const int N = 100000;
struct node
{
	int k, l, r, x, id;
} q[N + 5];
int m, n, l, r, s;
int a[N + 5], c[N + 5], ans[N + 5], rt[N + 5];
bitset<N + 5> now1, now2;
inline int operator<(node x, node y)
{
	return rt[x.l] == rt[y.l] ? rt[x.l] & 1 ? x.r < y.r : x.r > y.r : rt[x.l] < rt[y.l];
}
inline void init()
{
	n = read(), m = read(), s = sqrt(n);
	for (int i = 1; i <= n; ++i)
		a[i] = read(), rt[i] = (i - 1) / s + 1;
	for (int i = 1; i <= m; ++i)
	{
		q[i].k = read(), q[i].l = read(), q[i].r = read();
		q[i].x = read(), q[i].id = i;
	}
	sort(q + 1, q + 1 + m);
	l = 1, r = 0;
}
inline void add(int x)
{
	if (c[x]++ == 0)
		now1[x] = 1, now2[N - x] = 1;
}
inline void del(int x)
{
	if (--c[x] == 0)
		now1[x] = 0, now2[N - x] = 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P3674.in", "r", stdin);
	freopen("P3674_TJ.out", "w", stdout);
#endif
	init();
	for (int i = 1; i <= m; ++i)
	{
		while (l < q[i].l)
			del(a[l++]);
		while (l > q[i].l)
			add(a[--l]);
		while (r > q[i].r)
			del(a[r--]);
		while (r < q[i].r)
			add(a[++r]);
		int k = q[i].k, x = q[i].x;
		switch (k)
		{
		case 1:
		{
			if ((now1 & (now1 << x)).any())
				ans[q[i].id] = 1;
			break;
		}
		case 2:
		{
			if ((now1 & (now2 >> (N - x))).any())
				ans[q[i].id] = 1;
			break;
		}
		case 3:
		{
			for (int j = 1; j * j <= x; ++j)
				if (!(x % j))
					if (now1[j] && now1[x / j])
					{
						ans[q[i].id] = 1;
						break;
					}
			break;
		}
		}
	}
	for (int i = 1; i <= m; ++i)
		puts(ans[i] ? "hana" : "bi");
	return 0;
}