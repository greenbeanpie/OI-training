#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-48;ch=getchar();}
	return s*f;
}
struct pos{
	int lim,val;
	friend bool operator < (pos a,pos b)
	{
		return a.lim<b.lim;
	}
};
int c,t,n,m,k,d;
int x[N],y[N],v[N],dp[1005][1005];
vector<pos> p[N];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		k=read();
		d=read();
		if(c<=9) for(int i=1;i<=n;i++) p[i].clear();
		for(int i=1;i<=m;i++)
		{
			x[i]=read();
			y[i]=read();
			v[i]=read();
			if(c<=9) p[x[i]].push_back({y[i],v[i]});
		}
		if(c<=9) for(int i=1;i<=n;i++) sort(p[i].begin(),p[i].end());
		if(c<=9)
		{
			memset(dp,-0x3f,sizeof(dp));
			dp[0][0]=0;
			int ma=0;
			for(int i=1;i<=n;i++)
			{
				dp[i][0]=ma;
				ma=dp[i][0];
				int ind=0,l=p[i].size(),pre=0;
				for(int j=1;j<=min(i,k);j++)
				{
					while(ind<l&&j>=p[i][ind].lim) pre+=p[i][ind++].val;
					dp[i][j]=dp[i-1][j-1]-d+pre;
					ma=max(dp[i][j],ma);
				}
			}
			int ans=-inf;
			for(int i=0;i<=k;i++)
			{
				ans=max(ans,dp[n][i]);
			}
			cout<<ans<<endl;
			continue;
		}
		if(c==17||c==18)
		{
			int ans=0;
			for(int i=1;i<=m;i++)
			{
				if(y[i]>k) continue;
				ans+=max(0ll,v[i]-y[i]*d);
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}