#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

struct node
{
	int x, y;
	bool z = 0;
} q[5005];
int fa[10010];
int find(int u)
{
	if (fa[u] == u)
		return u;
	return fa[u] = find(fa[u]);
}
void merge(int u, int v)
{
	fa[find(u)] = find(v);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P5937.in", "r", stdin);
	freopen("P5937.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int tot = 0;
	int b[10010];
	string a;
	for (int i = 1; i <= m; i++)
	{
		cin >> q[i].x >> q[i].y >> a;
		q[i].x--;
		if (a == "odd")
		{
			q[i].z = 1;
		}
		b[++tot] = q[i].x;
		b[++tot] = q[i].y;
	}
	sort(b + 1, b + 1 + tot,less<int>());
	int l = unique(b + 1, b + 1 + tot) - b - 1;
	for (int i = 1; i <= 2*l; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		q[i].x = lower_bound(b + 1, b + 1 + l, q[i].x) - b;
		q[i].y = lower_bound(b + 1, b + 1 + l, q[i].y) - b;
	}
	for (int i = 1; i <= m; i++)
	{
		if (q[i].z)
		{
			if (find(q[i].x) == find(q[i].y)||find(q[i].x+l)==find(q[i].y+l))
			{
				cout << i - 1;
				return 0;
			}
			else
			{
				merge(q[i].x, q[i].y + l);
				merge(q[i].x + l, q[i].y);
			}
		}
		else
		{
			if (find(q[i].x) == find(q[i].y + l)||find(q[i].x+l)==find(q[i].y))
			{
				cout << i - 1;
				return 0;
			}
			else
			{
				merge(q[i].x, q[i].y);
				merge(q[i].x + l, q[i].y + l);
			}
		}
	}
	cout << m;
	return 0;
}