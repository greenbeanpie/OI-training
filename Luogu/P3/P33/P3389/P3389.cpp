#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3389"
#define const constexpr

double num[105][105];
double ans[105];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cin >> num[i][j + 1];
		}
		num[i][n + 1] = -num[i][n + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		
		int maxinum = i;
		for (int k = i + 1; k <= n; k++)
		{
			if (fabs(num[k][i]) > fabs(num[maxinum][i]))
			{
				maxinum=k;
			}
		}
		for (int k = 1; k <= n+1; k++)
		{
			swap(num[i][k], num[maxinum][k]);
		}
		if (!num[i][i])
		{
			cout << "No Solution";
			return 0;
		}
		for (int j = i + 1; j <= n; j++)
		{

			if (!num[j][i])
			{
				continue;
			}
			double k = num[i][i] / num[j][i];
			for (int f = i; f <= n + 1; f++)
			{
				num[j][f] = num[j][f] * k - num[i][f];
			}
		}
	}
	ans[n + 1] = 1;
	for (int i = n; i; i--)
	{
		double res = 0;
		for (int j = i + 1; j <= n + 1; j++)
		{
			res -= num[i][j] * ans[j];
		}
		ans[i] = res / num[i][i];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << fixed << setprecision(2) << ans[i] << endl;
	}
	return 0;
}