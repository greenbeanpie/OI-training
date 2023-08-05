#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1831.in","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	sfmt132049_64 random(time(0));
	int l=random()%10+1;
	int r=random()%10+1+l;
	cout << l << ' ' << r;
	return 0;
}