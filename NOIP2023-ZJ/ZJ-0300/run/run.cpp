#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ct,T,n,m,k,d;
struct Node
{
	int x,y,v;
}c[101000];
ll dp[2][101000];
bool cmp(Node x,Node y)
{
	if(x.x!=y.x)return x.x<y.x;
	return x.y<y.y;
}
int a[101000];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&ct,&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i)
			scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].v);
		sort(c+1,c+m+1,cmp);
		for(int i=1;i<=m;++i)a[i]=c[i].x;
		ll ans=-1e18;
		for(int j=0;j<=k;++j)dp[0][j]=0;
		for(int i=1;i<=m;++i)//n->m
		{
			int p=i&1;
			for(int j=0;j<=k;++j)dp[p][j]=-1e18;
			dp[p][0]=dp[p^1][0];
			ll maxn=0;
			for(int j=0;j<=k;++j)maxn=max(maxn,dp[p^1][j]);
			for(int j=1;j<=k;++j)
			{	
				ll val=(j>=c[i].y?c[i].v:0);
				int dt=a[i]-a[i-1];
				if(j>=dt)
					dp[p][j]=max(dp[p][j],dp[p^1][j-dt]-(ll)d*dt+val);
				else
					dp[p][j]=max(dp[p][j],maxn-(ll)d*j+val);
//				dp[p][j]=max(dp[p][j],dp[p^1][j-min(a[i]-a[i-1],j)]-(ll)d*min(a[i]-a[i-1],j)+c[i].v);
				if(dt!=0)dp[p][0]=max(dp[p][0],dp[p^1][j]);
			}
		}
		for(int j=0;j<=k;++j)ans=max(ans,dp[m&1][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
