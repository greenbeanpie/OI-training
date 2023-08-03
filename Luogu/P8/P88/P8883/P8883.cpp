#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define Pi M_PIf64x


signed main(){
#ifndef ONLINE_JUDGE
	freopen("P8883.in","r",stdin);
	freopen("P8883.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	double a=1.0l-6.0l/Pi/Pi;
	int T;
	cin >> T;
	int n;
	while(T--){
		cin >> n;
		cout << (int)(n*a) << endl;
	}
	return 0;
}