#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
// #define int long long
// #define double long double
#define endl "\n"
#define problemname "geometry"
#define const constexpr
const int N = 2005;
const double eps = 1e-12;

int n;
long long ans;
struct point
{
	long double x, y;
} chuizu[N]; // 垂足
bool operator==(point a, point b)
{
	return (fabs(a.x - b.x) <= eps) && (fabs(a.y - b.y) <= eps);
}
double p[N];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("geometry1.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	double a, b, c;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		chuizu[i] = {1.0 * a * c / (1.0 * a * a + 1.0 * b * b), 1.0 * b * c / (1.0 * a * a + 1.0 * b * b)};
	}
	for (int i = 1; i < n - 1; i++)
	{
		int idx = 0, same = 0, res = 1;
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
			if (p[j] == p[res])
			{
				;
			}
			else
			{
				ans += (j - res) * (j - res - 1) / 2, res = j;
			}
		}
		ans += (idx - res) * (idx - res + 1) / 2;
	}
	cout << ans;
	return 0;
}