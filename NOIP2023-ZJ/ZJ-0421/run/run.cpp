#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int inf = 1e18;
int n, m, k, d;
long long ans;
int C, t;
int b[MAXN], c[MAXN], sum[MAXN];
struct node {
	int l, r;
	long long v;
} a[MAXN];
void dfs(int pos, int lim)
{
	if (pos == n + 1)
	{
		long long res = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + b[i];
			if (b[i])
				res -= d;
		}
		for (int i = 1; i <= m; i++)
			if (sum[a[i].r] - sum[a[i].l - 1] == a[i].r - a[i].l + 1)
				res += a[i].v;
		ans = max(ans, res);
		return;
	}
	if(!c[pos] || lim == k)
	{
		b[pos] = 0;
		dfs(pos + 1, 0);
	}
	else
	{
		for (int i = 0; i <= 1; i++)
		{	
			b[pos] = i;
			dfs(pos + 1, lim * i + i);
		}
	}
}
void work()
{
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%lld", &a[i].r, &a[i].l, &a[i].v);
		a[i].l = a[i].r - a[i].l + 1;
	}
	if (C <= 2)
	{
		ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = a[i].l; j <= a[i].r; j++)
				c[j] = 1;
		dfs(1, 0);
		cout << ans << endl;
		return;
	}
	else if (C == 17 || C == 18)
	{
		ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int len = a[i].r - a[i].l + 1;
			a[i].v -= len * d;
			if (a[i].v < 0 || len > k) a[i].v = 0;
			ans += a[i].v;
		}
		printf("%lld\n", ans);
		return;
	}
	
}
signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &C, &t);
	while (t--)
		work();
	return 0;
}