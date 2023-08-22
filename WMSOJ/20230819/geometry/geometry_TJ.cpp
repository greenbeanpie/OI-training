#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NR = 2005;
const double eps = 1e-12;
void Min(int &x, int y) { x = min(x, y); }
void Max(int &x, int y) { x = max(x, y); }
int n;
ll ans = 0;
struct point
{
	long double x, y;
} chuizu[NR];
bool operator==(point a, point b)
{
	return (fabs(a.x - b.x) <= eps) && (fabs(a.y - b.y) <= eps);
}
double p[NR];
int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("geometry1.in", "r", stdin);
	freopen("geometry_TJ.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int a = read(), b = read(), c = read();
		chuizu[i].x = 1. * a * c / (1. * a * a + 1. * b * b);
		chuizu[i].y = 1. * b * c / (1. * a * a + 1. * b * b);
	}
	for (int i = 1; i <= n - 2; i++)
	{
		int same = 0, idx = 0, la = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (chuizu[i] == chuizu[j])
				same++; // 去重
			else if (fabs(chuizu[i].x - chuizu[j].x) > eps)
			{ // 算斜率
				p[++idx] = (chuizu[i].y - chuizu[j].y) / (chuizu[i].x - chuizu[j].x);
			}
			else
			{ // 特判斜率为无限大的时候
				p[++idx] = 1e15;
			}
		}
		ans += (n - i) * same - (1 + same) * same / 2; // 对符合条件的三个点对计算排列组合
		sort(p + 1, p + idx + 1);
		for (int j = 2; j <= idx; j++)
		{
			if (p[j] == p[la])
			{
				;
			}
			else
			{
				ans += (j - la) * (j - la - 1) / 2, la = j;
			}
		}
		ans += (idx - la) * (idx - la + 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}
