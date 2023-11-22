#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

mt19937 rnd;

int gen(int l, int r)
{
	return rnd() % (r - l + 1) + l;
}

int main()
{
	rnd.seed(GetTickCount());
	freopen("run.in", "w", stdout);
	int c = 0, T = gen(1, 6);
	printf("%d %d\n", c, T);
	while (T--)
	{
		int n = gen(1, 1e5), m = gen(1, 1e5), k = gen(1, min(200, n)), d = gen(1, 1e8);
		printf("%d %d %d %d\n", n, m, k, d);
		for (int i = 1; i <= m; ++i)
		{
			int l = gen(1, n), r = gen(1, n);
			if (l > r)
				swap(l, r);
			printf("%d %d %d\n", r, r - l + 1, gen(1, 1e9));
		}
	}
	return 0;
}