#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll inf = 1ll << 41, inf2 = 1ll << 52, ans;
#define N 1005
int n, m, i, x, y, cc, tot = 1, lst[N], a[N], b[N], c[N];
struct node
{
	int y, n;
	ll z;
} d[N << 3];
void cun(int x, int y, ll z)
{
	d[++tot] = node{y, lst[x], z};
	lst[x] = tot;
}
int dis[N], q[N], l, r, cur[N];
bool bfs()
{
	memset(dis, 127, sizeof(int) * (n * 2 + 3));
	memcpy(cur, lst, sizeof(int) * (n * 2 + 2));
	dis[q[l = r = 1] = 0] = 0;
	while (l <= r)
	{
		for (int j = lst[q[l]]; j; j = d[j].n)
			if (d[j].z && dis[d[j].y] > dis[q[l]] + 1)
				dis[q[++r] = d[j].y] = dis[q[l]] + 1;
		l++;
	}
	return dis[n * 2 + 1] != dis[n * 2 + 2];
}
ll dfs(int x, ll f)
{
	if (x == n * 2 + 1)
		return f;
	ll tmp = f;
	for (int &j = cur[x]; j; j = d[j].n)
		if (d[j].z && dis[d[j].y] == dis[x] + 1)
		{
			ll t = dfs(d[j].y, min(d[j].z, tmp));
			if (t)
			{
				d[j].z -= t, d[j ^ 1].z += t, tmp -= t;
				if (!tmp)
					break;
			}
			else
				dis[d[j].y] = -2;
		}
	return f - tmp;
}
int main()
{
	freopen("currency20.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (i = 1; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (i = 1; i < n; i++)
		scanf("%d", &c[i]);
	a[n - 1] += b[n], c[1] += b[1];
	for (i = 1; i < n; i++)
		cun(0, i, inf - a[i]), cun(i, 0, 0), ans += a[i];
	for (i = 1; i < n; i++)
		cun(i + n, n * 2 + 1, inf - c[i]), cun(n * 2 + 1, i + n, 0), ans += c[i];
	for (i = 1; i < n; i++)
		cun(i, i + n, inf2), cun(i + n, i, 0);
	for (i = 2; i < n; i++)
		cun(i - 1, n + i, b[i]), cun(n + i, i - 1, 0), cun(i, n + i - 1, b[i]), cun(n + i - 1, i, 0); // 10n
	for (i = 1; i <= m; i++)
		scanf("%d%d%d", &x, &y, &cc), cun(x, y + n, cc), cun(y + n, x, 0); // 2m
	while (bfs())
		ans += dfs(0, 1ll << 60);
	printf("%lld", ans - inf * (n - 1));
	return 0;
}