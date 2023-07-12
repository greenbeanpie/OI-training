#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("P1495.in","r",stdin);
		freopen("P1495.out","w",stdout);
	#endif
	int n;
	cin >> n;
	pair<int,int> p[n];
	for(int i=0;i<n;i++){
		cin >> p[i].first >> p[i].second;
	}
	sort(p,p+n,greater<pair<int,int> >());
	int a=p[0].first;
	int ans=p[0].first+p[0].second;
	for(int i=1;i<n;i++){
		while(ans%p[i].first!=p[i].second){
			ans+=a;
		}
		a*=lcm(a,p[i].first);
	}
	cout<<ans;
	return 0;
}