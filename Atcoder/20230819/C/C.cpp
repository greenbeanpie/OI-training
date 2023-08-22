#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "C"
#define const constexpr

int f, s;
unordered_map<int, pair<int, int>> um;
multiset<int> ms;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int f, s;
	for (int i = 1; i <= n; i++)
	{
		cin >> f >> s;
		if (um[f].first < s)
		{
			um[f].second = um[f].first;
			um[f].first = s;
		}
		else if (um[f].second < s)
		{
			um[f].second = s;
		}
	}
	for (auto i : um)
	{
		ms.insert(i.second.first);
	}
	int maxinum = 0;
	for (auto i : um)
	{
		maxinum = max(maxinum, i.second.first + i.second.second / 2);
	}
	if (ms.size() > 1)
		maxinum = max(maxinum, *++ms.rbegin() + *ms.rbegin());
	cout << maxinum;
	return 0;
}