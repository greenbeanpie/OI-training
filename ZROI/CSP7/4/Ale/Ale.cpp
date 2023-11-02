#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("Ale.in", "r", stdin);
	freopen("Ale.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		multiset<int> s;
		for (int i = 1, temp; i <= n; i++)
		{
			cin >> temp;
			s.insert(temp);
		}
		int ans = 0;
		while (s.size())
		{
			ans += *s.begin();
			s.erase(s.begin());
			if(s.empty()){
				break;
			}
			auto temp = s.upper_bound(2);
			if(temp==s.end()){
				--temp;
			}
			if (*temp <= 2)
			{
				s.erase(temp);
			}
			else
			{
				
				s.insert(*temp - 2);
				s.erase(temp);
			}
			if (s.empty()||*s.rbegin() <= 1)
			{
				break;
			}
		}
		ans += (s.size()+1)/2;
		cout << ans << endl;
	}
	return 0;
}