#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010];
long long jl[1010][1010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=1000;i++)
		dp[0][i]=-1e18;
	while(t--){
		memset(jl,0,sizeof(jl));
		int n,m,k,d;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		k=min(k,n);
		while(m--){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			jl[x][y]+=z;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++)
				jl[i][j]+=jl[i][j-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++)
				dp[i][j]=dp[i-1][j-1]-d+jl[i][j];
			dp[i][0]=dp[i-1][0];
			for(int j=1;j<=k;j++)
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
		}
		long long ans=-1e18;
		for(int i=0;i<=k;i++)
			ans=max(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}