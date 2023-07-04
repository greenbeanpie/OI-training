#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    priority_queue<int,vector<int>,greater<int> > pq;
    set<int> s1,s2;
    int t,n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        s1.insert(t);
    }
    for(int i=0;i<n;i++){
        cin >> t;
        s2.insert(t);
    }
    
	return 0;
}