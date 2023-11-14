#pragma once
#include <bits/stdc++.h>
#include <bits/extc++.h>

const int N = 1e5, M = 1e6;
int n /* 点数 */, m /* 边数 */, s /* 源点 */, t /* 汇点 */, tot = 1 /* 总边数/当前已建边数 */;
int head[N] /* 前向星 */, dep[N] /* 对应点深度 */, depcnt[N] /* 对应深度点数 */, left[N] /* 节点余流 */;
std::bitset<N> inque; /* 是否在队列中 */
struct node
{
	int to, val, nxt;
} e[M];
struct cmp
{
	bool operator()(const int &a, const int b)
	{
		return dep[a] < dep[b];
	}
};
std::queue<int> q;
#ifdef CODESPACE
std::priority_queue<int, std::vector<int>, cmp> pq;
#else
__gnu_pbds::priority_queue<int, cmp> pq;
#endif
void add_edge(int u, int v, int w)
{
	++tot;
	e[tot].nxt = head[u];
	head[u] = tot;
	e[tot].to = v;
	e[tot].val = w;
	++tot;
	std::swap(u, v);
	e[tot].nxt = head[u];
	head[u] = tot;
	e[tot].val = 0;
	e[tot].to = v;
}

bool bfs()
{
	memset(dep, 0x3f3f3f, sizeof(dep));
	dep[t] = 0;
	q.push(t);
	inque[t] = 1;
	while (q.size()) // 标高度
	{
		auto now = q.front();
		q.pop();
		inque[now] = 0;
		for (auto i = head[now]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (e[i ^ 1].val && dep[v] > dep[now] + 1)
			{ // 跑反向边
				dep[v] = dep[now] + 1;
				if (!inque[v])
				{
					q.push(v);
					inque[v] = 1;
				}
			}
		}
	}
	return dep[s] == INT_MAX; // 判断能否到达
}
void push(int u)
{
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (e[i].val && dep[v] + 1 == dep[u])
		{
			int temp = std::min(e[i].val, left[u]);
			e[i].val -= temp;
			e[i ^ 1].val += temp;
			left[u] -= temp;
			left[v] += temp;
			if (!inque[v] && v != t && v != s)
			{
				pq.push(v);
				inque[v] = 1;
			}
			if (!left[u])
			{ // 已经没有多余的流量可以推了
				break;
			}
		}
	}
}
void relabel(int u)
{
	dep[u] = 0x3f3f3f;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (e[i].val && dep[v] + 1 < dep[u])
		{
			dep[u] = dep[v] + 1;
		}
	}
} // 将u的节点高度改为和u最近的最低点+1
int HLPP()
{
	if (bfs())
	{
		return 0;
	}
	// inque.reset();
	dep[s] = n;
	for (int i = 1; i <= n; i++)
	{
		if (dep[i] <= N)
		{
			++depcnt[dep[i]];
		}
	}
	for (int i = head[s]; i; i = e[i].nxt)
	{
		int v = e[i].to, val = e[i].val;
		if (val)
		{
			left[s] -= val;
			left[v] += val;
			e[i].val -= val;
			e[i ^ 1].val += val;
			// cerr << inque[v] << " ";
			if (!inque[v] && v != s && v != t)
			{
				pq.push(v);
				inque[v] = 1;
			}
		}
	}
	while (pq.size())
	{
		auto u = pq.top();
		pq.pop();
		inque[u] = 0;
		push(u);
		if (left[u] && dep[u] <= N)
		{
			--depcnt[dep[u]];
			if (depcnt[dep[u]] == 0)
			{ // 重标高度
				for (int i = 1; i <= n; i++)
				{
					if (i != s && i != t && dep[i] > dep[u] && dep[i] <= n)
					{
						dep[i] = n + 1;
					}
				}
			}
			relabel(u);
			++depcnt[dep[u]];
			pq.push(u);
			inque[u] = 1;
		}
	}
	return left[t];
}
