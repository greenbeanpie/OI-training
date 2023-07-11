#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-3;
int n, k;
double a[100010], c[100010];
bool pd(double x)
{
	int cnt = 0;
	vector<double> xx;
	xx.push_back(0); // 先存一个0，使下标从1开始
	for (int i = 1; i <= n; i++)
	{
		double aaa = 1.0 * a[i] * (c[i] - x);
		xx.push_back(aaa); // 插入xx
		if (aaa >= 0)
			cnt--; // 减去i=j时符合的数量
	}
	sort(xx.begin() + 1, xx.end()); // 排序

	// 双指针扫描，i扫xx[i]，p扫-xx[p]
	// i从左往右，p从右往左
	int p = n;
	for (int i = 1; i <= n; i++)
	{
		while (xx[i] >= -xx[p] && p >= 1)
			p--;
		cnt += (n - p); // 加上此时符合的个数
	}
	return cnt >= k * 2; // cnt应除以2，要返回cnt/2>=k，即cnt>=k*2
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P6733.in", "r", stdin);
	freopen("P6733_TJ.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];

	double l = 1, r = 1000000000, ans = 0;
	while (fabs(l - r) > eps) // 二分
	{
		double mid = (l + r) / 2;
		if (pd(mid))
			l = mid;
		else
			r = mid;
	}

	printf("%.3lf", l);

	return 0;
}