#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int NN=1005;
const int MM=100005;
const LL INF=0x3f3f3f3f3f3f3f3f;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
int opt,t,n,m,k;
LL d,dp[NN][NN],dp10[4][MM],dp15[MM][105];
struct cha
{
	int x,y;
	LL val;
}a[MM];
bool cmp(cha x,cha y)
{
	return x.x<y.x;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	opt=read(),t=read();
	while(t--)
	{
		if(opt<=9)
		{
			int l=1;
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++)
				a[i].x=read(),a[i].y=read(),a[i].val=read();
			sort(a+1,a+m+1,cmp);
			for(int i=0;i<=n;i++)
				for(int j=0;j<=k;j++)
					dp[i][j]=-INF;
			dp[0][0]=0;
			for(int i=1;i<=n;i++)
			{
				dp[i][0]=dp[i-1][k];
				for(int j=0;j<k;j++)
				{
					dp[i][0]=max(dp[i][0],dp[i-1][j]);
					dp[i][j+1]=dp[i-1][j]-d;
				}
				while(l<=m&&a[l].x==i)
				{
					for(int j=a[l].y;j<=k;j++)
						dp[i][j]+=a[l].val;
					l++;
				}
			}
			LL ans=-INF;
			for(int j=0;j<=k;j++)
				ans=max(ans,dp[n][j]);
			printf("%lld\n",ans);
		}
		if(opt==15||opt==16)
		{
			LL gp;
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++)
				a[i].x=read(),a[i].y=read(),a[i].val=read();
			sort(a+1,a+m+1,cmp);
			a[0].x=0;
			for(int i=0;i<=m;i++)
				for(int j=0;j<=k;j++)
					dp15[i][j]=-INF;
			dp15[0][0]=0;
			for(int i=1;i<=m;i++)
			{
				gp=a[i].x-a[i-1].x;
				if(gp==0)
				{
					for(int j=0;j<=k;j++)
						dp15[i][j]=dp15[i-1][j];
				}
				else
				{
					for(int j=0;j<=k;j++)
						dp15[i][0]=max(dp15[i][0],dp15[i-1][j]);
					for(int j=0;j+gp<=k;j++)
						dp15[i][j+gp]=dp15[i-1][j]-d*gp;
					for(int j=0;j<gp;j++)
						dp15[i][j]=dp15[i][0]-d*j;
				}
				for(int j=a[i].y;j<=k;j++)
					dp15[i][j]+=a[i].val;
			}
			LL ans=-INF;
			for(int j=0;j<=k;j++)
				ans=max(ans,dp15[m][j]);
			printf("%lld\n",ans);
		}
		if(opt>=10&&opt<=14)
		{
			LL gp;
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++)
				a[i].x=read(),a[i].y=read(),a[i].val=read();
			sort(a+1,a+m+1,cmp);
			a[0].x=0;
			for(int i=0;i<=m;i++)
				for(int j=0;j<=k;j++)
					dp10[i%2][j]=-INF;
			dp10[0][0]=0;
			for(int i=1;i<=m;i++)
			{
				gp=a[i].x-a[i-1].x;
				if(gp==0)
				{
					for(int j=0;j<=k;j++)
						dp10[i%2][j]=dp10[(i+1)%2][j];
				}
				else
				{
					dp10[i%2][0]=-INF;
					for(int j=0;j<=k;j++)
						dp10[i%2][0]=max(dp10[i%2][0],dp10[(i+1)%2][j]);
					for(int j=0;j+gp<=k;j++)
						dp10[i%2][j+gp]=dp10[(i+1)%2][j]-d*gp;
					for(int j=0;j<gp;j++)
						dp10[i%2][j]=dp10[i%2][0]-d*j;
				}
				for(int j=a[i].y;j<=k;j++)
					dp10[i%2][j]+=a[i].val;
			}
			LL ans=-INF;
			for(int j=0;j<=k;j++)
				ans=max(ans,dp10[m%2][j]);
			printf("%lld\n",ans);
		}
		if(opt==17||opt==18)
		{
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++)
				a[i].x=read(),a[i].y=read(),a[i].val=read();
			LL ans=0;
			for(int i=1;i<=m;i++)
			{
				if(a[i].val>d*a[i].y&&a[i].y<=k)
					ans+=a[i].val-d*a[i].y;
			}
			printf("%lld\n",ans);
		}
	}
}