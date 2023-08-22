#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "nim"
#define const constexpr

namespace Main
{
	
	int n, m, temp;
	vector<int> num;
	int main()
	{
		cin >> n >> m;
		int sum = 0;
		for (int i = 1; i <= m; i++)
		{
			cin >> temp;
			sum ^= temp;
			num.push_back(temp);
		}
		int cnt = 0;
		int highest = 1ll << (int)log10(sum);
		if (n % 4 == 0)
			sum ^= n;
		else if (n % 4 == 1)
			sum ^= (n - 1) ^ n;
		else if (n % 4 == 2)
			sum ^= (n - 2) ^ (n - 1) ^ n;
		if (!sum)
			puts("0");
		for (int i : num)
		{
			if (i & highest)
			{
				++cnt;
			}
		}
		cout << cnt;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "2.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}