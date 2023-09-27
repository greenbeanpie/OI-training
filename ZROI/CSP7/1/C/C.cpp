#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "C"
#define const constexpr
#pragma GCC optimize("Ofast")

namespace Main
{

	cc_hash_table<int, int> dp;
	int s[15];

	int main()
	{
		int n, m;
		cin >> n >> m;
		if (m == 1 && n > 2030)
		{
			cout << 0;
			return 0;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> s[i];
		}
		dp[0] = 1;

		for (int i = 0; i < 20; i++)
		{
			dp[i] %= 2027;
			for (int j = 1; j <= m; j++)
			{
				dp[i + s[j]] += dp[i] * (i + 1);
			}
		}
		if(n>10000000){
			n = n % 2027 + 202700;
		}
		for (int i = 20; i < n; i++)
		{
			dp.erase(i - 20);
			dp[i] %= 2027;
			for (int j = 1; j <= m; j++)
			{
				dp[i + s[j]] += dp[i] * (i + 1);
			}
		}
		dp[n] %= 2027;
		cout << dp[n];
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