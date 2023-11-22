#include<bits/stdc++.h>
using namespace std;
int x[110000],y[110000],v[110000];
long long dp[1100][1100],w[1100][1100];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		int n,m,k,d;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)scanf("%d%d%d",&x[i],&y[i],&v[i]);
		dp[0][0]=0;
		for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)w[i][j]=0;
		for(int i=1;i<=m;i++)if(y[i]<=k)w[x[i]][y[i]]+=v[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)w[i][j]+=w[i][j-1];
		for(int i=1;i<=n;i++)for(int j=0;j<=min(k,i);j++){
			if(j==0){
				dp[i][0]=0;
				for(int t=0;t<=min(k,i-1);t++)dp[i][0]=max(dp[i][0],dp[i-1][t]);
			}
			else dp[i][j]=dp[i-1][j-1]+w[i][j]-d;
		}
		long long ans=0;
		for(int j=0;j<=k;j++)ans=max(ans,dp[n][j]);
		printf("%lld\n",ans);
	}
	return 0;
}