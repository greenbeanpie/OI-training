#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int sum[N], num[N], tong[N], cur, max_ans;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P8226.in", "r", stdin);
	freopen("P8226.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int t;
	for (int i = 1; i <= m; i++)
	{
		cin >> t;
		tong[t] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		sum[i] = sum[i - 1] + t;
	}
	for (int i = 1; i <= n; i++)
	{
		if (tong[i])
		{
			num[sum[i] % k]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (tong[i])
		{
			num[sum[i] % k]--;
		}
		max_ans = max(max_ans, cur + num[(sum[i] - sum[i - 1]) % k]);
		if (sum[i] % k == 0 && tong[i])
		{
			cur++;
		}
	}
	cout << max_ans;
	return 0;
}
