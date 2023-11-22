#include<bits/stdc++.h>
#define int long long
#define DEBUG puts("en en shui ye mei kan de qi ni");
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
int dp[1010][1010],id,T,n,m,k,d;
//day
//to do
//limin
//jianshao

//biaoshiqianit
const int inf=1e15;
int ans=0,sum[1010][1010];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	id=read();
	T=read();
	while(T--)
	{
		memset(dp,0x80,sizeof(dp));
		memset(sum,0,sizeof(sum));
		n=read();
		m=read();
		k=read();
		d=read();
		dp[0][0]=0;
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read(),v=read();
			sum[x][y]+=v;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				sum[i][j]+=sum[i][j-1];
			}
		}
		ans=-inf;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0];
			for(int j=1;j<=k;j++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d);
				dp[i][0]=max(dp[i-1][j],dp[i][0]);
				dp[i][j]+=sum[i][j];
				if(i==n)ans=max(ans,dp[i][j]);
			}
			if(i==n)
			ans=max(ans,dp[i][0]);
		}
		print(ans);
		puts("");
	}
	return 0;
}