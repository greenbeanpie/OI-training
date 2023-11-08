#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
inline int Read()
{
	int x = 0;
	char c = getchar();
	while (c > '9' || c < '0')
		c = getchar();
	while (c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}
const int inf = 1 << 30;
int top = 1, head[10100];
int n, m, s, t;
int e[10100], h[10100], cnth[20100]; // 每个点对应的余流，高度；每个高度有多少个点
struct cmp
{
	inline bool operator()(int a, int b) const
	{
		return h[a] < h[b];
	}
};
struct Node
{
	int v;
	int val;
	int next;
} node[400100];
inline void addedge(int u, int v, int val)
{
	node[++top].v = v;
	node[top].val = val;
	node[top].next = head[u];
	head[u] = top;
}
inline void add(int u, int v, int val)
{
	addedge(u, v, val);
	addedge(v, u, 0);
}
int inque[11000];
void bfs()
{
	memset(h, 0x3f, sizeof(h));
	h[t] = 0;
	queue<int> qu;
	qu.push(t);
	while (!qu.empty())
	{
		int u = qu.front();
		qu.pop();
		inque[u] = 0;
		for (int i = head[u]; i; i = node[i].next)
		{
			int d = node[i].v;
			if (node[i ^ 1].val && h[d] > h[u] + 1)
			{ // 反向跑
				h[d] = h[u] + 1;
				if (inque[d] == 0)
				{
					qu.push(d);
					inque[d] = 1;
				}
			}
		}
	}
	return;
}
priority_queue<int, vector<int>, cmp> q;
inline void push_(int u)
{
	for (int i = head[u]; i; i = node[i].next)
	{
		int d = node[i].v;
		if (node[i].val && h[d] + 1 == h[u])
		{ // 可以推流
			int mi = min(node[i].val, e[u]);
			node[i].val -= mi;
			node[i ^ 1].val += mi;
			e[u] -= mi;
			e[d] += mi;
			if (inque[d] == 0 && d != t && d != s)
			{
				q.push(d);
				inque[d] = 1;
			}
			if (e[u] == 0)
				break; // 已经推完了
		}
	}
} // 推流
inline void relabel(int u)
{
	h[u] = inf;
	for (int i = head[u]; i; i = node[i].next)
	{
		int d = node[i].v;
		if (node[i].val && h[d] + 1 < h[u])
		{
			h[u] = h[d] + 1;
		}
	}
} // 把u的高度更改为与u相邻的最低的点的高度加1
int hlpp()
{
	register int i;
	bfs();
	if (h[s] == 0x3f3f3f3f)
		return 0; // s与t不连通
	h[s] = n;
	for (i = 1; i <= n; i++)
		if (h[i] < 0x3f3f3f3f)
			cnth[h[i]]++; // 统计各个高度的点数，注意不要让下标越界
	for (i = head[s]; i; i = node[i].next)
	{
		int d = node[i].v;
		int mi = node[i].val;
		if (mi)
		{
			e[s] -= mi;
			e[d] += mi;
			node[i].val -= mi;
			node[i ^ 1].val += mi;
			if (d != t && inque[d] == 0 && d != s)
			{
				q.push(d);
				inque[d] = 1;
			}
		}
	} // 从s向周围点推流
	while (!q.empty())
	{
		int u = q.top();
		inque[u] = 0;
		q.pop();
		push_(u);
		if (e[u]&&h[u]<=20000)
		{ // 还有余流
			cnth[h[u]]--;
			if (cnth[h[u]] == 0)
			{
				for (int i = 1; i <= n; i++)
				{
					if (i != s && i != t && h[i] > h[u] && h[i] < n + 1)
					{
						h[i] = n + 1; // 标记无法到达
					}
				}
			} // gap优化
			relabel(u);
			cnth[h[u]]++;
			q.push(u);
			inque[u] = 1;
		}
	}
	return e[t];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P4722.in", "r", stdin);
	freopen("P4722_TJ.out", "w", stdout);
#endif
	n = Read(), m = Read(), s = Read(), t = Read();
	register int i;
	int u, v, val;
	for (i = 1; i <= m; i++)
		u = Read(), v = Read(), val = Read(), add(u, v, val);
	printf("%d", hlpp());
	return 0;
}