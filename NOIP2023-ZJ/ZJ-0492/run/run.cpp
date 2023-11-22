#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1001,maxm=1e5+5,MIN=LONG_LONG_MIN;
int dp[maxn][maxn];
int c,q,n,m,k,d;
struct point{
	int x,y,v;
}a[maxm];
inline bool cmp(point l,point r){return l.x<r.x||l.x==r.x&&l.y<r.y||l.x==r.x&&l.y==r.y&&l.v<r.v;}
inline int maxx(int *ddp)
{
	int temp=MIN;
	for(int i=0;i<=k;i++) temp=max(temp,ddp[i]);
	return temp;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&q);
	while(q--)
	{
		int cnt=1;
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k&&j<=i;j++)
			{
				if(j==0) dp[i][j]=maxx(dp[i-1]);
				else dp[i][j]=dp[i-1][j-1]-d;
				if(a[cnt].x==i&&a[cnt].y==j)
				{
					dp[i][j]+=a[cnt].v;
					cnt++;
				}
			}
		int ans=MIN;
		for(int i=0;i<=k;i++)
			ans=max(ans,dp[n][i]);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


