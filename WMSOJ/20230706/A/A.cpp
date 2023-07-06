#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
		freopen("A.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int sum=0,min1=INT_MAX;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		sum+=t;
		if(t%2==1){
			min1=min(min1,t);
		}
	}
	if(sum%2==0){
		cout << sum;
	}
	else{
		if(min1!=INT_MAX){
			cout << sum-min1;
		}
		else{
			cout << "NIESTETY";
		}
	}
	return 0;
}