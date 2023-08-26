#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "C"
#define const constexpr

namespace Main{
	
	
	
	int main(){
		
		
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
	random_device rd;
	sfmt216091_64 random(rd());
	int n = random() % 6 + 1;
	for(int i=1;i<=n;i++){
		int l = random() % 10 + 1, r = random() % 10 + 1;
		cout << max(l, r) << " " << min(l, r) << endl;
	}
	return 0;
}