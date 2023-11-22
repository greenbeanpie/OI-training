#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,h,j,cnt,ans[10000],f[10000],g[10000],cot,dp[3000][3000][2];
struct xx
{
	int p,y,g;
}xg[10000];
void sv()
{
	memset(dp,0,sizeof(dp));
	dp[0][0][1]=1;
	dp[0][0][0]=1;
	for(int i=1;i<=b;i++)
	{
		for(int n=1;n<=c;n++)
		{
			if(f[i]<g[n])dp[i][n][0]=max(dp[i-1][n-1][0],max(dp[i-1][n][0],dp[i][n-1][0]));
			else if(f[i]>g[n])dp[i][n][1]=max(dp[i-1][n-1][1],max(dp[i-1][n][1],dp[i][n-1][1]));
		}
	}
	cot++;
	ans[cot]=max(dp[b][c][0],dp[b][c][1]);
	return;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=1;i<=b;i++)cin>>f[i];
	for(int i=1;i<=c;i++)cin>>g[i];
	sv();
	while(d>0)
	{
		d--;
		cin>>h>>j;
		for(int i=1;i<=h;i++)
		{
			cnt++;
			cin>>xg[cnt].p>>xg[cnt].g;
			xg[cnt].y=f[xg[cnt].p];
			f[xg[cnt].p]=xg[cnt].g;
		}
		for(int i=1;i<=j;i++)
		{
			cnt++;
			cin>>xg[cnt].p>>xg[cnt].g;
			xg[cnt].y=g[xg[cnt].p];
			g[xg[cnt].p]=xg[cnt].g;
		}
		sv();
		for(int i=1;i<=j;i++)
		{
			g[xg[cnt].p]=xg[cnt].y;
			cnt--;
		}
		for(int i=1;i<=h;i++)
		{
			f[xg[cnt].p]=xg[cnt].y;
			cnt--;
		}	
	}
	for(int i=1;i<=cot;i++)cout<<ans[i];
	return 0;
}