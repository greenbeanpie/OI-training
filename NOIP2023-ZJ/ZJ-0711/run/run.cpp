#include<bits/stdc++.h>
using namespace std;
int c,T;
long long dp[1010][1010];
struct tar{
	long long x,y,v;
}t[100010];
bool cmp(tar x,tar y){
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
int n,m,k,d;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				dp[i][j]=-1e18;
			}
		}
		dp[0][0]=0;
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&t[i].x,&t[i].y,&t[i].v);
		}
		sort(t+1,t+m+1,cmp);
		int cnt=1;
		for(int i=1;i<=n;i++){
			while(t[cnt].x<i) cnt++;
			for(int j=0;j<=k;j++)
			dp[i][0]=max(dp[i-1][j],dp[i][0]);
			for(int j=1;j<=k;j++){
				dp[i][j]=dp[i-1][j-1]-d;
				int a=cnt;
				while(t[a].x==i&&t[a].y<=j){
					dp[i][j]+=t[a].v;
					a++;
				}
			}
		}
		long long ans=-1e18;
		for(int i=0;i<=k;i++){
			ans=max(ans,dp[n][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

