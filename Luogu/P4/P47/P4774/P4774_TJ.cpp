#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100005;
int T, n, m, b[maxn], t[maxn];
long long a[maxn], p[maxn], mx;
multiset<long long> s;
void exgcd(long long A, long long B, long long &x, long long &y, long long &gcd)
{
	if (!B)
		x = 1, y = 0, gcd = A;
	else
		exgcd(B, A % B, y, x, gcd), y -= (A / B) * x;
}
long long ExCRT()
{
	long long a1 = 0, m1 = 1, x, y, gcd, temp, m2, C;
	for (int i = 1; i <= n; ++i)
	{
		temp = (__int128)b[i] * m1 % p[i];
		m2 = p[i];
		C = (a[i] - b[i] * a1 % p[i] + p[i]) % p[i];
		exgcd(temp, m2, x, y, gcd), x = (x % m2 + m2) % m2;
		if (C % gcd)
			return -1;
		a1 += (__int128)(C / gcd) * x % (m2 / gcd) * m1 % (m1 *= m2 / gcd);
		a1 %= m1;
	}
	if (a1 < mx)
		a1 += ((mx - a1 - 1) / m1 + 1) * m1;
	return a1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P4774.in", "r", stdin);
	freopen("P4774_TJ.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--)
	{
		s.clear(), mx = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &p[i]);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &t[i]);
		for (int i = 1, x; i <= m; ++i)
			scanf("%d", &x), s.insert(x);
		for (int i = 1; i <= n; ++i)
		{
			auto u = s.upper_bound(a[i]);
			if (u != s.begin())
				u--;
			b[i] = *u, s.erase(u), s.insert(t[i]);
			mx = max(mx, (a[i] - 1) / b[i] + 1);
		}
		printf("%lld\n", ExCRT());
	}
}