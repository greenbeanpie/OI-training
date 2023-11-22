#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int op,T,n,m,k;
long long d,f[N][N],dp[N][N];
int read()
{
	int x=0,p=1;
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*p;
}
void init()
{
	while(T--)
	{
		long long ans=0;
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();long long z=read();
			if(z>d*y&&y<=k)ans+=z-d*y;
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>op>>T;
	if(op>9){init();return 0;}
	while(T--)
	{
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				f[i][j]=0;
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();long long z=read();
			f[x][y]+=z;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				f[i][j]+=f[i][j-1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				dp[i][j]=-0x3fffffffffffffff;
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=max(dp[i][0],dp[i-1][0]);
			for(int j=1;j<=k;j++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+f[i][j]-d),
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
		}
		long long ans=-0x3fffffffffffffff;
		for(int i=0;i<=k;i++)
			ans=max(ans,dp[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}