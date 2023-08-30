#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define INF 2147483647
using namespace std;
int n, m;
int p[300005];
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
struct node
{
	int u, v, a, b;
} x[300006];
int suma, sumb;
int ans1, ans2, ans3, ans4;
bool cmp1(node p, node q)
{
	if (p.b == q.b)
		return p.a < q.a;
	return p.b < q.b;
}
bool cmp2(node a, node b)
{
	// if (p.a == q.a)
	// 	return p.b < q.b;
	// return p.a < q.a;
	if (a.a + a.b != b.a + b.b)
	{
		return a.a + a.b < b.a + b.b;
	}
	return a.a < b.a;
}
bool cmp(node p, node q)
{
	return p.a + p.b < q.a + q.b;
}
bool cmp3(node p, node q)
{
	return p.a * p.b < q.a * q.b;
}

signed main()
{
	freopen("carnation.in", "r", stdin);
	freopen("carnation.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> x[i].u >> x[i].v >> x[i].a >> x[i].b;
	}
	sort(x + 1, x + 1 + m, cmp1);
	for (int i = 1; i <= m; i++)
	{
		int fx = find(x[i].u), fy = find(x[i].v);
		if (fx == fy)
			continue;
		p[fx] = fy;
		suma += x[i].a;
		sumb += x[i].b;
	}
	ans1 = suma * sumb;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	suma = 0;
	sumb = 0;
	sort(x + 1, x + 1 + m, cmp2);
	for (int i = 1; i <= m; i++)
	{
		int fx = find(x[i].u), fy = find(x[i].v);
		if (fx == fy)
			continue;
		p[fx] = fy;
		suma += x[i].a;
		sumb += x[i].b;
	}
	ans2 = suma * sumb;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	sort(x + 1, x + 1 + m, cmp);
	suma = 0;
	sumb = 0;
	for (int i = 1; i <= m; i++)
	{
		int fx = find(x[i].u), fy = find(x[i].v);
		if (fx == fy)
			continue;
		p[fx] = fy;
		suma += x[i].a;
		sumb += x[i].b;
	}
	ans3 = suma * sumb;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	suma = 0;
	sumb = 0;
	sort(x + 1, x + 1 + m, cmp3);
	for (int i = 1; i <= m; i++)
	{
		int fx = find(x[i].u), fy = find(x[i].v);
		if (fx == fy)
			continue;
		p[fx] = fy;
		suma += x[i].a;
		sumb += x[i].b;
	}
	ans4 = suma * sumb;
	cout << min(min(ans1, ans2), min(ans3, ans4));
	return 0;
}