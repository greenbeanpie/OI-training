#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
long long read()
{
	char ch = getchar();
	long long a = 0, x = 1;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			x = -x;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		a = (a << 1) + (a << 3) + (ch - '0');
		ch = getchar();
	}
	return a * x;
}
const int N = 4e6 + 5;
int n, m, a, b, x, y, tim, top, edge_sum, scc_sum;
int dfn[N], low[N], st[N], vis[N], scc[N], head[N];
struct node
{
	int to, next;
} A[N];
void add(int from, int to)
{
	edge_sum++;
	A[edge_sum].next = head[from];
	A[edge_sum].to = to;
	head[from] = edge_sum;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = A[i].next)
	{
		int v = A[i].to;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		scc_sum++;
		while (st[top] != u)
		{
			scc[st[top]] = scc_sum;
			vis[st[top]] = 0;
			top--;
		}
		scc[st[top]] = scc_sum;
		vis[st[top]] = 0;
		top--;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P4782.in", "r", stdin);
	freopen("P4782_TJ.out", "w", stdout);
#endif
	n = read();
	m = read();
	for (int i = 1; i <= m; i++)
	{
		a = read();
		x = read(); // 第a个数为x或第b个数为y
		b = read();
		y = read();
		if (x == 0 && y == 0) //"如果第a个数为0或第b个数为0"至少满足其一
		{
			add(a + n, b); // a=1则b=0
			add(b + n, a); // b=1则a=0
		}
		if (x == 0 && y == 1) //"如果第a个数为0或第b个数为1"至少满足其一
		{
			add(a + n, b + n); // a=1则b=1
			add(b, a);		   // b=0则a=0
		}
		if (x == 1 && y == 0) //"如果第a个数为1或第b个数为0"至少满足其一
		{
			add(a, b);		   // a=0则b=0
			add(b + n, a + n); // b=1则a=1
		}
		if (x == 1 && y == 1) //"如果第a个数为1或第b个数为1"至少满足其一
		{
			add(a, b + n); // a=0则b=1
			add(b, a + n); // b=0则a=1
		}
	}
	for (int i = 1; i <= 2 * n; i++) // 对每个变量的每种取值进行tarjan
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i++) // 判断无解的情况
	{
		if (scc[i] == scc[i + n]) // 同一变量的两种取值在同一强联通分量里,说明无解
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	printf("POSSIBLE\n"); // 否则就是有解
	for (int i = 1; i <= n; i++)
	{
		if (scc[i] > scc[i + n])
			printf("1 "); // 强联通分量编号越小 -> 拓扑序越大 -> 越优
		else
			printf("0 ");
	}
	return 0;
}
