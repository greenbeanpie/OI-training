#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3805"
#define const constexpr

namespace Main
{
	const int N = 22e6 + 5;
	int d1[N];
	char s[N], s2[N];
	int main()
	{
		cin >> (s + 1);
		s[0] = '|';
		s2[1] = '&';
		for (int i = 1; s[(i >> 1) + 1]; i += 2)
		{
			s2[i + 1] = s[(i >> 1) + 1];
			s2[i + 2] = '&';
		}
		int l = 0, r = -1, ans = 0;
		for (int i = 1; s2[i]; i++)
		{
			int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			while (i-k>=1&&s2[i + k] && s2[i - k] == s2[i + k])
			{
				++k;
			}
			d1[i] = k--;
			if (i + k > r)
			{
				l = i - k;
				r = i + k;
			}
			ans = max(ans, d1[i]-1);
		}
		cout << ans << endl;
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
