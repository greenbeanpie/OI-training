#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int c,n,m,q,x[N],y[N],a[N],b[N],dp[N][N];
string s;
bool check1()
{
	memset(dp,0,sizeof dp);
    if(x[1]>y[1])dp[1][1]=1;
    else return false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i]>y[j])
			{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
			}
		}
	}
	if(x[n]>y[m]&&dp[n][m]==1)return true;
	else return false;
}
bool check2()
{
	memset(dp,0,sizeof dp);
    if(x[1]<y[1])dp[1][1]=1;
    else return false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i]<y[j])
			{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
			}
		}
	}
	if(x[n]<y[m]&&dp[n][m]==1)return true;
	else return false;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]),a[i]=x[i];
	for(int i=1;i<=m;i++)scanf("%d",&y[i]),b[i]=y[i];
	if(check1()==false)
	{
		if(check2()==true)s+='1';
		else s+='0';
	}
	else s+='1';
	for(int i=1;i<=q;i++)
	{
		int numx,numy;
		scanf("%d%d",&numx,&numy);
		for(int j=1;j<=numx;j++)
		{
			int pos,v;
			scanf("%d%d",&pos,&v);
			x[pos]=v;
		}
		for(int j=1;j<=numy;j++)
		{
			int pos,v;
			scanf("%d%d",&pos,&v);
			y[pos]=v;
		}
		if(check1()==false)
		{
			if(check2()==true)s+='1';
			else s+='0';
		}
		else s+='1';
		for(int j=1;j<=n;j++)x[j]=a[j];
		for(int j=1;j<=m;j++)y[j]=b[j];
	}
	cout<<s;
	return 0;
}
