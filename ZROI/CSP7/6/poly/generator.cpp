#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "poly"
#define const constexpr

namespace Main
{
	int l = -10, r = 10;
	random_device rd;
	sfmt19937_64 myrand(rd());
	uniform_int_distribution<int> dist(l, r), dist2(1, 1e9);

	int main()
	{
		int T = 5;
		cout << T << endl;
		while (T--)
		{
		flag1:
			int k[12] = {0};
			__int128 a = dist(myrand);
			for (int i = 0; i <= 11; i++)
			{
				k[i] = dist(myrand);
			}
			__int128 b = 0;
			for (int i = 0; i <= 11; i++)
			{
				b += a * pow(k[i], i);
			}
			__int128 c = 0;
			for (int i = 0; i <= 11; i++)
			{
				c += b * pow(k[i], i);
			}
			if (c <= 1e18&&c>0&&b>0&&a>0)
			{
				cout << (int)a << " " << (int)b << " " << (int)c << endl;
			}
			else
			{
				goto flag1;
			}
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