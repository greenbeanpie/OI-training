#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010;
ll c,t,n,m,k,d,maxn=-1e18; 
ll dp[N][N],a[N][N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		maxn=-1e18;
		memset(a,0,sizeof a);
		memset(dp,-0x3f3f3f3f,sizeof dp);
		for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),a[x][y]=z;
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=min(k,(ll)i);j>=1;j--)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i][j]-d);
				maxn=max(maxn,dp[i][j]);
			}
			for(int j=min(k,(ll)i-1);j>=1;j--)dp[i][0]=max(dp[i-1][j]-d,dp[i][0]),maxn=max(maxn,dp[i][0]);
		}
		cout<<maxn<<"\n";
	}
	return 0;
}
