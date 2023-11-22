#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=2010;

int x[maxn],y[maxn],px[maxn],vx[maxn],py[maxn],vy[maxn];
bool dp[maxn][maxn];

bool bWork(int *x,int *y,int n,int m)
{
	int i,j;
	for(i=1;i<=n;i++) memset(dp[i]+1,0,m);
	dp[1][1]=true;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(x[i]>=y[j]) continue;
			if(i>1) dp[i][j]|=dp[i-1][j];
			if(j>1) dp[i][j]|=dp[i][j-1];
			if(i>1&&j>1) dp[i][j]|=dp[i-1][j-1];
		}
	}
	return dp[n][m];
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand2.out","w",stdout);
	int C,n,m,q,i;
	cin>>C>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>x[i];
	for(i=1;i<=m;i++) cin>>y[i];
	auto solve=[&]
	{
		if(x[1]<y[1]&&x[n]<y[m]) cout<<bWork(x,y,n,m);
		else if(x[1]>y[1]&&x[n]>y[m]) cout<<bWork(y,x,m,n);
		else cout<<0;
	};
	solve();
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(i=1;i<=kx;i++)
		{
			cin>>px[i]>>vx[i];
			swap(x[px[i]],vx[i]);
		}
		for(i=1;i<=ky;i++)
		{
			cin>>py[i]>>vy[i];
			swap(y[py[i]],vy[i]);
		}
		solve();
		for(i=1;i<=kx;i++) swap(x[px[i]],vx[i]);
		for(i=1;i<=ky;i++) swap(y[py[i]],vy[i]);
	}
	cout<<'\n';
	return 0;
}
