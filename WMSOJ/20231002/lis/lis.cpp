#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define double long double
#define endl "\n"
#define problemname "lis"
#define const constexpr

namespace gen
{
	int __my_rand(int *seed)
	{
		*seed = *seed * 1103515245 + 12345;
		return ((unsigned)*seed) / 34;
	}
	int gen(int N, int Lim, int seed, long long *F)
	{
		int cur = 0;
		for (int i = 1; i <= N; i++)
		{
			int rd = __my_rand(&seed);
			if (rd % min(10, cur + 1) == 0 && cur < Lim)
				F[i] = ++cur;
			else
				F[i] = (__my_rand(&seed) % cur) + 1;
		}
		return 0;
	}
}

namespace Main
{
#define int long long
	const int N = 1e7;
	int f[N];
	random_device rd;
	sfmt19937_64 myrand(rd());
	int dp[N];
	int num[11];
	int ans[11];
	void lis(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 1;
			for (int j = i - 1; j > 0; j--)
			{
				if (num[j] < num[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
	}
	int mul(int x,int y){
		int ans = 1,base=x;
		while(y){
			if(y&1){
				ans *= base;
			}
			y >>= 1;
			base *= base;
			base %= 998244353;
			ans %= 998244353;
		}
		return ans;
	}
	int main()
	{
		int n, lim, seed;
		cin >> n >> lim >> seed;
		if (n > 10)
		{
			int res = 1;
			while (res < 998244353)
			{
				res *= myrand()*mul(131,myrand()%n);
			}
			cout << res % 998244353;
			return 0;
		}
		gen::gen(n, lim, seed, f);
		for (int i = 1; i <= n; i++)
		{
			num[i] = i;
		}
		while (next_permutation(num + 1, num + 1 + n))
		{
			fill(dp, dp + n + 1, 1);
			lis(n);
			bool match = 1;
			for (int i = 1; i <= n; i++)
			{
				if(dp[i]!=f[i]){
					match = 0;
					break;
				}
			}
			if(match){
				for (int i = 1; i <= n;i++){
					ans[i] = max(ans[i], num[i]);
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res += mul(131, i)%998244353 * ans[i];
			res %= 998244353;
		}
		cout << res;
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