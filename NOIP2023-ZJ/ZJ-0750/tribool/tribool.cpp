#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int c, T;
int a[maxn * 2];
int fa[maxn * 2];
int sum[maxn * 2];
int n, m;
bool wa[maxn * 2];
int ans;

void build()
{
	ans = 0;
	memset(wa, 0, sizeof(wa));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= 2 * n + 10; i++)
	{
		a[i] = i;
		fa[i] = i;
	}
	for (int i = 1; i<= n; i++)
	{
		sum[i] = 1;
	}
}

int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void join(int x, int y)
{
	int xx = find(x), yy = find(y);
	if (xx != yy)
	{
		fa[xx] = yy;
		sum[yy] += sum[xx];
	}
}

bool issame(int x, int y)
{
	if (find(x) == find(y)) return true;
	return false;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> m;
		build();
		for (int i = 1; i <= m; i++)
		{
			char x;
			cin >> x;
			int u, v, y;
			switch(x)
			{
				case '+':
					cin >> u >> v;
					a[u] = a[v];
					break;
				case '-':
					cin >> u >> v;
					y = (a[v] + n + 3) % (2 * n + 6);
					if (y == 0) y = 2 * n + 6;
					a[u] = a[y];
					break;
				case 'T':
					cin >> u;
					a[u] = a[n + 1];
					break;
				case 'F':
					cin >> u;
					a[u] = a[n + 2];
					break;
				case 'U':
					cin >> u;
					a[u] = a[n + 3];
					break;
				default:
					break;
			}
		}
		join(n + 3, 2 * n + 6);
		for (int i = 1; i <= n; i++)
		{
			join(i, a[i]);
			int x = (a[i] + n + 3) % (2 * n + 6);
			if (!x) x = 2 * n + 6;
			join(x, i + n + 3);
		}
		for (int i = 1; i <= n; i++)
		{
			if (issame(i, i + n + 3))
			{
				wa[find(i)] = true;
			}
		}
		wa[find(n + 3)] = true;
		wa[find(2 * n + 6)] = true;
		for (int i = 1; i <= 2 * n + 6; i++)
		{
			if (wa[i])
			{
				ans += sum[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
