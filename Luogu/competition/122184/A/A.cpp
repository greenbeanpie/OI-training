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
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int a,b;
		cin >> a >> b;
		if(a==b){
			cout << 0 << endl;
			continue;
		}
		bool flag1=true,flag2=true;;
		while(a||b){
			if((a&1)&&!(b&1)){
				flag1=0;
			}
			if((b&1)&&!(a&1)){
				flag2=0;
			}
			a>>=1;
			b>>=1;
			if(!flag1&&!flag2){
				break;
			}
		}
		if(!flag1&&!flag2){
			cout << 2 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
	return 0;
}