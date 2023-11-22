/*
Oh no, it's too hard to solve.
I could only get 35 pts not any more.
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;

int c, n, m, q, a[maxn], b[maxn], x[maxn], y[maxn];

bool f[maxn][maxn];

int read()
{
	int res = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		res = (res << 3) + (res << 1) + (ch & 15);
	return res;
}

bool solve(int* x, int n, int* y, int m)
{
	memset(f, 0, sizeof(f));
	f[1][1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (x[i] > y[j + 1])
				f[i][j + 1] |= f[i][j];
			if (x[i + 1] > y[j])
				f[i + 1][j] |= f[i][j];
		}
	}
	return f[n][m];
}

bool check()
{
	if (1ll * (x[1] - y[1]) * (x[n] - y[m]) <= 0)
		return 0;
	if (x[1] > y[1])
		return solve(x, n, y, m);
	return solve(y, m, x, n);
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for (int i = 1; i <= n; ++i)
		x[i] = a[i] = read();
	for (int i = 1; i <= m; ++i)
		y[i] = b[i] = read();
	printf("%d", check());
	for (int i = 1; i <= q; ++i)
	{
		memcpy(x, a, sizeof(a));
		memcpy(y, b, sizeof(b));
		int kx = read(), ky = read();
		for (int j = 1; j <= kx; ++j)
		{
			int p = read(), v = read();
			x[p] = v;
		}
		for (int j = 1; j <= ky; ++j)
		{
			int p = read(), v = read();
			y[p] = v;
		}
		printf("%d", check());
	}
	return 0;
}