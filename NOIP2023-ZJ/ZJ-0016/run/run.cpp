#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int sid,T,n,m,k;
ll d,dp[1005][1005],val[1005][1005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&sid,&T);
	while(T--){
		memset(val,0,sizeof(val));
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for(int i=1,x,y,v;i<=m;i++){
			scanf("%d%d%d",&x,&y,&v);
			val[x][y]+=v;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				val[i][j]+=val[i][j-1];
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++){
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+val[i+1][j+1]-d);
				dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
			}
		ll ans=0;
		for(int j=0;j<=k;j++)ans=max(ans,dp[n][j]);
		printf("%lld\n",ans);
	}
	return 0;
}