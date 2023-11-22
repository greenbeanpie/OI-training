#include <bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
inline ll read()
{
	ll k=0,pos=1;char c=getchar();
	while (!isdigit(c)&&c!='-')c=getchar();
	if (c=='-')pos=-1,c=getchar();
	while (isdigit(c))k=(k<<3)+(k<<1)+c-'0',c=getchar();
	return k*pos;
}
struct node
{
	int x,y;
	ll v;
};
vector<node>q[100100];
bool vis[100100];
int x[100100],y[100100],n,m,k;
ll f[100100],a[100100],sum[100100],d,v[100100];
inline void check()
{
	ll ans=0;
	f[0]=0;
	for (re int tot=0;tot<=(1<<n)-1;tot++)
	{
		int len=0,val=tot;
		while (len<n)
		{
			a[++len]=val%2;
			val/=2;
		}
		bool flag=1;
		ll Max=0;
		memset(sum,0,sizeof(sum));
		for (re int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
			if (a[i]==0)f[i]=f[i-1];
			else if (a[i]==1)
			{
				if (i>=k+1&&sum[i]-sum[i-k-1]==k+1){flag=0;break;}
				f[i]=f[i-1]-d;
				if (vis[i])
				{
					int l=q[i].size();
					for (re int j=0;j<l;j++)
					{
						int x=q[i][j].x,y=q[i][j].y,v=q[i][j].v;
						if (sum[x]-sum[x-y]==y)f[i]+=v;
					}
				}
			}
			Max=max(Max,f[i]);
		}
		if (flag)ans=max(ans,Max);
	}
	printf("%lld\n",ans);
}
ll dp[100100][2],l[100100],r[100100],len[100100];
inline void force()
{
	n=read(),m=read(),k=read(),d=read();
	for (re int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		v[i]=read();
		l[i]=x-y+1,r[i]=x;
		len[i]=y;
	}
	memset(dp,0,sizeof(dp));
	for (re int i=1;i<=m;i++)
	{
		if (v[i]-len[i]*d>0)
		{
			if (l[i]==r[i-1]+1)
			{
				if (dp[i-1][0]<dp[i-1][1]&&len[i-1]+len[i]<=k)
				{
					dp[i][1]=dp[i-1][1]-len[i]*d+v[i];
					len[i]+=len[i-1];
				}
				else dp[i][1]=dp[i-1][0]-len[i]*d+v[i];
			}
			else dp[i][1]=max(dp[i-1][0],dp[i-1][1])-len[i]*d+v[i];
		}
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
	}
	printf("%lld\n",max(dp[m][1],dp[m][0]));
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c=read(),t=read();
	while (t--)
	{
		if (c>2){force();continue;}
		memset(vis,0,sizeof(vis));
		n=read(),m=read(),k=read(),d=read();
		for (re int i=1;i<=n;i++)q[i].clear();
		for (re int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			ll v=read();
			q[x].push_back((node){x,y,v});
			vis[x]=1;
		}
		check();
	}
	return 0;
}