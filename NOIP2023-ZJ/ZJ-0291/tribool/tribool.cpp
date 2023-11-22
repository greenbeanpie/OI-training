#include <bits/stdc++.h>
using namespace std;
const int Not[3] = {1, 0, 2};
int n, m, l[100010], p[100010], ans, c, t;
struct node
{
	char opt;
	int a, b;
}cmd[100010];
void Fre()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	return;
}

void dfs(int now,int ukn)
{
	if (ukn >= ans) return;
	if (now > n)
	{
		for (int i = 1; i <= m; i++) l[i] = p[i];
		for (int i = 1; i <= m; i++)
			if (cmd[i].opt == 'T')
				l[cmd[i].a] = 0;
			else if (cmd[i].opt == 'F')
				l[cmd[i].a] = 1;
			else if (cmd[i].opt == 'U')
				l[cmd[i].a] = 2;
			else if (cmd[i].opt == '+')
				l[cmd[i].a] = l[cmd[i].b];
			else
				l[cmd[i].a] = Not[l[cmd[i].b]];
		int flag = 1;
		for (int i = 1; i <= m; i++)
			if (l[i] != p[i])
			{
				flag = 0;
				break;
			}
		if (flag) ans = ukn;
		return;
	}
	p[now] = 0; dfs(now + 1, ukn);
	p[now] = 1; dfs(now + 1, ukn);
	p[now] = 2; dfs(now + 1, ukn + 1);
	return;
}
void Subwork1()
{
	for (int i = 1; i <= m; i++) 
		{
			scanf("%c", &cmd[i].opt);
			if (cmd[i].opt == '+' || cmd[i].opt == '-')
				scanf("%d %d\n", &cmd[i].a, &cmd[i].b);
			else
				scanf("%d\n", &cmd[i].a);
		}
	ans = n;
	dfs(1, 0);
	printf("%d\n", ans);
	return;
}

void Subwork2()
{
	char op;
	int x;
	for (int i = 1; i <= n; i++) p[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%c %d\n", &op, &x);
		if (op == 'T') p[x] = 0;
		else if (op == 'F') p[x] = 1;
		else p[x] = 2;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) ans += (p[i] == 2);
	printf("%d\n", ans);
	return;
}

int find(int x)
{
	return (x == l[x]) ? x : l[x] = find(l[x]);
}
void Subwork3()
{
	char op;
	int x, y;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("%c", & op);
		if (op == '+')
		{
			scanf("%d %d\n", &x, &y);
			p[x] = p[y];
		}
		else
		{
			scanf("%d\n", &x);
			p[x] = 0;
		}
	}
	for (int i = 0; i <= n; i++) l[i] = i;
	for (int i = 1; i <= n; i++)
	{
		x = find(i);
		y = find(p[i]);
		if (x != y)
			l[x] = y;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) ans += (find(i) == 0);
	printf("%d\n", ans);
	return;
}

signed main()
{
	Fre();
	for (scanf("%d %d", &c, &t); t; t--)
	{
		scanf("%d %d\n", &n, &m);
		if (c == 1 || c == 2)
			Subwork1();
		else if (c == 3 || c == 4)
			Subwork2();
		else if (c == 5 || c == 6)
			Subwork3();
//		else 
//			Work();
	}
	return 0;
}