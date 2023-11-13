#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
struct edge
{
	int to, nxt;
} e[maxn << 1];
int n, cnt, id;
int head[maxn];
long long ans;
long long f[maxn], dep[maxn], size[maxn];
inline void add(int u, int v)
{
	e[++cnt].nxt = head[u];
	head[u] = cnt;
	e[cnt].to = v;
}
void dfs1(int x, int fa)
{
	size[x] = 1;
	dep[x] = dep[fa] + 1;
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int y = e[i].to;
		if (y == fa)
			continue;
		dfs1(y, x);
		size[x] += size[y];
	}
}
void dfs2(int x, int fa)
{
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int y = e[i].to;
		if (y == fa)
			continue;
		f[y] = f[x] + n - 2 * size[y];
		dfs2(y, x);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P3478.in", "r", stdin);
	freopen("P3478_TJ.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs1(1, 0);
	for (int i = 1; i <= n; i++)
		f[1] += dep[i];
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		if (ans < f[i])
			ans = f[i], id = i;
	printf("%d", id);
	return 0;
}
