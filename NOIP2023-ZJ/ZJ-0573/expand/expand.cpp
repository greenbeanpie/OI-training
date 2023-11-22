#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;

int c,n,m,q;
int x[N],y[N];
int f[N],g[N];

int px[N],vx[N];
int py[N],vy[N];

bool dp[N][N];

bool judge()
{
	if((f[1]==g[1])||(f[n]==g[m]))
		return false;
	if((f[1]<g[1])^(f[n]<g[m]))
		return false;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	if(f[1]<g[1])
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(f[i]<g[j])
					dp[i][j]=dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1];
			}
		return dp[n][m];
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(f[i]>g[j])
					dp[i][j]=dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1];
			}
		return dp[n][m];
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>m>>n>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i];
		f[i]=x[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>y[i];
		g[i]=y[i];
	}
	if(judge())
		cout<<1;
	else
		cout<<0;
	
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			cin>>px[i]>>vx[i];
			f[px[i]]=vx[i];
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>py[i]>>vy[i];
			g[py[i]]=vy[i];
		}
		
		if(judge())
			cout<<1;
		else
			cout<<0;
		
		for(int i=1;i<=kx;i++)
			f[px[i]]=x[px[i]];
		for(int i=1;i<=ky;i++)
			g[py[i]]=y[py[i]];
	}
	cout<<endl;
	return 0;
}
