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

namespace Main
{
	const int N = 5e5 + 5;
	int first[N], second[N], first2[100005];
	map<int, int> chafen;
	unordered_map<int, int> idx;
	int main()
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> first[i] >> second[i];
			if (first[i] > second[i])
			{
				ans = max(ans, first[i]);
				--chafen[first[i]];
				++chafen[second[i]];
			}
			else
			{
				ans = max(ans, second[i]);
			}
			// first2[i] = first[i];
		}
		int maxval = ans;
		// sort(first + 1, first2 + 1 + n);
		// int endp = unique(first + 1, first + 1 + n) - first;
		int now = 0, start = 0, temp = 0;

		for (auto i : chafen)
		{
			now += i.second;
			if (!start && now)
			{
				start = i.first;
			}
			if (!now)
			{
				ans += (i.first - start) * 2;
				temp = i.first - start;
				start = 0;
			}
		}
		// if (chafen.size())
		// {
		// 	ans -= temp;
		// 	ans += min(maxval - chafen.rbegin()->first, temp);
		// }
		int sum = 0;
		start = 0;
		ans = min(ans, maxval * 2 - chafen.begin()->first);
		for (auto i : chafen)
		{
			// if (!now)
			// {
			// 	ans = min(maxval + sum + (maxval - i.first), ans);
			// 	sum += (i.first - start) * 2;
			// 	start = 0;
			// }
			// now += i.second;
			// if (!start && now)
			// {
			// 	start = i.first;
			// }
			now += i.second;
			if (!start && now)
			{
				ans = min(maxval + sum + (maxval - i.first), ans);
				start = i.first;
			}
			if (!now)
			{
				sum += (i.first - start) * 2;
				start = 0;
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