/*
[l1[i],r1[i]]里i是唯一的最小值
[l2[i],r2[i]]里i是唯一的最大值
用单调队列O(n)求出
枚举最小值的位置i，则最大值的位置j须满足l1[i]<=j<=r1[i]，l2[j]<=l1[i]，r2[j]>=i
求出满足条件的最大的r2[j]，则此时区间长度为min(r1[i],r2[j])-l1[i]+1，开头为l1[i]
排序后用线段树维护
然后将l1[i]与l2[i]交换、r1[i]与r2[i]交换再求一次即可求出最优解
*/
#include <cstdio>
const int N = 500010, M = 1048577;
int n, i, j, a[N], q[N], t, l1[N], r1[N], l2[N], r2[N], len = 1, st = 1, v[M];
struct E
{
	int v, w;
	E *nxt;
} pool[N << 1], *cur = pool, *g[N], *h[N], *p;
inline void addg(int x, int y, int z)
{
	p = cur++;
	p->v = y;
	p->w = z;
	p->nxt = g[x];
	g[x] = p;
}
inline void addh(int x, int y, int z)
{
	p = cur++;
	p->v = y;
	p->w = z;
	p->nxt = h[x];
	h[x] = p;
}
inline void read(int &a)
{
	char c;
	bool f = 0;
	a = 0;
	while (!((((c = getchar()) >= '0') && (c <= '9')) || (c == '-')))
		;
	if (c != '-')
		a = c - '0';
	else
		f = 1;
	while (((c = getchar()) >= '0') && (c <= '9'))
		(a *= 10) += c - '0';
	if (f)
		a = -a;
}
inline void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
inline void max(int &a, int b)
{
	if (a < b)
		a = b;
}
inline void ins(int c, int d)
{
	int x = 1, a = 1, b = n, mid;
	while (1)
	{
		max(v[x], d);
		if (a == b)
			return;
		mid = (a + b) >> 1, x <<= 1;
		if (c <= mid)
			b = mid;
		else
			x |= 1, a = mid + 1;
	}
}
void ask(int x, int a, int b, int c, int d)
{
	if (c <= a && b <= d)
	{
		max(j, v[x]);
		return;
	}
	int mid = (a + b) >> 1;
	if (c <= mid)
		ask(x << 1, a, mid, c, d);
	if (d > mid)
		ask(x << 1 | 1, mid + 1, b, c, d);
}
void work()
{
	for (i = 1; i <= n; i++)
		addg(l1[i], i, r1[i]), addh(l2[i], i, r2[i]);
	for (i = 1; i <= n; i++)
	{
		for (p = h[i]; p; p = p->nxt)
			ins(p->v, p->w);
		for (p = g[i]; p; p = p->nxt)
		{
			j = 0, ask(1, 1, n, i, p->w);
			if (j < p->v)
				continue;
			if ((t = (p->w < j ? p->w : j) - i + 1) > len)
				len = t, st = i;
			else if (t == len && i < st)
				st = i;
		}
	}
}
int main()
{
	freopen("only.in", "r", stdin);
	freopen("only.out", "w", stdout);
	for (read(n), i = 1; i <= n; i++)
		read(a[i]);
	for (q[t = 0] = 0, i = 1; i <= n; q[++t] = i++)
	{
		while (t && a[q[t]] > a[i])
			t--;
		l1[i] = q[t] + 1;
	}
	for (q[t = 0] = n + 1, i = n; i; q[++t] = i--)
	{
		while (t && a[q[t]] > a[i])
			t--;
		r1[i] = q[t] - 1;
	}
	for (q[t = 0] = 0, i = 1; i <= n; q[++t] = i++)
	{
		while (t && a[q[t]] < a[i])
			t--;
		l2[i] = q[t] + 1;
	}
	for (q[t = 0] = n + 1, i = n; i; q[++t] = i--)
	{
		while (t && a[q[t]] < a[i])
			t--;
		r2[i] = q[t] - 1;
	}
	work();
	for (cur = pool, i = 1; i <= n; i++)
		g[i] = h[i] = NULL;
	for (i = 1; i < M; i++)
		v[i] = 0;
	for (i = 1; i <= n; i++)
		swap(l1[i], l2[i]), swap(r1[i], r2[i]);
	work();
	printf("%d %d", len, st);
	fclose(stdin);
	fclose(stdout);
	return 0;
}