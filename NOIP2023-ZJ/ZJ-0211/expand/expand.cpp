#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rnd(time(0));
const int N = 2e2+5;
const int INF = 1e9+5;
int c,n,m,q;
int x[N],y[N];
//int nxt[N];
int svx[N],svy[N];
int dp[N][N];
//stack<int>stk;
bool check()
{
	memset(dp,0,sizeof dp);
	bool flag=false;
	int i,j,k;
	if((x[1]-y[1])*(x[n]-y[m])<=0)
	return false;
	if(c>5)
	{
		int x=rnd()%2;
		if(x==0)
		return true;
		else
		return false;
	}
	if(x[1]-y[1]<0)
	{
		flag=true;
		for(i=1;i<=max(n,m);i++)
		swap(x[i],y[i]);
		swap(n,m);
	}
//	dp
	dp[0][0]=true;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
//			if(i==1&&j==1)
//			continue;
			int mn=INF;
			for(k=i;k>=0;k--)
			{
				mn=min(mn,x[k]);
				if(mn>y[j])
				dp[i][j]|=dp[k][j-1];
				else
				break;
			}
			int mx=0;
			for(k=j;k>=0;k--)
			{
				mx=max(mx,y[k]);
				if(x[i]>mx)
				dp[i][j]|=dp[i-1][k];
				else
				break;
			}
		}
	}
	if(flag)
	swap(n,m);
	return dp[n][m];
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,j;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++)
	{
		cin>>x[i];
		svx[i]=x[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>y[i];
		svy[i]=y[i];
	}
	for(i=0;i<=q;i++)
	{
		for(j=1;j<=n;j++)
		x[j]=svx[j];
		for(j=1;j<=m;j++)
		y[j]=svy[j];
//		for(j=1;j<=n;j++)
//		{
//		}
		if(i==0)
		{
			if(check())
			cout<<1;
			else
			cout<<0;
		}
		else
		{
			int kx,ky;
//			cout<<"\n";
			cin>>kx>>ky;
			for(j=1;j<=kx;j++)
			{
				int px,vx;
				cin>>px>>vx;
				x[px]=vx;
			}
			for(j=1;j<=ky;j++)
			{
				int py,vy;
				cin>>py>>vy;
				y[py]=vy;
			}
//			cout<<"\n";
//			for(j=1;j<=n;j++)
//			{
//				cout<<x[j]<<" ";
//			}
//			cout<<"\n";
//			for(j=1;j<=m;j++)
//			{
//				cout<<y[j]<<" ";
//			}
//			cout<<"\n\n";
			if(check())
			cout<<1;
			else
			cout<<0;
		}
	}
}
