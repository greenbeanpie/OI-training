#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <python3.9/Python.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P1896"
#define const constexpr
#define popcount __builtin_popcount

namespace Main
{
	vector<int> ac;
	int dp[10][100][2000]; // i: 处理到的行数 j: 使用的国王数 s: 当前行的状态
	int main()
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < (1 << n); i++)
		{
			if (!(i & ((i << 1) | (i >> 1))))
			{
				ac.push_back(i);
			}
		}
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j : ac)
			{ // j: 当前行状态
				for (int f : ac)
				{ // f:上一行状态
					if (j & ((f << 1) | f | (f >> 1)))
					{
						continue;
					}
					for (int cnt = popcount(j); cnt <= k; cnt++)
					{
						dp[i][cnt][j] += dp[i - 1][cnt - popcount(j)][f];
					}
				}
			}
		}
		int ans = 0;
		for (int i : ac)
		{
			ans += dp[n][k][i];
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