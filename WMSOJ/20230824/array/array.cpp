#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "array"
#define const constexpr

namespace Main
{
	const int N = 25, M = 1e5 + 5;
	int dp[N][(1 << 20) + 10];
	int row[M];

	int main()
	{
		int n, m;
		cin >> n >> m;
		int ans = n * m;
		string s;
		for (int i = 1; i <= n; i++)
		{
			cin >> s;
			for(int j=1;j<=m;j++){
				row[j] = (row[j] << 1) + s[j-1] - '0';
			}
		}
		for (int i = 1; i <= m; i++)
		{
			++dp[0][row[i]];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = n-1; j >= 1; j--)
			{
				for (int k = 0; k < (1 << n); k++)
				{
					dp[j][k] += dp[j - 1][k ^ (1 << (i-1))];
				}
			}
		}
		for (int i = 0; i < (1 << n); i++)
		{
			int res = 0;
			for (int j = 0; j <= n; j++)
			{
				res += dp[j][i] * min(j, n - j);
			}
			ans = min(ans, res);
		}
		cout << ans;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}