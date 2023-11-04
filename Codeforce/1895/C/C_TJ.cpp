#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n;
int a[N];
int lth(int x)
{
	if (!x)
		return 0;
	return lth(x / 10) + 1;
}
int su(int x)
{
	if (!x)
		return 0;
	return su(x / 10) + x % 10;
}
int las(int x, int p)
{
	if (!p)
		return 0;
	return las(x / 10, p - 1) + x % 10;
}
ll mp[10][100];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		mp[lth(a[i])][su(a[i])]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int lt = lth(a[i]);
		int s1, s2, nd, nl, lp;
		for (int j = 1; j < lt; j++)
		{
			if (2 * j <= lt)
			{
				continue;
			}
			s2 = las(a[i], lt - j);
			s1 = su(a[i]) - s2;
			nl = 2 * j - lt;
			nd = s1 - s2;
			ans += mp[nl][nd];
		}
		for (int j = 1; j < lt; j++)
		{
			if (2 * j <= lt)
			{
				continue;
			}
			s2 = las(a[i], j);
			s1 = su(a[i]) - s2;
			nl = 2 * j - lt;
			nd = s2 - s1;
			ans += mp[nl][nd];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans += mp[lth(a[i])][su(a[i])];
	}
	printf("%lld\n", ans);
}
int main()
{
	solve();
	return 0;
}