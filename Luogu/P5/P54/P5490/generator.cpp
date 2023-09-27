#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P5490"
#define const constexpr

namespace Main
{
	random_device rd;
	sfmt216091_64 myrand(rd());

	int main()
	{
		int n = myrand() % 10+1;
		cout << n << endl;
		for (int i = 1; i <= n; i++)
		{
			int l = myrand() % 1000, r = myrand() % 1000, u = myrand() % 1000, d = myrand() % 1000;
			if (l > r)
			{
				swap(l, r);
			}
			if (d > u)
			{
				swap(d, u);
			}
			cout << l << " " << d << " " << r << " " << u << endl;
		}

		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}