#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

int dp[1010][1010], mx[N], id, t;
int sum[1010][1010];
int n, m, k, d;

void solve()
{
	cin >> n >> m >> k >> d;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= k;j++)
		sum[i][j] = 0;
	}
	for (int i = 1;i <= m;i++)
	{
		int l, r, z;
		cin >> l >> r >> z;
		sum[l][r] += z;
	}
	for (int i = 0;i <= n;i++)
	{
		for (int j = 2;j <= k;j++)
		{
			sum[i][j] += sum[i][j - 1];
		}
		for (int j = 0;j <= k;j++)
		dp[i][j] = -1e15;
	}
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
	{
		mx[i] = dp[i][0] = mx[i - 1];
		for (int j = 1;j <= min(i, k);j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + sum[i][j] - d;
			mx[i] = max(mx[i], dp[i][j]);
		}
	}
	cout << mx[n] << '\n';
}

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> id >> t;
	while (t--)
	{
		solve();
	}
}
