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

const int N=3e5+5;
int f[N],s[N];

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname"_TJ.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> f[i] >> s[i];
	}
	int maxinum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i]==f[j]){
				maxinum=max(maxinum,max(s[i],s[j])+min(s[i],s[j])/2);
			}
			else{
				maxinum=max(maxinum,s[i]+s[j]);
			}
		}
	}
	cout << maxinum;
	return 0;
}