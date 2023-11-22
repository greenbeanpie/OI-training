#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int c, T, n, m;

struct node
{
	int flg, v;
	node operator-() const
	{
		return (node) { flg, -v };
	}
} a[maxn];

int fa[maxn * 2];

bool bad[maxn * 2];

int read()
{
	int res = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		res = (res << 3) + (res << 1) + (ch & 15);
	return res;
}

int getfa(int x)
{
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	c = read(), T = read();
	while (T--)
	{
		n = read(), m = read();
		for (int i = 1; i <= n; ++i)
			a[i] = (node) { 0, i };
		for (int i = 1; i <= n * 2; ++i)
			fa[i] = i, bad[i] = 0;
		for (int i = 1; i <= m; ++i)
		{
			char ch = getchar();
			while (!isalpha(ch) && ch != '+' && ch != '-')
				ch = getchar();
			if (ch == 'T')
			{
				int x = read();
				a[x] = (node) { 1, 1 };
			}
			else if (ch == 'F')
			{
				int x = read();
				a[x] = (node) { 1, -1 };
			}
			else if (ch == 'U')
			{
				int x = read();
				a[x] = (node) { 1, 0 };
			}
			else if (ch == '+')
			{
				int x = read(), y = read();
				a[x] = a[y];
			}
			else if (ch == '-')
			{
				int x = read(), y = read();
				a[x] = -a[y];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (!a[i].flg)
			{
				if (a[i].v > 0)
				{
					fa[getfa(i)] = getfa(a[i].v);
					fa[getfa(i + n)] = getfa(a[i].v + n);
				}
				else
				{
					fa[getfa(i)] = getfa(-a[i].v + n);
					fa[getfa(i + n)] = getfa(-a[i].v);
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (getfa(i) == getfa(i + n))
				bad[getfa(i)] = 1;
			if (a[i].v == 0)
				bad[getfa(i)] = bad[getfa(i + n)] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i].flg)
				ans += (a[i].v == 0);
			else
				ans += bad[getfa(abs(a[i].v))];
		}
		printf("%d\n", ans);
	}
	return 0;
}