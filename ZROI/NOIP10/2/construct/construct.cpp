#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "construct"
#define const constexpr

namespace Main{
	
	void solve(int x,int p){
		int n = x * p * p;
		for (int a = 1; a <= 20;a++){
			for (int b = 1; b <= 20;b++){
				for (int c = 1; c <= 10;c++){
					if(a*b+a*c+b*c==n){
						cout << a << " " << b << " " << c << endl;
						return;
					}
				}
			}
		}
		cout << -1 << endl;
		return;
	}

	int main(){
		int T;
		cin >> T;
		floor(T);
		while (T--)
		{
			int x, p;
			cin >> x >> p;
			solve(x, p);
		}

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