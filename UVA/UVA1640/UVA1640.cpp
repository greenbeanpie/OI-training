#include <iostream>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 a, b;
i64 l[30], r[30];
i64 f[30], B[30];

inline void init()
{
	B[0] = 1;
	for (int i = 1; i <= 15; ++i)
	{
		f[i] = f[i - 1] * 10 + B[i - 1];
		B[i] = B[i - 1] * 10;
	}
}

inline void DP(i64 n, i64 *res)
{
	int x[16];
	i64 tmp = n;
	i64 len = 0;
	while (n)
	{
		x[++len] = n % 10;
		n /= 10;
	}
	for (int i = len; i >= 1; --i)
	{
		for (int j = 0; j < 10; ++j)
			res[j] += f[i - 1] * x[i];
		for (int j = 0; j < x[i]; ++j)
			res[j] += B[i - 1];

		tmp -= B[i - 1] * x[i];
		res[x[i]] += tmp + 1;
		res[0] -= B[i - 1];
	}
}

inline void solve()
{
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	memset(f, 0, sizeof f);

	if (a > b)
		swap(a, b);
	init();

	DP(b, r), DP(a - 1, l);
	for (int i = 0; i <= 8; ++i)
		cout << r[i] - l[i] << ' ';
	cout << r[9] - l[9] << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("UVA1640.in", "r", stdin);
	freopen("UVA1640.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool f = 0;
	while (cin >> a >> b and a and b)
	{
		solve();
		f = 1;
	}
	return 0;
}
