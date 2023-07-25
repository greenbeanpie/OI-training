#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
	freopen("AT_joisc2014_h.in","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	sfmt11213_64 rand(time(0));
	int n=rand()%200000+1;
	cout << n << endl;
	for(int i=1;i<=n;i++){
		int res=rand()%3;
		if(res==0){
			cout << "J";
		}
		else if(res==1){
			cout << "O";
		}
		else{
			cout << "I";
		}
	}
	return 0;
}