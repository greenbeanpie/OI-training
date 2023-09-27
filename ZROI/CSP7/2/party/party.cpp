#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "party"
#define const constexpr

namespace Main
{

	int main()
	{
		map<int, int> cnt;
		int n;
		cin >> n;
		for (int i = 1, temp; i <= n; i++)
		{
			cin >> temp;
			++cnt[temp];
		}
		cc_hash_table<int, bool> maxinum, mininum;
		for (auto i : cnt)
		{
			int num = i.first, count = i.second;
			if (mininum.find(num - 1) == mininum.end() && mininum.find(num) == mininum.end())
			{
				mininum[num + 1] = 1;
			}
			if (count&&!maxinum[num - 1] )
			{
				maxinum[num - 1] = 1;
				--count;
			}
			if (count&&!maxinum[num] )
			{
				maxinum[num] = 1;
				--count;
			}
			if (count&&!maxinum[num + 1] )
			{
				maxinum[num + 1] = 1;
				--count;
			}
		}
		cout << mininum.size() << " " << maxinum.size();

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