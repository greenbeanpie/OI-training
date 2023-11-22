#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1005;
int c,t,n,m,k,d,dp[N][N];
struct node{
	int y,v;
};
vector <node> meal[N];
bool cmp(node p,node q){
	return p.y < q.y;
}
int read(){
	int res = 0;
	char c; c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9'){
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c < 15){
	while(t --){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			int a,b,val; scanf("%lld%lld%lld",&a,&b,&val);
			meal[a].push_back((node){b,val});
		}
		for(int i=1;i<=n;i++)
		    if(meal[i].size()) sort(meal[i].begin(),meal[i].end(),cmp);
		for(int i=1;i<=n;i++){
			dp[i][0] = 0;
			for(int j=0;j<=k;j++) dp[i][0] = max(dp[i][0],dp[i-1][j]);
			//cout<<dp[i][0]<<" "<<i<<" "<<0<<endl;
			int res = 0,pos = 0;
			for(int j=1;j<=min(i,k);j++){
				while(pos < meal[i].size() && meal[i][pos].y <= j){
					res += meal[i][pos].v;
					++ pos;
				}
				dp[i][j] = dp[i-1][j-1] + res - d;
				//cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
			}
		}
		int ans = 0;
		for(int i=0;i<=k;i++) ans = max(ans,dp[n][i]);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) meal[i].clear();
	}	
	}
	else{
		while(t --){
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			int ans = 0;
			for(int i=1;i<=m;i++){
				int a = read(),b = read(),val = read();
				if(b <= k){
					if(val > b * d) ans += val - b * d;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
