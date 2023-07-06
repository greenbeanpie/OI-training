#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define int long long
#define endl "\n"

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("P7505_3.in","r",stdin);
		freopen("P7505.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	multiset<int> s;
	int t;
	for(int i=0;i<n;i++){
		cin >> t;
		s.insert(t);
	}
	int op,add=0;
	for(int i=0;i<m;i++){
		cin>> op;
		if(op==1){
			cin >> op;
			add+=op;
			while(s.size()&&*(--s.end())+add>k){
				s.erase(--s.end());
			}
		}
		else if(op==2){
			cin >> op;
			add-=op;
			while(s.size()&&*s.begin()+add<-k){
				s.erase(s.begin());
			}
		}
		else{
			cout << s.size() << endl;
		}
	}
	return 0;
}