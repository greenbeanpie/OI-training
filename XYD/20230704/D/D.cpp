#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int dp[8][10];
	int t;
	cin >> t;
	int l, r;
	for (int i = 1; i <= t; i++)
	{

		int l, r, ans = 0, len = 1;
		bool vis[200005];
		memset(vis, 0, sizeof(vis));
		cin >> l >> r;
		if (r < 10)
		{
			cout << 0 << endl;
			continue;
		}
		while (len < r)
			len *= 10;
		len /= 10;
		// len=pow(10,log10(r));
		for (int j = l; j <= r; j++)
		{
			if (vis[j]) continue;
			vis[j] = 1;
			int sum = 0;
			for (int f = j / 10 + j % 10 * len; f != j; f = f / 10 + f % 10 * len)
			{
				if (!vis[f] && f >= l && f <= r)
				{
					sum++, vis[f] = 1;
				}
			}
			ans += (sum + 1) * sum / 2;
		}
		cout << ans << "\n";
	}
	return 0;
}