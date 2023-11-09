#include <cstring>
#include <cstdio>
#include <queue>
#include <string>
using std::queue;
using std::string;

#define min(a, b) a < b ? a : b
#define N 100005
const int INF = (1 << 29);
int tot = 1, head[N << 1], cost[N << 1], to[N << 1], cap[N << 1], nex[N << 1];
int curflow[N], pre[N], vis[N], d[N];
int maxflow, ans;
void add(int x, int y, int c, int z)
{
	++tot;
	to[tot] = y;
	cost[tot] = z;
	cap[tot] = c;
	nex[tot] = head[x];
	head[x] = tot;
}
inline bool spfa(int s, int t)
{
	memset(vis, 0, sizeof vis);
	memset(d, 127, sizeof d);
	queue<int> Q;
	Q.push(s), d[s] = 0, vis[s] = 1, curflow[s] = INF;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		vis[x] = 0;
		for (int i = head[x]; i; i = nex[i])
		{
			int u = to[i];
			if (cap[i] && d[u] > d[x] + cost[i])
			{
				d[u] = d[x] + cost[i];
				pre[u] = i;
				curflow[u] = min(curflow[x], cap[i]);
				if (!vis[u])
					vis[u] = 1, Q.push(u);
			}
		}
	}
	if (d[t] >= INF)
		return 0;
	return 1;
}
inline void update(int s, int t)
{
	int u = t, temp;
	while (u != s)
	{
		temp = pre[u];
		cap[temp] -= curflow[t];
		cap[temp ^ 1] += curflow[t];
		u = to[temp ^ 1];
	}
	maxflow += curflow[t];
	ans += curflow[t] * d[t];
}
int n, m, s, t, st, tt, total[N];
inline void EK()
{
	while (spfa(st, tt))
		update(st, tt);
	maxflow = 0;
	while (spfa(s, t))
		update(s, t);
}
void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P7173");
#endif
	int u, v, c, w;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d%d", &u, &v, &c, &w);
		if (w >= 0)
			add(u, v, c, w), add(v, u, 0, -w);
		else
		{
			add(v, u, c, -w), add(u, v, 0, w);
			total[u] -= c, total[v] += c;
			ans += c * w;
		}
	}
	st = n + 1, tt = n + 2;
	for (int i = 1; i <= n; ++i)
	{
		if (!total[i])
			continue;
		if (total[i] > 0)
			add(st, i, total[i], 0), add(i, st, 0, 0);
		else
			add(i, tt, -total[i], 0), add(tt, i, 0, 0);
	}
	add(t, s, INF, 0), add(s, t, 0, 0),
		EK();
	printf("%d %d\n", maxflow, ans);
	return 0;
}
