#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "A"
#define const constexpr
#define mod 998244353
namespace Main
{
	int quickpower(int a, int b)
	{
		int ans = 1, base = a;
		a = a % mod;
		while (b)
		{
			if (b & 1)
			{
				ans *= base;
				ans %= mod;
			}
			base = base * base % mod;
			b >>= 1;
		}
		return ans;
	}

	int main()
	{
		int a, b, k;
		cin >> a >> b >> k;
		if (a > b)
		{
			if (k % a > k % b)
			{
				cout << 1;
			}
			else
			{
				cout << 2;
			}
			return 0;
		}
		cout << quickpower(2, (k / a)) * quickpower(499122177, (k / b)) % mod;

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