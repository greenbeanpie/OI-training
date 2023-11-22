#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int c, T, n, m, ans, a[maxn], b[maxn], x[maxn], y[maxn];

char opt[maxn];

int read()
{
	int res = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		res = (res << 3) + (res << 1) + (ch & 15);
	return res;
}

void check()
{
	for (int i = 1; i <= n; ++i)
		b[i] = a[i];
	for (int i = 1; i <= m; ++i)
	{
		if (opt[i] == 'U')
			b[x[i]] = 0;
		if (opt[i] == 'T')
			b[x[i]] = 1;
		if (opt[i] == 'F')
			b[x[i]] = -1;
		if (opt[i] == '+')
			b[x[i]] = b[y[i]];
		if (opt[i] == '-')
			b[x[i]] = -b[y[i]];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != b[i])
			return;
	}
	int now = 0;
	for (int i = 1; i <= n; ++i)
		now += (b[i] == 0);
	ans = min(ans, now);
}

void dfs(int step)
{
	if (step > n)
	{
		check();
		return;
	}
	for (int i = -1; i <= 1; ++i)
	{
		a[step] = i;
		dfs(step + 1);
	}
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool1.out", "w", stdout);
	c = read(), T = read();
	while (T--)
	{
		n = read(), m = read();
		for (int i = 1; i <= m; ++i)
		{
			char ch = getchar();
			while (!isalpha(ch) && ch != '+' && ch != '-')
				ch = getchar();
			opt[i] = ch, x[i] = read();
			if (ch == '+' || ch == '-')
				y[i] = read();
		}
		ans = 1e9;
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}