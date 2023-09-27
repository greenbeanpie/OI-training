#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "sumII"
#define const constexpr

namespace Main
{

	const int N = 2e5 + 5;

	int prefix[N], num[N];
	map<int, bool> pos;
	int main()
	{

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			if (num[i])
			{
				pos[i] = 1;
			}
			prefix[i] = prefix[i - 1] + num[i];
		}
		if (prefix[n] - prefix[0] == n)
		{
			cout << n * (n + 1) / 2;
			return 0;
		}
		else if (prefix[n] == prefix[0])
		{
			cout << 0;
			return 0;
		}
		int ans = 0;
		// for (auto i = pos.begin(); i != pos.end(); ++i)
		// {
		// 	for (auto j = i; j != pos.end(); ++j)
		// 	{
		// 		auto start = i, end = j;
		// 		auto startpos = start->first, endpos = end->first;
		// 		if (start != pos.begin())
		// 		{
		// 			--start;
		// 			startpos = start->first + 1;
		// 		}
		// 		else{
		// 			startpos = 1;
		// 		}
		// 		if (end != --pos.end())
		// 		{
		// 			++end;
		// 			endpos = end->first - 1;
		// 		}
		// 		else{
		// 			endpos = n;
		// 		}
		// 		auto tsum = prefix[j->first] - prefix[i->first - 1];
		// 		ans += floor(1.0 * (endpos - startpos + 1) / tsum) - ceil(1.0 * (j->first - i->first + 1) / tsum) + 1;
		// 	}
		// }
		// cout << ans;
		for (int i = 1; i <= n; i++)
		{
			auto startpos = pos.lower_bound(i);
			// if (num[i])
			// {
			// 	ans += pos.lower_bound(i+1)->first - i;
			// }
			for (auto j = startpos; j != pos.end(); ++j)
			{
				auto temp = j;
				++temp;
				int seg1 = j->first, seg2, tsum = prefix[j->first] - prefix[i - 1];
				if (temp != pos.end())
				{
					seg2 = temp->first - 1;
				}
				else
				{
					seg2 = n;
				}
				ans += (seg2 - i + 1) / tsum - (seg1 - i) / tsum;
			}
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