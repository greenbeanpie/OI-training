#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace solve
{
	const int maxn=1010;
	int n,m,k,d;
	struct CHA
	{
		int x,y,val;
		CHA(int _x=0,int _y=0,int _v=0){
			x=_x,y=_y,val=_v;
		}
	};
	CHA c[maxn];
	int dp[maxn][maxn]={0};
//	map<pair<int,int>,int>pos;
	int ans;
	int main()
	{
		memset(dp,0,sizeof(dp));
//		pos.clear();
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>c[i].x>>c[i].y>>c[i].val;
//			pos[make_pair(c[i].x,c[i].y)]=i;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k&&j<=i;j++)
			{
				int val=0;
				for(int l=1;l<=m;l++)
					if(c[l].x==i&&j>=c[l].y)
						val+=c[l].val;
				dp[i][j]=dp[i-1][j-1]-d+val;		
			}
//				(pos.find(make_pair(i,j))!=pos.end()?c[pos[make_pair(i,j)]].val:0);
			if(i>1)
			{
				dp[i][0]=dp[i-1][0];
				for(int j=1;j<=k;j++)
					dp[i][0]=max(dp[i][0],dp[i-1][j]);
			}
		}
		ans=0;
//		for(int i=1;i<=n;i++)
//			for(int j=0;j<=k;j++)
//				cout<<dp[i][j]<<" \n"[j==k];
		for(int i=0;i<=k;i++)
			ans=max(ans,dp[n][i]);
		cout<<ans<<"\n";
		return 0;
	}
}
int c,t;
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
		solve::main();
	return 0;
}