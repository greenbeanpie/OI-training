#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
const int N = 125;
int matrix[N][N], dp[N], ans;
int n;
int range_max(int *a, int len)
{
	int maxinum = 0;
	fill(dp, dp + N, 0);
	for (int i = 1; i <= len; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + a[i]);
		maxinum = max(maxinum, dp[i]);
	}
	return maxinum;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1719.in", "r", stdin);
	freopen("P1719.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	int sum[n + 1];
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++)
	{
		memset(sum, 0, sizeof(sum));
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				sum[k] += matrix[j][k];
			}
			ans = max(ans, range_max(sum, n));
		}
	}
	cout << ans;
	return 0;
}