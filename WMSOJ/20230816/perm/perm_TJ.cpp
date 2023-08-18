#include <cstdio>
#include <cmath>
#define N 1000010
int n, m, i, j, a[N], b[N], c[N], f[N], g[N << 1], nxt[N], st[N << 1], en[N << 1], q[N];
inline void read(int &a)
{
	char c;
	while (!(((c = getchar()) >= '0') && (c <= '9')))
		;
	a = c - '0';
	while (((c = getchar()) >= '0') && (c <= '9'))
		(a *= 10) += c - '0';
}
inline void add(int x, int y)
{
	nxt[y] = g[x];
	g[x] = y;
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int pre(int l, int r, int x)
{
	int t = 0, mid;
	while (l <= r)
		if (q[mid = (l + r) >> 1] <= x)
			l = (t = mid) + 1;
		else
			r = mid - 1;
	return q[t];
}
int dp(int x, int y)
{
	if (!x || !y)
		return x + y;
	if (a[x] == b[y])
		return f[x] ? f[x] : f[x] = min(dp(x - 1, y), dp(x, y - 1)) + 1;
	int t = pre(st[x - y + n], en[x - y + n], x);
	return t ? dp(t, y - x + t) + x - t : std::max(x,y);
}
int main()
{
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	read(n);
	for (i = 1; i <= n; i++)
		read(a[i]);
	for (i = 1; i <= n; i++)
		read(b[i]), c[b[i]] = i;
	for (i = n; i; i--)
		add(i - c[a[i]] + n, i);
	for (i = 1; i < n + n; en[i++] = m)
		for (st[i] = m + 1, j = g[i]; j; j = nxt[j])
			q[++m] = j;
	printf("%d", dp(n, n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}