#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 500005
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-48;ch=getchar();}
	return s*f;
}
int c,n,m,q;
int a[N],b[N],px[N],py[N],prea[N],preb[N];
int dp[2005][2005];
bool check()
{
	memset(dp,0,sizeof(dp));
	dp[1][1]=1; 
	if(a[1]>b[1]&&a[n]>b[m])
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!dp[i][j]) continue;
			if(i!=n&&j!=m&&a[i+1]>b[j+1]) dp[i+1][j+1]=1;
			for(int k=i+1;k<=n;k++)
			{
				if(a[k]<=b[j]) break;
				dp[k][j]=1;
			}
			for(int k=j+1;k<=m;k++)
			{
				if(a[i]<=b[k]) break;
				dp[i][k]=1;
			}
		}
		return dp[n][m];
	}
	else if(a[1]<b[1]&&a[n]<b[n])
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!dp[i][j]) continue;
			if(i!=n&&j!=m&&a[i+1]<b[j+1]) dp[i+1][j+1]=1;
			for(int k=i+1;k<=n;k++)
			{
				if(a[k]>=b[j]) break;
				dp[k][j]=1;
			}
			for(int k=j+1;k<=m;k++)
			{
				if(a[i]>=b[k]) break;
				dp[i][k]=1;
			}
		}
		return dp[n][m];
	}
	else return 0;
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++) a[i]=prea[i]=read();
	for(int i=1;i<=n;i++) b[i]=preb[i]=read();
	if(c<=7)
	{
		cout<<check();
		for(int i=1;i<=q;i++)
		{
			int kx=read();
			int ky=read();
			for(int i=1;i<=kx;i++) 
			{
				px[i]=read();
				a[px[i]]=read();
			}
			for(int i=1;i<=ky;i++)
			{
				py[i]=read();
				b[py[i]]=read();
			}
			cout<<check();
			for(int i=1;i<=kx;i++) a[px[i]]=prea[px[i]];
			for(int i=1;i<=ky;i++) b[py[i]]=preb[py[i]];
		}
		return 0;
	}
	return 0;
}