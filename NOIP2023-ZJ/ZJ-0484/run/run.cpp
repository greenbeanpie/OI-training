#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+5;
ll minf=-1000000000000000;
int c,t,n,m,k,d,u,v,w;
struct Edge{
	int v;
	ll w;
	bool operator <(const Edge &x) const{
		return v<x.v;
	}
};
vector<Edge> G[maxn];
ll dp[2][maxn];

ll eat(int u,int k){
	ll ans=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i].v;
		if(v<=k){
			 ans+=G[u][i].w*1ll;
		}
	}
	return ans;
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%d%d%lld",&u,&v,&w);
			G[u].push_back((Edge){v,w});
		}
		for(int i=1;i<=k;i++) dp[0][i]=minf;
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			int id=i&1;
			for(int j=0;j<=k;j++) dp[id][j]=minf;
			for(int j=1;j<=k;j++){
				dp[id][j]=max(dp[id^1][j-1]+eat(i,j)-d,dp[id][j]);
			}
			for(int j=0;j<=k;j++){
				dp[id][0]=max(dp[id^1][j],dp[id][0]);
			}
		}
		ll ans=minf;
		for(int i=0;i<=k;i++){
			ans=max(ans,dp[n&1][i]);
		}
		printf("%lld\n",ans);
		for(int i=1;i<=1e5+5;i++){
			G[i].clear();
		}	
	}	
	
	return 0;
}
