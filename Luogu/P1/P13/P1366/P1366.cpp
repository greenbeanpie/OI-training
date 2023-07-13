#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("P1366.in","r",stdin);
		freopen("P1366.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		vector<int> a,b;
		int t;
		for(int i=0;i<n;i++){
			cin >> t;
			a.push_back(t);
		}
		for(int i=0;i<m;i++){
			cin >> t;
			b.push_back(t);
		} 
	}
	return 0;
}