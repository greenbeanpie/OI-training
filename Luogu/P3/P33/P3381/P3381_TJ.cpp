#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 5001;
const int MAXM = 50001;
int n, m, s, t, tot = 1;
int maxflow, mincost;
int dis[MAXN], head[MAXN], curflow[MAXN], last[MAXN]; // dis表示最短路，incf表示当前增广路上最小流量，pre表示前驱
bool vis[MAXN];
struct Edge
{
	int nxt, to, weight, val;
} e[MAXM << 1];
inline void addedge(int u, int v, int val, int w)
{
	e[++tot].nxt = head[u];
	e[tot].to = v;
	e[tot].weight = w;
	e[tot].val = val;
	head[u] = tot;
}
bool spfa()
{
	queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	curflow[s] = 1 << 30;
	while (!q.empty())
	{
		int u = q.front();
		vis[u] = 0;
		q.pop();
		for (auto i = head[u]; i; i = e[i].nxt)
		{
			if (!e[i].val)
			{
				continue;
			}
			int v = e[i].to;
			if (dis[v] > dis[u] + e[i].weight)
			{
				dis[v] = dis[u] + e[i].weight;
				curflow[v] = min(curflow[u], e[i].val);
				last[v] = i;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if (dis[t] == 1061109567)
		return 0;
	return 1;
}
void MCMF()
{
	while (spfa())
	{ // 如果有增广路
		int cur = t;
		maxflow += curflow[t];
		mincost += dis[t] * curflow[t];
		int temp;
		while (cur != s)
		{
			temp = last[cur];
			e[temp].val -= curflow[t];
			e[temp ^ 1].val += curflow[t];
			cur = e[temp ^ 1].to;
		}
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3381.in", "r", stdin);
	freopen("P3381_TJ.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int u, v, w, x, i = 1; i <= m; ++i)
	{
		scanf("%d%d%d%d", &u, &v, &w, &x);
		addedge(u, v, w, x);
		addedge(v, u, 0, -x); // 反向边费用为-f[i]
	}
	MCMF(); // 最小费用最大流
	printf("%d %d\n", maxflow, mincost);
	return 0;
}
