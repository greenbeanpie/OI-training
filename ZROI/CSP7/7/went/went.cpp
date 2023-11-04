#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define double long double

const int N = 1e6 + 5;

char s[N];

list<pair<bool, bool>> v;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("went.in", "r", stdin);
	freopen("went.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	cin >> (s + 1);

	for (int i = 1; i <= n; i++)
	{
		int l = i;
		while (s[i + 1] != s[i] && i < n)
		{
			++i;
		}
		v.emplace_back(s[l] - '0', s[i] - '0');
	}

	int ans = 0;

	for (auto i = v.begin(); i != v.end(); i++)
	{
		if (i == v.begin())
		{
			continue;
		}
		auto lst = i, nxt = i;
		--lst, ++nxt;
		if (nxt == v.end())
		{
			continue;
		}
		if(lst->second^nxt->first){
			++ans;
			lst->second = nxt->second;
			auto temp = i--;
			--i;
			v.erase(nxt);
			v.erase(temp);
		}
	}
	ans += v.size();
	cout << ans << endl;
	return 0;
}
