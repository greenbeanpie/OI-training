#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P4718"
#define const constexpr

namespace Main
{
	random_device rd;
	sfmt19937_64 myrand(rd());
	uniform_int_distribution<> dist(1000, 2000);

	int f(unsigned int t,unsigned int c,unsigned int x){
		return (x * x + c) % t;
	}

	int quickpower(int a, int b, int mod)
	{
		int ans = 1, base = a;
		while (b)
		{
			if (b & 1)
			{
				ans = ans * base % mod;
			}
			base = base * base % mod;
			b >>= 1;
		}
		return ans % mod;
	}

	bool MillerRabin(int x)
	{
		int time = 8;
		if (x < 3 || !(x % 2))
		{
			return x == 2;
		}
		int u = x - 1, t = 0;
		while (!(u & 1))
		{
			u >>= 1;
			++t;
		}
		for (int i = 1; i <= time; i++)
		{
			int a = myrand() % (x - 2) + 2,v=quickpower(a,u,x);
			if(v==1){
				continue;
			}
			bool pass = 0;
			for (int s = 1; s <= t;s++){
				if(v==x-1){
					pass = 1;
					break;
				}
				v = v * v % x;
			}
			if(!pass){
				return 0;
			}
		}
		return 1;
	}

	int PollardRho(int x){
		int t = 0, c = myrand() % (x - 1) + 1;
		for (int i = 1; i <= dist(myrand);i++){
		}
	}

	int main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			int n;
			cin >> n;
		}

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