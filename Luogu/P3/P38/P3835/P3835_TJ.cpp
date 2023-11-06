#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define go(i, j, n, k) for (int i = j; i <= n; i += k)
#define fo(i, j, n, k) for (int i = j; i >= n; i -= k)
#define rep(i, x) for (int i = h[x]; i; i = e[i].nxt)
#define mn 500010
#define ld long double
#define fi first
#define se second
#define inf 1 << 30
#define ll long long
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define bson l, r, rt
inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct edge
{
	int ch[2], sze, pri;
	ll w;
} z[mn * 50];
int rot[mn], xx, yy, zz, n, cnt;
inline void update(int rt)
{
	z[rt].sze = 1;
	if (z[rt].ch[0])
		z[rt].sze += z[z[rt].ch[0]].sze;
	if (z[rt].ch[1])
		z[rt].sze += z[z[rt].ch[1]].sze;
}
inline int newnode(ll w = 0)
{
	z[++cnt].w = w;
	z[cnt].sze = 1;
	z[cnt].pri = rand();
	return cnt;
}
inline int merge(int x, int y)
{
	if (!x || !y)
		return x + y;
	if (z[x].pri < z[y].pri)
	{
		int rt = newnode();
		z[rt] = z[x];
		z[rt].ch[1] = merge(z[rt].ch[1], y);
		update(rt);
		return rt;
	}
	else
	{
		int rt = newnode();
		z[rt] = z[y];
		z[rt].ch[0] = merge(x, z[rt].ch[0]);
		update(rt);
		return rt;
	}
}
inline void split(int rt, ll k, int &x, int &y)
{
	if (!rt)
		x = y = 0;
	else
	{
		if (z[rt].w <= k)
		{
			x = newnode();
			z[x] = z[rt];
			split(z[x].ch[1], k, z[x].ch[1], y);
			update(x);
		}
		else
		{
			y = newnode();
			z[y] = z[rt];
			split(z[y].ch[0], k, x, z[y].ch[0]);
			update(y);
		}
	}
}
inline int findkth(int rt, int k)
{
	while (1119)
	{
		if (k <= z[z[rt].ch[0]].sze)
			rt = z[rt].ch[0];
		else
		{
			if (z[rt].ch[0])
				k -= z[z[rt].ch[0]].sze;
			if (!--k)
				return rt;
			rt = z[rt].ch[1];
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P3835.in", "r", stdin);
	freopen("P3835_TJ.out", "w", stdout);
#endif
	n = read();
	go(i, 1, n, 1)
	{
		xx = yy = zz = 0;
		int tmp = read(), s = read();
		ll a = read();
		rot[i] = rot[tmp];
		if (s == 1)
		{
			split(rot[i], a, xx, yy);
			rot[i] = merge(merge(xx, newnode(a)), yy);
		}
		else if (s == 2)
		{
			split(rot[i], a, xx, zz);
			split(xx, a - 1, xx, yy);
			yy = merge(z[yy].ch[0], z[yy].ch[1]);
			rot[i] = merge(merge(xx, yy), zz);
		}
		else if (s == 3)
		{
			split(rot[i], a - 1, xx, yy);
			printf("%lld\n", z[xx].sze + 1);
			rot[i] = merge(xx, yy);
		}
		else if (s == 4)
		{
			printf("%lld\n", z[findkth(rot[i], a)].w);
		}
		else if (s == 5)
		{
			split(rot[i], a - 1, xx, yy);
			if (xx == 0)
			{
				printf("-2147483647\n");
				continue;
			}
			printf("%lld\n", z[findkth(xx, z[xx].sze)].w);
			rot[i] = merge(xx, yy);
		}
		else if (s == 6)
		{
			split(rot[i], a, xx, yy);
			if (yy == 0)
			{
				printf("2147483647\n");
				continue;
			}
			printf("%lld\n", z[findkth(yy, 1)].w);
			rot[i] = merge(xx, yy);
		}
	}
	return 0;
}