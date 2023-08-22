#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "C"
#define const constexpr



signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	sfmt19937 random(time(0));
	cout << 100 << endl;
	for(int i=1;i<=100;i++){
		cout << random()%10+1 << " " << random()%10*2 << endl;
	}
	return 0;
}