#include <iostream>
#include <string>
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

int x[10001], y[10001];
int c, n, m, q, kx, ky, px, vx, py, vy;

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		x[i] = read();
	for (int i = 1; i <= m; i++)
		y[i] = read();
	if (c == 1)
	{
		if (x[1] != y[1])
			putchar('1');
		else putchar('0');
		for (int i = 1; i <= q; i++)
		{
			kx = read(), ky = read();
			for (int i = 1; i <= kx; i++)
			{
				px = read(), vx = read();
				x[px] = vx;	
			}
			for (int i = 1; i <= ky; i++)
			{
				py = read(), vy = read();
				y[py] = vy;
			}
			if (x[1] != y[1])
				putchar('1');
			else putchar('0');
		}
	}
	else if (c == 2)
	{
		if (x[1] != y[1] && x[1] != y[2])
			putchar('1');
		else putchar('0');
		for (int i = 1; i <= q; i++)
		{
			kx = read(), ky = read();
			for (int i = 1; i <= kx; i++)
			{
				px = read(), vx = read();
				x[px] = vx;	
			}
			for (int i = 1; i <= ky; i++)
			{
				py = read(), vy = read();;
				y[py] = vy;
			}
			if (x[1] != y[1] && x[1] != y[2])
				putchar('1');
			else putchar('0');
		}	
	}
	else
	{
		for (int i = 1; i <= q + 1; i++)
			putchar('0');
	}
	return 0;
}
