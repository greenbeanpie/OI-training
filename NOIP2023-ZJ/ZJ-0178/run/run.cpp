#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int x,c,w;
}ts[100005];
int n,m,k;
ll d,dp[1005][1005],dp1[100005][105];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,T; cin >> C >> T;
	while(T--){
		cin >> n >> m >> k >> d;
		for(int i=1;i<=m;++i){
			cin >> ts[i].x >> ts[i].c >> ts[i].w;
			if(ts[i].c>k) --i,--m;
		}
		sort(ts+1,ts+m+1,[](node A,node B){return A.x!=B.x?A.x<B.x:A.c>B.c;});
		ll ans=0;
		if(k<=100){
			memset(dp1,0x80,sizeof(dp1));
			dp1[0][0]=0;
			for(int i=1;i<=m;++i){
				int qwq=ts[i].x-ts[i-1].x;
				for(int j=qwq;j<=k;++j){
					dp1[i][j]=dp1[i-1][j-qwq]-d*qwq;
					if(j>=ts[i].c) dp1[i][j]+=ts[i].w;
					ans=max(ans,dp1[i][j]);
				}
				ll mx=0;
				for(int j=0;j<=k;++j)
					mx=max(dp1[i-1][j],mx);
				for(int j=0;j<qwq&&j<=k;++j){
					dp1[i][j]=mx-d*j;
					if(j>=ts[i].c) dp1[i][j]+=ts[i].w;
					ans=max(ans,dp1[i][j]);
				}
			}
		}else{
			memset(dp,0x80,sizeof(dp));
			dp[0][0]=0;
			for(int i=1;i<=m;++i){
				int qwq=ts[i].x-ts[i-1].x;
				for(int j=qwq;j<=k;++j){
					dp[i][j]=dp[i-1][j-qwq]-d*qwq;
					if(j>=ts[i].c) dp[i][j]+=ts[i].w;
					ans=max(ans,dp[i][j]);
				}
				ll mx=0;
				for(int j=0;j<=k;++j)
					mx=max(dp[i-1][j],mx);
				for(int j=0;j<qwq&&j<=k;++j){
					dp[i][j]=mx-d*j;
					if(j>=ts[i].c) dp[i][j]+=ts[i].w;
					ans=max(ans,dp[i][j]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
