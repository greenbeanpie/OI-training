#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
ll dp[N<<3][N];
int n,m,k,d;
struct Reward{
	int x,y;ll v;
	bool operator<(const Reward &a)const{
		return x!=a.x?x<a.x:y<a.y;
	}
}r[N];
void solve(){
	memset(dp,0xc0,sizeof dp);
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++){
		cin>>r[i].x>>r[i].y>>r[i].v;
	}
	dp[0][0]=0;
	sort(r+1,r+m+1);
	for(int i=1,j=0;i<=n;i++){
		while(r[j].x<i) j++;
		dp[i][0]=dp[i-1][0];
		ll sum=0;
		for(int p=1;p<=k;p++) dp[i][0]=max(dp[i][0],dp[i-1][p]);
		for(int p=1;p<=k;p++){
			int q=j;
			while(r[j].x==i&&r[j].y<=p) sum+=r[j++].v;
			dp[i][p]=max(dp[i][p],dp[i-1][p-1]+sum-d);
		}
	}
	ll ans=0;
	for(int p=0;p<=k;p++) ans=max(ans,dp[n][p]);
//	for(int i=1;i<=n;i++) for(int p=0;p<=k;p++) cout<<dp[i][p]<<" \n"[p==k];
	cout<<ans<<"\n";
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
11:02 Genshin(actually this problem),start!(?) 
11:55+ si ji le, da!!!! ji!!!!!!!!  but 36 pts bao li
*/
