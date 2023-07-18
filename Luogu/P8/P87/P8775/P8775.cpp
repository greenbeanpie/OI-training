#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

int n,x,river[100005];

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P8775.in","r",stdin);
	freopen("P8775.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> x;
	x*=2;
	for(int i=1;i<n;i++){
		cin >> river[i];
	}
	int ans=0,l=0,sum=0;
	for(l=1;l+ans<n;l++){
		sum+=river[l+ans];
		while(sum<x&&l+ans<n){
			sum+=river[l+(++ans)];
		}
		sum-=river[l];
	}
	cout << ans+1;
	return 0;
}