#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P4137"
#define const constexpr

namespace Main{
	random_device rd;
	sfmt216091_64 myrand(rd());

	int main(){

		
		int n = 200000, m = 200000;
		cout << n << " " << m << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << myrand() % 200001 << " ";
		}
		cout << endl;
		for (int i = 1; i <= m; i++)
		{
			int l = myrand() % n + 1, r = myrand() % n + 1;
			if (l > r)
			{
				swap(l, r);
			}
			cout << l << " " << r << endl;
		}
		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	
	return 0;
}