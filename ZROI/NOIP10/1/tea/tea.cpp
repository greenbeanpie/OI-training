#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "tea"
#define const constexpr

namespace Main
{

	const int N = 1e5 + 5;
	// int prefix[N], num[N];
	int num[N];
	int maxans = -1;
	int sum = 0;
	int n;
	int vis[N];
	double st = clock();
	void dfs(int now, int used, int left)
	{
		maxans = max(maxans, (used + 1) ^ left);
		maxans = max(maxans, used ^ (left + 1));
		for (int i = 1; i <= n && (clock()-st)/CLOCKS_PER_SEC<=0.98; i++)
		{
			if (!vis[i])
			{
				used ^= num[i];
				left ^= num[i];
				vis[i] = 1;
				dfs(now + 1, used, left);
				vis[i] = 0;
				used ^= num[i];
				left ^= num[i];
			}
		}
	}
	int main()
	{
		// int n;
		// cin >> n;
		// for (int i = 1; i <= n; i++)
		// {
		// 	cin >> num[i];
		// 	prefix[i] = prefix[i - 1] ^ num[i];
		// }
		// int maxinum = 0;

		// cout << maxinum;
		// return 0;

		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			sum ^= num[i];
		}
		dfs(0, 0, sum);
		cout << maxans;
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