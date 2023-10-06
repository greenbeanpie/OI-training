#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "picture"
#define const constexpr

namespace Main{
	int l=1,r=10;
	random_device rd;
	sfmt216091_64 myrand(rd());
	 uniform_int_distribution<> dist(l,r);
	
	int main(){
		int n;
		cin >> n;
		for (int i = 1; i <= n;i++){
			cout << dist(myrand) << " ";
		}

			return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdout);
	freopen(problemname "out.", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}