#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010
using namespace std;
int n, m, S, T, tmp1, tmp2, tot;
int en = 1, head[N], h[N], q[N], ans1[N], ans2[N];
struct Edge
{
	int to, next, v;
} e[N];
bool b[N];
inline void insert(int u, int v, int f)
{
	e[++en].to = v;
	e[en].v = f;
	e[en].next = head[u];
	head[u] = en;
	e[++en].to = u;
	e[en].v = 0;
	e[en].next = head[v];
	head[v] = en;
}
inline bool bfs()
{
	int f = 0, t = 0;
	memset(h, -1, sizeof(h));
	q[t++] = S;
	h[S] = 0;
	while (f < t)
	{
		int now = q[f++];
		for (int i = head[now]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (h[v] == -1 && e[i].v)
			{
				h[v] = h[now] + 1;
				q[t++] = v;
			}
		}
	}
	if (h[T] != -1)
		return 1;
	return 0;
}
inline int dfs(int x, int f)
{
	if (x == T)
		return f;
	int w, used = 0;
	for (int i = head[x]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (h[v] == h[x] + 1 && e[i].v)
		{
			w = dfs(v, min(f - used, e[i].v));
			e[i].v -= w;
			e[i ^ 1].v += w;
			used += w;
			if (used == f)
				return f;
		}
	}
	if (!used)
		h[x] = -1;
	return used;
}
void dinic()
{
	while (bfs())
		tot += dfs(S, 0x3f3f3f3f);
}
int main()
{
	scanf("%d %d", &m, &n);
	S = 0, T = n + 1;
	scanf("%d %d", &tmp1, &tmp2);
	do
	{
		insert(tmp1, tmp2, 0x3f3f3f3f);
		scanf("%d %d", &tmp1, &tmp2);
	} while (tmp1 != -1 && tmp2 != -1);
	for (int i = 1; i <= m; i++)
		insert(S, i, 1);
	for (int i = m + 1; i <= n; i++)
		insert(i, T, 1);
	dinic();
	if (tot == 0)
	{
		puts("No Solution!");
		return 0;
	}
	printf("%d\n", tot);
	for (int i = 2; i <= en; i = i + 2)
	{
		if (e[i].to != S && e[i ^ 1].to != S)
			if (e[i].to != T && e[i ^ 1].to != T)
				if (e[i ^ 1].v != 0)
				{
					printf("%d %d\n", e[i ^ 1].to, e[i].to);
				}
	}
	return 0;
}
