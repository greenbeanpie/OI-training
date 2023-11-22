#include<bits/stdc++.h>
#define int long long
#define N (1005)
using namespace std;
int n,m,k,c,T,d,minn,maxx,x,y,z;
int dp[N][N][2],f[N][N];
int max(int x,int y){return x>y?x:y;}
void solve()
{
	maxx=-1e18;
	memset(dp,128,sizeof dp);
	memset(f,0,sizeof f);
	cin>>n>>m>>k>>d;
	for(;m--;)
	  {
	  	cin>>x>>y>>z;
	    f[x-y+1][x]+=z;
	  }
	for(int i=1;i<=n;++i)
	  for(int j=i-1;j>=1;--j)
	    f[j][i]+=f[j+1][i];
	dp[1][0][1]=-d+f[1][1];
	dp[1][0][0]=0;
	for(int i=2;i<=n;++i)
	  {
	  	int maxs=-1e18;
	    for(int l=0;l<=i-2&&l<=k;++l)
	      {
	      	dp[i][0][0]=max(dp[i][0][0],dp[i-1][l][0]);
	 		dp[i][0][1]=max(dp[i][0][1],dp[i-1][l][0]-d+f[i][i]);
	 		maxs=max(maxs,dp[i][0][0]);
	 		maxs=max(maxs,dp[i][0][1]);
	      	if(l+1<=k)
	      	  {
	      	    if(l+2<=k)
			      dp[i][l+1][1]=max(dp[i][l+1][1],dp[i-1][l][1]-d+f[i-l-1][i]);
				dp[i][l+1][0]=max(dp[i][l+1][0],dp[i-1][l][1]);
	      	    maxs=max(maxs,dp[i][l+1][1]);
	      	    maxs=max(maxs,dp[i][l+1][0]); 
		  	  }
		  }
		maxx=max(maxx,maxs);
	  }
	cout<<max(maxx,0ll)<<'\n';
	return ;
}
/*
dp i,j,0/1 
表示到第i天，
前面已经连续跑了j天步，
0/1表示这天跑还是不跑 
*/
signed main(void)
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	for(;T--;)solve();
	return 0;
}
/*
1 1 	
3 2 2 1
2 2 4
3 2 3

1 2 4
2 3 3


*/
