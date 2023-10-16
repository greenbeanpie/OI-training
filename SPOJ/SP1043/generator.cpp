#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "SP1043"
#define const constexpr

namespace Main{
	int l=-15007,r=15007,n=10;
	random_device rd;
	sfmt19937_64 myrand(rd());
	uniform_int_distribution<> dist(l,r),dist2(1,n);
	
	int main(){
		int m=10;
		cout << n << endl;
		for (int i = 1; i <= n;i++){
			cout << dist(myrand) << " ";
		}
		cout << endl;
		cout << m << endl;
		for (int i = 1; i <= m;i++){
			int l = dist2(myrand), r = dist2(myrand);
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