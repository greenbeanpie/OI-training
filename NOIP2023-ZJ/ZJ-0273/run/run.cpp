#include<bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=1005;
int C,T,n,m,k,d,x,y,v,mx,mn,dp[N][N],a[N][N];
main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	if (C==17||C==18)
	{
		while (T--)
		{
			cin>>n>>m>>k>>d;
			int ans=0;F(i,1,m)
			{
				cin>>x>>y>>v;
				ans+=max(0ll,v-d*y);
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while (T--)
	{
		cin>>n>>m>>k>>d;
		F(i,1,n)F(j,0,k)a[i][j]=0;
		F(i,1,m)
		{
			cin>>x>>y>>v;
			if (y>k)continue;
			a[x][y]+=v;
		}
		F(i,1,n)F(j,1,k)a[i][j]+=a[i][j-1];
		F(i,1,n)F(j,0,k)dp[i][j]=0;
		F(i,1,n)
		{
			F(j,0,k)dp[i][0]=max(dp[i][0],dp[i-1][j]);
			F(j,1,k)dp[i][j]=dp[i-1][j-1]+a[i][j]-d;
		}
		mx=0;F(i,0,k)mx=max(mx,dp[n][i]);
		cout<<mx<<'\n';
	}
	return 0;
}
