#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000
const int N=1e5+10;
int c,T;
ll n,m,k,d;
ll x,y,v;
ll a[1005][1005];
ll dp[1005][1005],ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				a[i][j]=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			a[x][y]+=v;
		}
		for(int i=0;i<=n;i++)
			for(int j=1;j<=k;j++)
				a[i][j]+=a[i][j-1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				dp[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0];
			for(int j=1;j<=k;j++)
			{
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
				dp[i][j]=dp[i-1][j-1]-d+a[i][j];
			}
		}
		/*
		for(int i=1;i<=n;i++)
		{
			cout<<i<<":";
			for(int j=0;j<=k;j++)
				cout<<dp[i][j]<<" ";
				cout<<endl;
		}
		*/
		ans=-INF;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				ans=max(ans,dp[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
