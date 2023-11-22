#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int o,t;
long long dp[1010][1010];
unordered_map <long long,long long> mp;
struct node{
	int u,v,w;
}a[MAXN];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&o,&t);
	while(t--)
	{
		int n,m,k,d;
		long long ans=0;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		for(int i=1;i<=m;i++) mp[1ll*a[i].u*MAXN+a[i].v]+=a[i].w;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i-1,k);j++)
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
			long long x=0;
			for(int j=1;j<=min(i,k);j++)
			{
				x+=mp[1ll*i*MAXN+j];
				dp[i][j]=dp[i-1][j-1]-1ll*d+x;
			}
		}
		for(int i=0;i<=min(n,k);i++) ans=max(ans,dp[n][i]);
		printf("%lld\n",ans);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=min(i,k);j++)
			dp[i][j]=0;
		}
		mp.clear();
	}
	return 0;
}