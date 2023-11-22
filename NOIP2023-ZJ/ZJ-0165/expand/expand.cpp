#include<bits/stdc++.h>
using namespace std;
bool flag;
int c,n,m,q;
int x[2010],y[2010];
int tmpx[2010],tmpy[2010];
bool vis[2010][2010],dp[2010][2010];
bool dfs(int a,int b)
{
	if(a==n&&b==m)
		return 1;
	if(vis[a][b])
		return dp[a][b];
	vis[a][b]=1;
	dp[a][b]=0;
	if(a==n)
	{
		dp[a][b]=1;
		for(int i=b+1;i<=m;++i)
			dp[a][b]&=(x[n]>y[i]);
		return dp[a][b];
	}
	if(b==m)
	{
		dp[a][b]=1;
		for(int i=a+1;i<=n;++i)
			dp[a][b]&=(x[i]>y[m]);
		return dp[a][b];
	}
	if(x[a]>y[b+1])
		dp[a][b]|=dfs(a,b+1);
	if(x[a+1]>y[b])
		dp[a][b]|=dfs(a+1,b);
	if(x[a+1]>y[b+1])
		dp[a][b]|=dfs(a+1,b+1);
	return dp[a][b];
}
bool check()
{
	if(x[1]==y[1])
		return false;
	if(n==1)
		return true;
	flag=0;
	if(x[1]<y[1])
	{
		swap(n,m);
		swap(x,y);
		flag=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			vis[i][j]=dp[i][j]=0;
	return dfs(1,1);
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",x+i);
		tmpx[i]=x[i];
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d",y+i);
		tmpy[i]=y[i];
	}
	printf("%d",check());
	if(flag)
	{
		swap(n,m);
		swap(x,y);
	}
	for(int i=1;i<=q;++i)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=n;++j)
			x[j]=tmpx[j];
		for(int j=1;j<=m;++j)
			y[j]=tmpy[j];
		for(int i=1;i<=kx;++i)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		for(int i=1;i<=ky;++i)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		printf("%d",check());
		if(flag)
		{
			swap(n,m);
			swap(x,y);
		}
	}
	puts("");
	return 0;
}
