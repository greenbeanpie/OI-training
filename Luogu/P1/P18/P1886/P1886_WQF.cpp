#include <bits/stdc++.h>
using namespace std;
int n, k, hff = 1, hgg = 1;
long long a[1000005], f[1000005], g[1000005];
vector<int> ff(1, 0), gg(1, 0);
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P1886.in", "r", stdin);
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	for (int i = 1; i <= k - 1; ++i)
	{
		ff.push_back(a[i]);
		gg.push_back(a[i]);
	}
	for (int i = 1; i <= n - k + 1; ++i)
	{
		if (hff < i)
			hff++;
		int maxx = hff;
		ff.push_back(a[i + k - 1]);
		for (int j = hff + 1; j <= i + k - 1; ++j)
		{
			if (a[j] >= a[maxx])
				maxx = j;
		}
		while (hff < maxx)
			hff++;
		f[i] = a[hff];
	}
	for (int i = 1; i <= n - k + 1; ++i)
	{
		if (hgg < i)
			hgg++;
		int minx = hgg;
		gg.push_back(a[i + k - 1]);
		for (int j = hgg + 1; j <= i + k - 1; ++j)
		{
			if (a[j] <= a[minx])
				minx = j;
		}
		while (hgg < minx)
			hgg++;
		g[i] = a[hgg];
	}
	for (int i = 1; i <= n - k + 1; ++i)
		printf("%lld ", g[i]);
	printf("\n");
	for (int i = 1; i <= n - k + 1; ++i)
		printf("%lld ", f[i]);
	return 0;
}