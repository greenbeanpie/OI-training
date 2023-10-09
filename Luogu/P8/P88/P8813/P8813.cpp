#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P8813"
#define const constexpr

namespace Main{
	
	int quickpower(int a,int b){
		if(a==1){
			return 1;
		}
		if(a>=2&&b>=30){
			return -1;
		}
		int base = a, ans = 1;
		while(b){
			if (base > 1e9 || ans > 1e9)
			{
				return -1;
			}
			if(b&1){
				ans *= base;
			}
			base *= base;
			b >>= 1;
			
		}
		if(ans>1e9){
			return -1;
		}
		return ans;
	}

	int main(){
		int a, b;
		cin >> a >> b;
		cout << quickpower(a, b);

		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}