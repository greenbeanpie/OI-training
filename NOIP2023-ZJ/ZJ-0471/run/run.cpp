#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,k,d;
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin >> c >> T;
	while(T--){
		int ans = 0;
		cin >> n >> m >> k >> d;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			ans += z;
		}
		cout << ans<<endl;
	}
	return 0;
}
