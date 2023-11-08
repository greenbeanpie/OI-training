#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;					// inf:最大值
int cnt = 1, head[505], cur[505], val[505]; // cnt:第CNT条边head[i]:第i个点属于第几条边
int n, m, s, t;								// n个点m条边s:源点t:汇点
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
struct Node
{
	int v;		// 当前点
	int next;	// 连接点
	int val;	// 容量
} node[100010]; // node[i]:第i条边的情况
inline void addedge(int u, int v, int val)
{
	node[++cnt].v = v;
	node[cnt].val = val;
	node[cnt].next = head[u];
	head[u] = cnt;
}
int dep[505], gap[505]; // dep[i]表示节点i的深度，gap[i]表示深度为i的点的数量
void bfs()				// 倒着搜
{
	memset(dep, -1, sizeof(dep)); // 把深度变为-1(0会导致gap崩坏)
	memset(gap, 0, sizeof(gap));
	dep[t] = 0; // 汇点深度为0
	gap[0] = 1; // 深度为0的点有1个
	queue<int> q;
	q.push(t); // t点入栈
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = node[i].next) // head[u]:u点所在的边,node[i].next:u点所在的边的下一个点，就这样遍历下去
		{
			int v = node[i].v; // v为当前边的下一个点
			if (dep[v] != -1)
				continue; // dep[v]!=-1相当于v点已被遍历||不管
			q.push(v);
			dep[v] = dep[u] + 1; // v点的深度比u点大1
			gap[dep[v]]++;
		} // 直到所有点都被遍历过
	}
	return;
} // 从t到s跑一遍bfs，标记深度
long long maxflow;
int dfs(int u, int flow)
{
	if (u == t)
	{
		maxflow += flow;
		return flow;
	}
	int used = 0;
	for (int p = cur[u]; p; p = node[p].next)
	{
		cur[u] = p; // 更新当前弧
		int v = node[p].v;
		if (val[p] && dep[v] + 1 == dep[u])
		{
			int mi = dfs(v, min(flow - used, val[p]));
			if (mi)
			{
				val[p] -= mi;
				val[p ^ 1] += mi;
				used += mi;
			}
			if (used == flow)
				return used;
		}
	}
	if (--gap[dep[u]] == 0)
		dep[s] = n + 1;
	dep[u]++;
	gap[dep[u]]++;
	return used;
}

inline long long ISAP()
{
	maxflow = 0;
	bfs();
	while (dep[s] < n)
		memcpy(cur, head, sizeof(head)), dfs(s, inf);
	return maxflow;
}

void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + "_TJ.out").c_str(), "w", stdout);
}

int main()
{
	FileIO("P3376");
	n = Read(), m = Read(), s = Read(), t = Read();
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		u = Read();
		v = Read();
		w = Read();
		addedge(u, v, w); // 正向边
		addedge(v, u, 0); // 反向边
	}
	printf("%lld\n", ISAP());
	return 0;
}
