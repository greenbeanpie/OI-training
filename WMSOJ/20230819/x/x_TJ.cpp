#include <bits/stdc++.h>

typedef long long i64;
constexpr int N = 1e5 + 100;
int n, m, lim, a[N], bit[N << 1], sum[N];

inline void add(int x, int k)
{
	for (; x <= lim; x += (x & -x))
		bit[x] += k;
}

inline int qry(int x)
{
	int res = 0;
	for (; x; x -= (x & -x))
		res += bit[x];
	return res;
}

inline i64 calc(int val, int len)
{
	if (len == 0)
		return 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= val)
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1] - 1;
	}
	std::fill(bit + 1, bit + lim + 1, 0);
	for (int i = 0; i <= n; i++)
		sum[i] += n + 10;
	i64 res = 0;
	for (int r = 0; r <= n; r++)
	{
		res += qry(sum[r]), add(sum[r], 1);
		int l = r - len + 1;
		if (l - 1 >= 0)
			add(sum[l - 1], -1);
	}
	// r - l + 1 = len => l = r - len + 1;
	return res;
}

inline i64 solve(int l1, int r1, int l2, int r2)
{
	return calc(r1, r2) + calc(l1 - 1, l2 - 1) - calc(r1, l2 - 1) - calc(l1 - 1, r2);
}

signed main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	freopen("X.in", "r", stdin);
	freopen("X.out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i < +n; i++)
		std::cin >> a[i];
	lim = (n << 1) + 100;
	for (std::cin >> m; m--;)
	{
		int l1, r1, l2, r2;
		std::cin >> l1 >> r1 >> l2 >> r2;
		std::cout << solve(l1, r1, l2, r2), putchar('\n');
	}
	return 0;
}
