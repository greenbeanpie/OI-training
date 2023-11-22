#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+5;
const int M = 1e5+5;
int c,T;
int n,m,k,d;
int cnt[N][N];
int dp[N];
int sum[N][N];
int ans;
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int i,j;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		memset(cnt,0,sizeof cnt);
		memset(dp,0xcf,sizeof dp);
		memset(sum,0,sizeof sum);
		dp[0]=0;
		cin>>n>>m>>k>>d;
		for(i=1;i<=m;i++)
		{
			int x,y,v;
			cin>>x>>y>>v;
			if(c==17||c==18)
			{
				if(y<=k&&y<=x)
				ans+=max(0ll,v-y*d);
			}
			else
			{
				cnt[x][y]+=v;
			}
			
		}
		if(c==17||c==18)
		{
			cout<<ans<<"\n";
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				cnt[i][j]+=cnt[i][j-1];
//				cnt[i][j]+=cnt[i-1][j-1];
//				cout<<cnt[i][j]<<" ";
			}
			for(j=1;j<=k;j++)
			sum[i][j]=cnt[i][j]+sum[i-1][j-1];//cerr<<sum[i][j]<<" ";
//			cerr<<"\n";
//			cout<<"\n";
//			cout<<"\n";
//			cout<<cnt[i][j]
		}
//		for(i=1;i<=n;i++)
//		for(j=1;j<=k;j+)
		for(i=1;i<=n;i++)
		{
			dp[i]=max(dp[i-1],0ll);
			for(j=1;j<=min(k,i);j++)
			{
				if(i-j-1<0)
				dp[i]=max(dp[i],sum[i][j]-j*d);
				else
				dp[i]=max(dp[i],dp[i-j-1]+sum[i][j]-j*d);
			}
		}
		cout<<dp[n]<<"\n";
	}
}
