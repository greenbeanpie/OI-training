#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("champagne.in","r",stdin);
		freopen("champagne.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int num[n+1];
	int sum=0;
	for(int i=1;i<=n;i++){
		cin >> num[i];
		sum+=num[i];
	}
	if(sum%n!=0){
		cout << -1;
		return 0;
	}
	int ave=sum/n;
	for(int i=1;i<=n;i++){
		if(num[i]<ave){
			int first=i-1,second=i+1;
			
		}
	}
	return 0;
}
	cin.tie(0),cout.tie(0);

	return 0;
}