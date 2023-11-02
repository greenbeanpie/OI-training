#include <bits/stdc++.h>
using namespace std;
#define N 100005
const int p = 998244353;
int n, i, f[N][2][2][2], ans, sz[N], r[N], lst[N], pre[N], x, tmp[2][2][2];
void dfs(int x)
{
	if (!r[x])
		return (void)(f[x][0][0][0] = sz[x] = 1);
	dfs(lst[x]), sz[x] = sz[lst[x]];
	for (int o1 = 0; o1 < 2; o1++)
		for (int o2 = 0; o2 < 2; o2++)
		{
			int u = (f[lst[x]][0][o1][o2] + f[lst[x]][1][o1][o2]) % p;
			if (!r[lst[x]])
				f[x][1][1][1] = 1;
			else
				f[x][1][o1][o2] = f[lst[x]][0][o1][o2];
			f[x][0][o1][o2] = u;
		}
	for (int j = pre[lst[x]]; j; j = pre[j])
	{
		dfs(j);
		memset(tmp, 0, sizeof(tmp));
		if (!r[j])
		{
			for (int o = 0; o < 2; o++)
				for (int o1 = 0; o1 < 2; o1++)
					for (int o2 = 0; o2 < 2; o2++)
					{
						tmp[o][0][o2] = (tmp[o][0][o2] + f[x][o][o1][o2]) % p;
						if (o == 0)
							tmp[1][1][o2] = (tmp[1][1][o2] + f[x][o][o1][o2]) % p;
						if (o1 == 0)
							tmp[o][1][sz[x] == 1 ? 1 : o2] = (tmp[o][1][sz[x] == 1 ? 1 : o2] + f[x][o][o1][o2]) % p;
					}
		}
		else
			for (int o = 0; o < 2; o++)
				for (int o1 = 0; o1 < 2; o1++)
					for (int o2 = 0; o2 < 2; o2++)
						for (int u = 0; u < 2; u++)
							for (int u1 = 0; u1 < 2; u1++)
								for (int u2 = 0; u2 < 2; u2++)
								{
									int v = 1ll * f[x][o][o1][o2] * f[j][u][u1][u2] % p;
									tmp[o][u1][o2] = (tmp[o][u1][o2] + v) % p;
									if (!o && !u)
										tmp[1][u1][o2] = (tmp[1][u1][o2] + v) % p;
									if (!o1 && !u2)
										tmp[o][sz[j] == 1 ? 1 : u1][sz[x] == 1 ? 1 : o2] = (tmp[o][sz[j] == 1 ? 1 : u1][sz[x] == 1 ? 1 : o2] + v) % p;
									if (!o && !u && !o1 && !u2)
										tmp[1][sz[j] == 1 ? 1 : u1][sz[x] == 1 ? 1 : o2] = (tmp[1][sz[j] == 1 ? 1 : u1][sz[x] == 1 ? 1 : o2] + v) % p;
								}
		memcpy(f[x], tmp, sizeof(tmp));
		sz[x] += sz[j];
	}
}
int main()
{
	freopen("value20.in", "r", stdin);
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		scanf("%d", &x), r[x]++, pre[i] = lst[x], lst[x] = i;
	dfs(1);
	for (int o = 0; o < 2; o++)
		for (int o1 = 0; o1 < 2; o1++)
			for (int o2 = 0; o2 < 2; o2++)
			{
				ans = (ans + f[1][o][o1][o2]) % p;
				if (sz[1] > 1 && !o1 && !o2)
					ans = (ans + f[1][o][o1][o2]) % p;
			}
	printf("%d", ans);
	return 0;
}