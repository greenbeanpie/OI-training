//lyxhsx
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int cnt, c, t, n, m, u, v, a[N], b[N], vis[N];//连n+1代表T,n+1F,n+3U
char op;

int find (int x)
{
	int y = x, z;
	while (x != a[x])
		x = a[x];
	while (y != a[y])
	{
		z = y;
		y = a[y];
		a[z] = x;
	}
	return x;
//	return x == a[x] ? x : a[x] = find (a[x]);
}

int main ()
{
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> m;
		for (int i = 1; i <= n + 3; ++ i)
			a[i] = i, b[i] = 1, vis[i] = 0;
		for (int i = 1; i <= m; ++ i)
		{
			cin >> op;
			scanf ("%d", &u);
			if (op == 'T')
				a[u] = n + 1;
			if (op == 'F')
				a[u] = n + 2;
			if (op == 'U')
				a[u] = n + 3;
			if (op == '+')
				scanf ("%d", &v), a[u] = a[v], b[u] = b[v];
			if (op == '-')
				scanf ("%d", &v), a[u] = a[v], b[u] = -b[v];
		}
		int ans = 0;
		for (int i = 1; i <= n; ++ i)
		{
			if (!vis[i])
			{
				int x = i;
				while (1)
				{
					if (x > n || (vis[x] != i && vis[x]))
						break ;
					if (vis[x] == i)
					{
						int s = x, c = 1;
						while (a[x] != s)
						{
							c *= b[x];
							x = a[x];
						}
						c *= b[x];
						if (c == -1)
							a[x] = n + 3;
						else
							a[x] = 0;
						break ;
					}
					else
					{
						vis[x] = i;
						x = a[x];
					}
				}
			}
		}
		for (int i = 1; i <= n; ++ i)
			if (find (i) == n + 3)
				++ ans;
		cout << ans << '\n';
	}
	return 0;
}
