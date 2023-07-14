#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int unsigned long long
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
		vector<int> a;
		int n,m;
		cin >> n >> m;
		int t;
		for(int i=1;i<=n;i++){
			cin >> t;
			a.push_back(t);
		}
		int ans=0,now=0,last=-1;
		auto pos=a.begin();
		for(int i=1;i<=m;i++){
			cin >> t;
			if(t!=last){
				now==0?1:ans^=now;
				last=t;
				now=0;

			}
			while(*pos<last){
				pos++;	
			}
			if(*pos==last){
				now++;
			}
		}
		ans^=now;
		cout << ans << endl;
	}
	return 0;
}