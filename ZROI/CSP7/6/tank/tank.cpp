#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'

const int N = 3e5 + 5;
pair<int, int> pt[N];
#ifdef CODESPACE
#pragma GCC optimize("Ofast")
#endif

unsigned int gcd(unsigned int x, unsigned int y)
{
	if (!x && !y)
	{
		return 1;
	}
	if (x == 0)
	{
		return y;
	}
	if (y == 0)
	{
		return x;
	}
	return gcd(y % x, x);
}

unsigned int lcm(unsigned int x, unsigned int y)
{
	return x / gcd(x, y) * y;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("tank.in", "r", stdin);
	freopen("tank.out", "w", stdout);
#endif
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> pt[i].first >> pt[i].second;
	}
	int l, r, p, q;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r >> p >> q;
		int maxans1 = 0, maxans2 = 1;
		for (int j = l; j <= r; j++)
		{
			int deltax = pt[j].first - p, deltay = pt[j].second - q;
			pair<int, int> ans2 = {b * deltax - a * deltay, a * a + b * b}, ans1 = {deltax * ans2.second - b * ans2.first, a * ans2.second};
			ans2.first = abs(ans2.first), ans1.first = abs(ans1.first);
			int temp1 = gcd(ans1.first, ans1.second), temp2 = gcd(ans2.first, ans2.second);
			ans1.first /= temp1, ans1.second /= temp1, ans2.first /= temp2, ans2.second /= temp2;
			int temp3 = lcm(ans1.second, ans2.second);
			ans1.first *= temp3 / ans1.second;
			ans1.second = temp3;
			ans2.first *= temp3 / ans2.second;
			ans2.second = temp3;
			ans1.first += ans2.first;
			int temp4 = gcd(ans1.first, ans1.second);
			ans1.first /= temp4, ans1.second /= temp4;
			if ((long double)1.0 * maxans1 / maxans2 < (long double)1.0 * ans1.first / ans1.second)
			{
				maxans1 = ans1.first, maxans2 = ans1.second;
			}
		}
		cout << maxans1 << "/" << maxans2 << endl;
	}
	return 0;
}