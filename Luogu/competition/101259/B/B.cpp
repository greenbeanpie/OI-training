#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "B"
#define const constexpr

namespace Main
{

	int main()
	{
		int n;
		cin >> n;
		if (n % 2)
		{
			for (int i = 1; i < n; i += 2)
			{
				cout << i << " ";
				if (i != n - i)
				{
					cout << n - i << " ";
				}
			}
			cout << n;
		}
		else
		{
			for (int i = 1; i <= n/2; i += 2)
			{
				cout << i << " ";
				if (i != n - i)
				{
					cout << n - i << " ";
				}
			}
			int st = n / 2;
			if(st%2){
				++st;
			}
			for (int i = st;i<n;i+=2){
				cout << i<< " ";
				if (i != n - i)
				{
					cout << n - i << " ";
				}
				
			}
			cout << n << " ";
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