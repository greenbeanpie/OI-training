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
	int n = gen(2, 5), m = gen(2, 5), xn = gen(1, 5), ym = gen(15, 20);
	int x1 = gen(xn + 1, 10), y1 = gen(x1 + 1, ym);
	printf("%d %d %d %d\n", 0, n, m, 0);
	printf("%d ", x1);
	for (int i = 2; i < n; ++i)
		printf("%d ", gen(xn, 10));
	printf("%d\n", xn);
	printf("%d ", y1);
	for (int i = 2; i < m; ++i)
		printf("%d ", gen(10, ym));
	printf("%d\n", ym);
	return 0;
}