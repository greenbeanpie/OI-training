#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3380"
#define const constexpr

namespace Main
{
	int l = 0, r = 10;
	random_device rd;
	sfmt19937_64 myrand(rd());
	uniform_int_distribution<> dist(l, r);
	vector<int> num;
	int main()
	{
		int n = 5, m =2;
		cout << n << " " << m << endl;
		for (int i = 1; i <= n; i++)
		{
			num.push_back(dist(myrand));
		}
		for (int i : num)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = 1; i <= m; i++)
		{
			int opt = myrand() % 4 + 1;
			cout << opt << " ";
			if (opt == 3)
			{
				cout << myrand() % n + 1 << " " << dist(myrand) << endl;
			}
			else
			{
				int l = myrand() % n + 1, r = myrand() % n + 1;
				if (l > r)
				{
					swap(l, r);
				}
				cout << l << " " << r << " ";
				if (opt == 1)
				{
					cout << num[myrand() % n] << endl;
				}
				else if(opt==2){
					cout << myrand() % (r-l)+1 << endl;
				}
				else
				{
					cout << dist(myrand) << endl;
				}
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