#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,T;
int n,m,k,d;
vector<pair<int,int> >mp[1005];
int dp[1005][1005];
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) {
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1; i<=n; ++i) mp[i].clear();
		for(int i=0; i<=n; ++i) {
			for(int j=0; j<=k; ++j) {
				dp[i][j]=-inf;
			}
		}
		for(int i=1; i<=m; ++i) {
			int x,y,v;
			scanf("%lld%lld%lld",&x,&y,&v);
			mp[x].push_back(make_pair(y,v));
		}
		dp[0][0]=0;
		for(int i=1; i<=n; ++i) {
			int mx=-inf;
			for(int j=0; j<=k; ++j) {
				mx=max(mx,dp[i-1][j]);
			}
			dp[i][0]=mx;
			for(int j=1; j<=k; ++j) {
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d);
			}
			for(int j=0; j<mp[i].size(); ++j) {
				int y=mp[i][j].first,val=mp[i][j].second;
				for(int z=y; z<=k; ++z) {
					if(dp[i][z]!=inf) {
						dp[i][z]+=val;
					}
				}
			}
		}
		int mx=-inf;
		for(int j=0; j<=k; ++j) {
			mx=max(mx,dp[n][j]);
		}
		printf("%lld\n",mx);
	}
	return 0;
}
