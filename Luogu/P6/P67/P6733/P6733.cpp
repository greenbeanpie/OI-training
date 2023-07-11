#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N = 1e5 + 10;
double a[N], c[N];
int n, k;
bool check(double x)
{
	int cnt = 0;
	vector<double> v = vector<double>(1);
	for (int i = 1; i <= n; i++)
	{
		v.push_back(1.0 * a[i] * (c[i] - x));
		if (a[i] * (c[i] - x) >= 0)
		{
			cnt--;
		}
	}
	sort(v.begin() + 1, v.end());
	int r = v.size() - 1;
	for (int i = 1; i <= n; i++)
	{
		while (v[i] >= -v[r] && r)
		{
			r--;
		}
		cnt += n - r;
	}
	return cnt >= k * 2;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P6733.in", "r", stdin);
	freopen("P6733.out", "w", stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	double l = 1, r = 1e9;
	while (r - l > 0.001)
	{
		double mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	cout << fixed << setprecision(3) << l;
	return 0;
}