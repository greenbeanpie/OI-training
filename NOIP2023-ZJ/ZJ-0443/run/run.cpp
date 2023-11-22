#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int s=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c))
	{
		f=(c=='-');
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+c-'0';
		c=getchar();
	}
	return f?-s:s;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
int c,t,n,m,k,d,dp[1005][1005];
struct rw
{
	int d,w;	
};
vector<rw>s[1005];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	{
		for(int i=0;i<=1004;i++)
		{
			s[i].clear();
		}
		memset(dp,0,sizeof(dp));
		n=read();
		m=read();
		k=read();
		d=read();
		for(int i=1,x;i<=m;i++)
		{
			x=read();
			rw p;
			p.d=read();
			p.w=read();
			s[x].emplace_back(p);
		}
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=mx;
			mx=dp[i][0];
			for(int j=1;j<=k&&j<=i;j++)
			{
				dp[i][j]=dp[i-1][j-1]-d;
				for(auto u:s[i])
				{
					if(j>=u.d)
					{
						dp[i][j]+=u.w;
					}
				}
				mx=max(mx,dp[i][j]);
			}
		}
		int ans=-1;
		for(int i=0;i<=k;i++)
		{
			ans=max(ans,dp[n][i]);
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}