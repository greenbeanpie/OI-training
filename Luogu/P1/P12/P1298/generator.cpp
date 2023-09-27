#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P1298"
#define const constexpr

namespace Main{
	random_device rd;
	sfmt216091_64 myrand(rd());
	
	int main(){
		int a = myrand() % 1000000 + 1, b = myrand() % 1000000 + 1;
		int m=myrand()%a+1,n=myrand()%b+1;
		cout << m << " " << n << " " << endl
			 << fixed << setprecision(10) << (double)a / b;
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