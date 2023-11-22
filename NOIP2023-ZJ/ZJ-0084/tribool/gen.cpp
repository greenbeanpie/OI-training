#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int maxn = 100005;

mt19937 rnd;

char opt[maxn];

int a[maxn], b[maxn], x[maxn], y[maxn];

int gen(int l, int r)
{
	return rnd() % (r - l + 1) + l;
}

char id(int x)
{
	if (x == -1)
		return 'F';
	if (x == 0)
		return 'U';
	return 'T';
}

int val(char ch)
{
	if (ch == 'F')
		return -1;
	if (ch == 'U')
		return 0;
	if (ch == 'T')
		return 1;
	return 2;
}

int main()
{
	rnd.seed(GetTickCount());
	freopen("tribool.in", "w", stdout);
	int c = 0, T = gen(1, 6);
	printf("%d %d\n", c, T);
	while (T--)
	{
		int n = gen(1, 12), m = gen(1, 15);
		for (int i = 1; i <= n; ++i)
		{
			int x = gen(1, 5);
			if (x == 1)
				a[i] = b[i] = -1;
			if (x == 2)
				a[i] = b[i] = 1;
			else
				a[i] = b[i] = 0;
		}
		for (int i = 1; i <= m; ++i)
		{
			int op = gen(-1, 3 - (n == 1));
			if (op <= 1)
				opt[i] = id(op), x[i] = gen(1, n);
			else if (op == 2)
				opt[i] = '+', x[i] = gen(1, n), y[i] = gen(1, n);
			else
			{
				int p = gen(1, n), q = gen(1, n);
				while (p == q)
					p = gen(1, n), q = gen(1, n);
				opt[i] = '-', x[i] = p, y[i] = q;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] != b[i])
				opt[++m] = id(a[i]), x[m] = i;
		}
		printf("%d %d\n", n, m);
		for (int i = 1; i <= m; ++i)
		{
			if (val(opt[i]) <= 1)
				printf("%c %d\n", opt[i], x[i]);
			else
				printf("%c %d %d\n", opt[i], x[i], y[i]);
		}
	}
	return 0;
}