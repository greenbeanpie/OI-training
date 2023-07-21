#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

list<int> num[1000005];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("B3656.in", "r", stdin);
	freopen("B3656.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t, a, x;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string s;
		cin >> s;
		if (s == "push_back")
		{
			cin >> a >> x;
			num[a].push_back(x);
		}
		else if (s == "pop_back")
		{
			cin >> a;
			if (num[a].size())
			{
				num[a].pop_back();
			}
		}
		else if (s == "push_front")
		{
			cin >> a >> x;
			num[a].push_front(x);
		}
		else if (s == "pop_front")
		{
			cin >> a;
			if (num[a].size())
			{
				num[a].pop_front();
			}
		}
		else if (s == "size")
		{
			cin >> a;
			cout << num[a].size() << endl;
		}
		else if (s == "front")
		{
			cin >> a;
			if (num[a].size())
			{
				cout << *num[a].begin() << endl;
			}
		}
		else
		{
			cin >> a;
			if (num[a].size())
			{
				cout << *num[a].rbegin() << endl;
			}
		}
	}
	return 0;
}