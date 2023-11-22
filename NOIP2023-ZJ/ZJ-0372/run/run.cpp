#include <bits/stdc++.h>
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define int long long
#define MAXN 2009
using namespace std;
int n,m,k,c,d,t;
int s[MAXN][MAXN];
int dp[MAXN][MAXN];
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m>>k>>d;
		rep(i,1,m) {
			int x,y,z;
			cin>>x>>y>>z;
			s[x][y]+=z;
		}
		rep(i,1,n) rep(j,1,n) s[i][j]+=s[i][j-1];
		memset(dp,0xaf,sizeof(dp));
		dp[0][0]=0;
		rep(i,0,n-1) rep(j,0,min(k,i)) {
			if(j<k) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-d+s[i+1][j+1]);
			dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
		}
//		rep(i,1,n) rep(j,0,min(k,i))
//			cerr<<"dp "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		int ans=0;
		rep(i,0,min(n,k)) ans=max(ans,dp[n][i]);
		cout<<ans<<endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}
