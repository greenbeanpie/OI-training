#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f;;
const int MAXN = 1e5 + 3;
namespace sub1
{
	const int MAXN = 1e3 + 3;
	int n,m,k,d;
	int dp[MAXN][MAXN][2];
	struct ac
	{
		int x,y,w;
	};
	vector<ac> acv[MAXN];
	void work()
	{
		for(int i = 1;i<MAXN;i++)acv[i].clear();
		cin>>n>>m>>k>>d;
		for(int x,y,w,i = 1;i<=m;i++){
			cin>>x>>y>>w;
			acv[x].push_back({x,y,w});
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				dp[i][j][0] = dp[i][j][1] = -INF;
			}
		}dp[1][0][0] = 0;
			
			for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= min(i-1,k); j++)
			{
				if(j+2<=k)
				dp[i + 1][j + 1][1] = dp[i][j][1] - d;
				dp[i + 1][0][0] = max(dp[i][j][0],dp[i + 1][0][0]);
				dp[i + 1][0][1] = max(dp[i][j][0],dp[i + 1][0][1]);
				dp[i+1][j+1][0] = dp[i][j][1]-d;
			}
			if(acv[i].size()){
				for(auto v:acv[i]){
					for(int j = max(v.y-1,0ll);j<=min(i-1,k);j++)
					dp[i+1][j+1][0] = max(dp[i][j][1]-d+v.w,dp[i+1][j+1][0]);
					for(int j = max(v.y-1,0ll);j<=min(i-1,k-1);j++)
					dp[i+1][j+1][1] = max(dp[i][j][1]-d+v.w,dp[i+1][j+1][1]);					
				}
			}
		}
		int ans = -INF;
		for(int i = 0;i<=k;i++){
			ans = max(ans,max(dp[n][i][0],dp[n][i][1]));
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		sub1::work();
	}
	return 0;
}