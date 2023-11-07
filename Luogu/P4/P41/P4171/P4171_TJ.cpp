// niiick
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long lt;

int read()
{
	int f = 1, x = 0;
	char ss = getchar();
	while (ss < '0' || ss > '9')
	{
		if (ss == '-')
			f = -1;
		ss = getchar();
	}
	while (ss >= '0' && ss <= '9')
	{
		x = x * 10 + ss - '0';
		ss = getchar();
	}
	return f * x;
}

const int maxn = 400;
int t, n, m;
struct node
{
	int v, nxt;
} E[4010];
int head[maxn], tot;
int low[maxn], dfn[maxn], cnt, judge;
int col[maxn], ins[maxn], colnum;
stack<int> st;
char s1[5], s2[5];

void add(int u, int v)
{
	E[++tot].nxt = head[u];
	E[tot].v = v;
	head[u] = tot;
}

void tarjan(int u)
{
	low[u] = dfn[u] = ++cnt;
	st.push(u);
	ins[u] = 1;
	for (int i = head[u]; i; i = E[i].nxt)
	{
		int v = E[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		int v;
		colnum++;
		do
		{
			v = st.top();
			st.pop();
			ins[v] = 0;
			col[v] = colnum;
		} while (v != u);
	}
}

void init()
{
	judge = tot = cnt = colnum = 0;
	memset(head, 0, sizeof(head));
	memset(col, 0, sizeof(col));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	// memset(ins,0,sizeof(ins));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("P4171.in", "r", stdin);
	freopen("P4171_TJ.out", "w", stdout);
#endif
	t = read();
	while (t--)
	{
		init();
		n = read();
		m = read();
		for (int i = 1; i <= m; ++i) // h-1,m-0
		{
			scanf("%s%s", &s1, &s2);
			int u = 0, v = 0, k;
			k = 1;
			while (s1[k] >= '0' && s1[k] <= '9')
				u = u * 10 + s1[k++] - '0';
			k = 1;
			while (s2[k] >= '0' && s2[k] <= '9')
				v = v * 10 + s2[k++] - '0';
			if (s1[0] == 'm')
			{
				if (s2[0] == 'h')
					add(u + n, v + n), add(v, u);
				else if (s2[0] == 'm')
					add(u + n, v), add(v + n, u);
			}
			else if (s1[0] == 'h')
			{
				if (s2[0] == 'h')
					add(u, v + n), add(v, u + n);
				else if (s2[0] == 'm')
					add(u, v), add(v + n, u + n);
			}
		}

		for (int i = 1; i <= n << 1; ++i)
			if (!dfn[i])
				tarjan(i);

		for (int i = 1; i <= n; ++i)
			if (col[i] == col[i + n])
			{
				judge = 1;
				break;
			}

		if (judge)
			printf("BAD\n");
		else
			printf("GOOD\n");
	}
	return 0;
}
