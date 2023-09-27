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

namespace Main{
	int start=1,end=1e9;
	random_device rd;
	sfmt216091_64 myrand(rd());
	uniform_int_distribution<> dist(start,end),ng(1,5e4); // 在[start,end]间均匀生成随机数
	normal_distribution<> ndist(start,end);
	int main()
	{
		int T=10;
		cout << T << endl;
		while(T--){
			int n = ng(myrand);
			cout << n << endl;
			for(int i=1;i<=n;i++){
				cout << (int)abs(ndist(myrand)) << " ";
			}
			cout << endl;
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