#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "B"
#define const constexpr

int day[105];

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin >> day[i];
		sum+=day[i];
	}
	int mid=(sum+1)/2;
	int now=0;
	for(int i=1;i<=n;i++){
		if(day[i]<mid-now){
			now+=day[i];
		}
		else{
			cout << i << " " << mid-now;
			break;
		}
	}
	return 0;
}