#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

char c;
struct Node
{
	string o, b, s;
}str[3001];

int n, m, temp[3001];
int flag = 1;

bool cmp1(int a, int b)
{
	return a < b;
}
bool cmp2(int a, int b)
{
	return a > b;
}

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

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[j] = int(getchar());
		}
		getchar();
		sort(temp, temp + m, cmp1); //s
		for (int j = 0; j < m; j++)
			str[i].s = str[i].s + char(temp[j]);
		sort(temp, temp + m, cmp2); //b
		for (int j = 0; j < m; j++)
			str[i].b = str[i].b + char(temp[j]);
	}
	
	for (int i = 1; i <= n; i++)
	{
		c = '1';
		for (int j = 1; j <= n; j++)
		{
			if ((i != j) && (str[i].s > str[j].b))
			{c = '0';	break;}
		}
		putchar(c);
	}
	
	return 0;
}
