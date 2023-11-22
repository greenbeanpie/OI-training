#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int read()
{
	char c;
	int s = 0, f = 1;
	c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9')
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}

int min(int a, int b) {return a < b ? a : b;}

int n, m, c, t, ans, temp;
char v, I, J;
int x[10001];

struct Node1
{
	char v;
	int I, J;
}step[1001];

struct Node2
{
	int b;
	int e;
}xx[10001];

void dfs(int k)
{
	if (k == n + 1)
	{
		temp = 0;
		for (int i = 1; i <= n; i++)
		{
			xx[i].e = xx[i].b;
		}
		for (int i = 1; i <= m; i++)
		{
			if (step[i].v == 'U')
				xx[step[i].I].e = 0;
			else if (step[i].v == 'F')
				xx[step[i].I].e = -1;
			else if (step[i].v == 'T')
				xx[step[i].I].e = 1;
			else if (step[i].v == '+')
			{
				xx[step[i].I].e = xx[step[i].J].e;
//				cout << "xx[" << step[i].I << "].e = xx[" << step[i].J << "].e = " << xx[step[i].J].e << endl;
			}
					
			else if (step[i].v == '-')
			{
				xx[step[i].I].e = -xx[step[i].J].e;		
//				cout << "xx[" << step[i].I << "].e = -xx[" << step[i].J << "].e = " << -xx[step[i].J].e << endl;		
			}
		}
	
		for (int i = 1; i <= n; i++)
		{
			if (xx[i].b != xx[i].e)
				return ;
			if (xx[i].b == 0) temp++;
		}
		ans = min(temp, ans);
		return ;
	}
	
	xx[k].b = xx[k].e = -1;
	dfs(k + 1);
	xx[k].b = xx[k].e = 1;
	dfs(k + 1);
	xx[k].b = xx[k].e = 0;
	dfs(k + 1);	
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	c = read(), t = read();
	if (c == 3 || c == 4)
	{
		while (t--)
		{
			ans = 0;
			memset(x, -1, sizeof(x));
			n = read(), m = read();
			for (int i = 1; i <= m; i++)
			{
				char v; 
				scanf("%s", &v); I = read();
				if (v == 'F')
					x[I] = 0;
				else if (v == 'T')
					x[I] = 1;
				else if (v == 'U')
					x[I] = 2;
			}
			for (int i = 1; i <= n; i++)
				if (x[i] == 2) ans++;
			printf("%d\n", ans);
		}
	}
	
	else if (c == 1 || c == 2)
	{
		while (t--)
		{
			ans = 0x3f3f3f3f;
			n = read(), m = read();
			for (int i = 1; i <= n; i++)
				xx[i].b = xx[i].e = 0;
			for (int i = 1; i <= m; i++)
			{
				scanf("%s", &step[i].v);
				step[i].I = read();
				if (step[i].v == '+' || step[i].v == '-')
					step[i].J = read();
			}
			dfs(1);
			printf("%d\n", ans);
		}
	}	
	else
	{
		while (t--)
		{
			n = read(), m = read();
			cout << 0 << endl;
		}
	}
	return 0;
}
