#include<bits/stdc++.h>
using namespace std;
int n,m,k,d;
typedef long long ll;
ll dp[1005][1005];
ll dt[1005][1005];
inline void solve(){
	cin>>n>>m>>k>>d;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k+1;j++)
		dt[i][j]=0;
	for(int i=1;i<=m;i++){
		int x,y,v;cin>>x>>y>>v;
		if(y>k) continue;
		dt[x][y]+=v;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k;j++)
		dt[i][j]+=dt[i][j-1];
	for(int i=0;i<=n+1;i++)
	for(int j=0;j<=k+1;j++) dp[i][j]=-1e14;
	dp[0][0]=0;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k;j++){
		if(dp[i][j]<-1e13) continue;
		dp[i][j]+=dt[i][j];
		dp[i+1][0]=max(dp[i][j],dp[i+1][0]);
		if(j!=k) dp[i+1][j+1]=max(dp[i][j]-d,dp[i+1][j+1]);
	}
	ll ans=dp[n][0];
	for(int i=1;i<=k;i++) ans=max(ans,dp[n][i]);
	cout<<ans<<'\n';
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	if(c==17||c==18){
		while(t--){
			cin>>n>>m>>k>>d;
			ll ans=0;
			for(int i=1;i<=m;i++){
				int x,y,v;cin>>x>>y>>v;
				if(y>k) continue;
				ans+=max(0ll,v-1ll*d*y);
			}
			cout<<ans<<'\n';
		}
	}
	else while(t--) solve();
	return 0;
}