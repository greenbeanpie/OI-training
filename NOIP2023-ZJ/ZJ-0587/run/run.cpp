#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
struct node{
	int x,y,v;
	bool operator < (const node &s){
		return x<s.x;
	}
}a[MAXN];
int n,m,k,d;
long long dp[2][MAXN];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int id,t;
	scanf("%d%d",&id,&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i(1);i<=m;++i)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
		sort(a+1,a+m+1);
		int z=1;
		long long ans=0;
		for(int i(0);i<=k;++i)
		dp[0][i]=dp[1][i]=-1e18-7;
		dp[0][0]=0;
		for(int i(1);i<=min(a[m].x,n);++i)
		{
			dp[i%2][0]=dp[(i-1)%2][0];
			for(int j(1);j<=k;++j)
			{
				if(dp[(i-1)%2][j-1]!=-1e18-7)
				dp[i%2][j]=dp[(i-1)%2][j-1]-((long long) d);
				dp[i%2][0]=max(dp[i%2][0],dp[(i-1)%2][j]);
			}
			while(i==a[z].x&&z<=m)
			{
				for(int j(a[z].y);j<=k;++j)
					if(dp[i%2][j]!=-1e18-7)
						dp[i%2][j]=dp[i%2][j]+((long long)a[z].v);
				z++;
			}
			for(int j(0);j<=k;++j)
				ans=max(ans,dp[i%2][j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
