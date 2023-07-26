#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

const int N = 5e4 + 5;
int fa[N * 3];
int find(int u)
{
	if (fa[u] == u)
		return u;
	return fa[u] = find(fa[u]);
}
void merge(int u, int v)
{
	u=find(u);
	v=find(v);
	fa[v] = u;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P2024.in", "r", stdin);
	freopen("P2024.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int op, u, v, cnt = 0;
	for (int i = 1; i <= 3 * n; i++)
	{
		fa[i] = i;
	}

	for (int i = 1; i <= k; i++)
	{
		cin >> op >> u >> v;
		if (u > n || v > n)
		{
			cnt++;
			continue;
		}
		if (op == 1)
		{
			if (find(u + n) == find(v) || find(u) == find(v + n))
			{
				cnt++;
			}
			else
			{
				merge(u, v);
				merge(u + n, v + n);
				merge(u + n + n, v + n + n);
			}
		}
		else
		{
			if (find(u) == find(v) || find(u) == find(v + n))
			{
				cnt++;
			}
			else
			{
				merge(u + n, v);
				merge(u + n + n, v + n);
				merge(u, v + n + n);
			}
		}
	}
	cout << cnt;
	return 0;
}