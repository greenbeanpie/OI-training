#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("P9063.in","r",stdin);
		freopen("P9063.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		cout << ((n&1)?"Yes":"No") << endl;
	}
	return 0;
}