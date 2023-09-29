#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC optimize(3,"Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "elevator"
#define const constexpr

namespace Main
{

	const int N = 25;
	int num[N];
	int n;
	int check(){
		int maxans = 0,now = 0;
		for(int i=1;i<=n;i++){
			now+=num[i];
			maxans=max(maxans,now);
		}
		return maxans;
	}
	int main()
	{

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
		}
		unsigned int t=1;
		for(int i=1;i<=n;i++){
			t*=i;
		}
		int sum=0;
		for(auto i=1ull;i<=t;i++){
			sum+=check();
			next_permutation(num+1,num+1+n);
		}
		cout << sum;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "1.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}