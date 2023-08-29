#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "F"
#define const constexpr

namespace Main{
	
	
	
	int main(){
		random_device rd;
		sfmt216091_64 random(rd());
		int n = 5e5, q = 5e5;
		cout << n << endl;
		for (int i = 1;i<=n;i++){
			cout << random() % n+1 << " ";
		}
		cout << q << endl;
		for (int i = 1; i <= n;i++){
			int l = random() % n, r = random() % n;
			if(l>r){
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