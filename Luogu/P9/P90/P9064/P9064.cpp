#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("P9064.in","r",stdin);
		freopen("P9064.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> num;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		num.push_back(t);
	}
	sort(num.begin(),num.end());
	int mininum=INT_MAX;
	for(int i=0;i<=n-m;i++){
		mininum=min(mininum,num[i+m-1]-num[i]);
	}
	cout << mininum;
	return 0;
}