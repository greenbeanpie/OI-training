#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll read()
{
	char c;
	ll s = 0, f = 1;
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
ll max(ll a, ll b) {return a > b ? a : b;}

ll c, t;
ll n, m, k, d, ans, temp;
struct Node
{
	ll x, y, v;
}a[10001];
ll f[10001];

void dfs(int q)
{
	if (q == n + 1)
	{
		temp = 0;
		for (int i = 1; i <= m; i++)
			if (f[a[i].x] >= a[i].y) temp += a[i].v;
		for (int i = 1; i <= n; i++)
			if (f[i] > 0) temp -= d;
		ans = max(ans, temp);
		return;
	}
	f[q] = 0;
	dfs(q + 1);
	if (f[q - 1] < k)
	{
		f[q] = f[q - 1] + 1;
		dfs(q + 1);
		f[q] = 0;
	}
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	c = read(), t = read();
	if (c == 1)
	{
		while (t--)
		{
			n = read(), m = read(), k = read(), d = read();
			for (int i = 1; i <= m; i++)
				a[i].x = read(), a[i].y = read(), a[i].v = read();
			dfs(1);
			printf("%d\n", ans);
		}
	}
	else 
	{
		while (t--)
		{
			n = read(), m = read(), k = read(), d = read();
			for (int i = 1; i <= m; i++)
				a[i].x = read(), a[i].y = read(), a[i].v = read();
			cout << 0 << endl;
		}
	}
	return 0;
}

/*
f[i] -- energy  g[i] -- times 
f[i] = 0  g[i - 1] = k
f[i] = 

*/
