#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int x[500010],y[500010];
int xp[500010],xv[500010];
int yp[500010],yv[500010];
int ans[500010];
int dp[2010][2010];
int c;
int solve()
{
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(dp[i][j]==0)
				continue;
			if(x[i]<y[j])
				dp[i+1][j]=dp[i+1][j+1]=dp[i][j+1]=1;
		}
	/*
	cerr<<endl;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m+1;j++)
			cerr<<dp[i][j];
		cerr<<endl;
	}
	*/
	return dp[n+1][m+1];	
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
	ans[0]=solve();
	for(int i=1;i<=q;i++)
	{
		int dx,dy;
		scanf("%d%d",&dx,&dy);
		for(int j=1;j<=dx;j++)
			scanf("%d%d",&xp[j],&xv[j]),swap(x[xp[j]],xv[j]);
		for(int j=1;j<=dy;j++)
			scanf("%d%d",&yp[j],&yv[j]),swap(y[yp[j]],yv[j]);
		int swp=0;
		if(x[1]>y[1])
		{
			for(int i=1;i<=max(n,m);i++)
				swap(x[i],y[i]);
			swp=1;
		}
		ans[i]=solve();
		if(swp)
		{
			for(int i=1;i<=max(n,m);i++)
				swap(x[i],y[i]);
		}
		for(int j=1;j<=dx;j++)
			swap(x[xp[j]],xv[j]);
		for(int j=1;j<=dy;j++)
			swap(y[yp[j]],yv[j]);
	}
	for(int i=0;i<=q;i++)
		putchar(ans[i]+'0');
	puts("");
}
