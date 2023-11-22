#include <bits/stdc++.h>
using namespace std;
long long ans,x[500001],y[500001],v[500001],sum[1001][1001],dp[1001][1001];
int n,t,m,k,d,i,j,c;
int main()
{
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>m>>k>>d;
		ans=0;
		for (i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&v[i]);
		if (c==17 || c==18)
		{
			for (i=1;i<=m;i++) if ((v[i]-d*y[i])>0) ans+=v[i]-d*y[i];
			cout<<ans<<endl;
		}else
		{
			for (i=0;i<=n;i++) for (j=0;j<=k;j++) sum[i][j]=0,dp[i][j]=-1e9;
			dp[0][0]=0;
			for (i=1;i<=m;i++) sum[x[i]][y[i]]+=v[i];
			for (i=1;i<=n;i++) for (j=1;j<=k;j++) sum[i][j]+=sum[i][j-1];
			for (i=1;i<=n;i++) 
			{
				for (j=0;j<=min(i-1,k);j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
				for (j=1;j<=min(i,k);j++) dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+sum[i][j]);
			}
			for (i=0;i<=min(n,k);i++) ans=max(ans,dp[n][i]);
			cout<<ans<<endl;
		}
	}
}