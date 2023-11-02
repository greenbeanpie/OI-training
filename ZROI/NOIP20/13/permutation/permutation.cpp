#include <bits/stdc++.h>
#define reg register
// #define int long long
// inline int read()
// {
// 	reg int k = 1, x = 0;
// 	char ch = getchar();
// 	while (ch < '0' || ch > '9')
// 	{
// 		if (ch == '-')
// 			k = -1;
// 		ch = getchar();
// 	}
// 	while (ch >= '0' && ch <= '9')
// 		x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
// 	return k * x;
// }
const int N = 1010;
int n;
std::vector<int> vc[20], tmp;
std::map<std::vector<int>, bool> mp;
int vis[N];
signed main()
{
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	std::cin >> n;
	for (reg int j = 0; j <= 9; j++)
	{
		for (reg int i = 1; i <= n; i++)
			if (i >> j & 1)
				vc[j].push_back(i);
			else
				tmp.push_back(i);
		mp[vc[j]] = 1, mp[tmp] = 1, tmp.clear();
	}
	for (reg int j = 0; j <= 9; j++)
		for (reg int k = 0; k <= 9; k++)
			if (j ^ k)
			{
				tmp.clear();
				for (reg int i = 1; i <= n; i++)
					if ((i >> j & 1) && (i >> k & 1))
						tmp.push_back(i);
				mp[tmp] = 1;
			}
	printf("%lu\n", mp.size());
	for (reg auto vec : mp)
	{
		memset(vis, 0, n + 1 << 2);
		for (reg auto it : vec.first)
			vis[it] = 1;
		for (reg int i = 1; i <= n; i++)
			printf("%d", vis[i]);
		puts("");
	}
	return 0;
}