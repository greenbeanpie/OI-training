#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("Ofast")
#define int long long
#define double long double
#define endl "\n"
#define problemname "watermelon"
#define const constexpr

namespace Main
{
	const int N = 1e5 + 5;
	// int num[N], typ[N];
	map<int, int> cnt;
	int main()
	{
		int n;
		cin >> n;
		int temp;
		for (int i = 1; i <= n; i++)
		{
			// cin >> num[i];
			cin >> temp;
			++cnt[temp];
		}
		// sort(num + 1, num + 1 + n);
		// for (int i = 1; i <= n; i++)
		// {
		// 	typ[i] = typ[i - 1];
		// 	if (num[i] != num[i - 1])
		// 	{
		// 		++typ[i];
		// 	}
		// }
		// if(typ[n]<=3){
		// 	cout << "华强" << endl;
		// 	cout << num[1] << " " << num[n];
		// 	return 0;
		// }
		// int l = 1, r = n,lnow=0,rnow=0;
		// for (int i = 1; i <= n; i++)
		// {
		// 	++l;

		// }
		int l = 0, r = 0;
		string ans = "华强"; // 郝哥或华强
		while (cnt.size() >= 3)
		{
			auto big1 = --cnt.end(), big2 = big1, small1 = cnt.begin(), small2 = small1;

			--big2;
			++small2;
			if (cnt.size() == 3)
			{
				// ans = l + small1->second <= r + big1->second ? "" : "";
				// break;
				if (l + small1->second <= r + big1->second)
				{
					cnt.erase(small1);
					ans = "郝哥";
				}
				else
				{
					cnt.erase(big1);
					ans = "华强";
				}
				break;
			}

			if (l + small1->second <= r + big1->second)
			{
				l += small1->second;
				small2->second += small1->second;
				cnt.erase(small1);
				ans = "郝哥";
			}
			else
			{
				r += big1->second;
				big2->second += big1->second;
				cnt.erase(big1);
				ans = "华强";
			}
		}
		cout << ans << endl;
		cout << cnt.begin()->first << " " << cnt.rbegin()->first;
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