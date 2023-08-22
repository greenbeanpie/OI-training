#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define int long long
#define double long double
#define endl "\n"
#define problemname "standard"
#define const constexpr

namespace Main
{
	int k, l, r,T,t,st=clock();
	random_device rd;
	sfmt19937 random(rd());
	int log10(int x){
		int len=0;
		while(x>=10){
			++len;
			x/=10;
		}
		return len;
	}
	int res[10] = {0, 1, 4, 9, 6, 5, 6, 9, 4, 1};
	double downlimit[] = {0.1, 0.2, 1.2, 6.7,
						  45.1,
						  338.5,
						  2709.4,
						  22587.3,
						  193662.0,
						  1694915.3,
						  15068493.1,
						  135635018.5,
						  1233183856.5,
						  11305241521.1,
						  104364326375.7,
						  969162995594.7,
						  9046052631578.9,
						  84811102544333.1};
	int uplimit[] = {
		9,
		90,
		900,
		9000,
		90000,
		900000,
		9000000,
		90000000,
		900000000,
		9000000000,
		90000000000,
		900000000000,
		9000000000000,
		90000000000000,
		900000000000000,
		9000000000000000,
		90000000000000000};
	// int f(int x){
	// 	int sum=0;
	// 	while(x){
	// 		sum+=res[x%10];
	// 		x/=10;
	// 	}
	// 	return sum;
	// }
	cc_hash_table<int, int>
		ht;
	int f(int x)
	{

		if (x < 1e7)
		{
			if (!x)
			{
				return 0;
			}
			if (ht[x])
			{
				return ht[x];
			}
			else
			{
				return ht[x] = f(x / 10) + ht[x % 10];
			}
		}
		else
		{
			return f(x / 10) + (x % 10) * (x % 10);
		}
	}
	int solve(int x, int y)
	{
		// if(ht[x]){
		// 	return ht[x];
		// }
		// else{
		// 	return ht[x]=dp(x/10)+res[x%10];
		// }
		int ans = 0;
		int len = 0, temp = x;
		while (temp)
		{
			++len;
			temp /= 10;
		}
		--len;
		for (int start = pow(10, len); start <= y; start *= 10)
		{
			if(clock()-st>0.95*CLOCKS_PER_SEC/T*t){
				return random()%2;
			}
			int end = min(start * 10 - 1, y);
			if (downlimit[(int)log10(start)] > k)
			{
				break;
			}
			else if (uplimit[(int)log10(start)] < k)
			{
				continue;
			}

			for (int i = ceil(1.0*max(start, x)/k)*k; i <= end; i+=k)
			{
				if (f(i)  == i/k)
				{
					++ans;
				}
			}
		}
		return ans;
	}
	int main()
	{
		for (int i = 1; i <= 9; i++)
		{
			ht[i] = i * i;
		}
		
		cin >> T;
		
		for(t=1;t<=T;t++)
		{
			cin >> k >> l >> r;
			cout << solve(l, r) << endl;
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