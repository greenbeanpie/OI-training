#include<bits/stdc++.h>
using namespace std;
const long long inf=1e10;
int nu,t,n,m,k,d;
long long dp[2][10000010];
long long ta=0;
int now;
struct ch{
	long long x,y,v;
}chan[100100];
bool cmp(ch a,ch b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int main(){
	cin.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>nu>>t;
	while(t--){
		ta=1;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>chan[i].x>>chan[i].y>>chan[i].v;
		}
		for(int i=0;i<=k;i++) dp[0][i]=dp[1][i]=-inf;
		dp[0][0]=0;
		sort(chan+1,chan+m+1,cmp);
		for(int i=1;i<=n;i++){
			now^=1;
			dp[now][0]=dp[now^1][0];
			while(chan[ta].x<i&&ta<=m) ta++;
			int backup=ta;
			for(int j=1;j<=min(k,i);j++){
				dp[now][0]=max(dp[1^now][j],dp[now][0]);
				dp[now][j]=dp[now^1][j-1]-d;
				while(i==chan[ta].x&&j>=chan[ta].y&&ta<=m){
					dp[now][j]+=chan[ta].v;
					ta++;
				}
				ta=backup;
			}
		}	
		long long ans=-inf;
		for(int i=0;i<=k;i++) ans=max(ans,dp[now][i]);
		cout<<ans<<"\n";
	}
	return 0;
}
