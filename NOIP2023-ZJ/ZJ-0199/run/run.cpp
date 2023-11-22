#include<bits/stdc++.h>
using namespace std;
int n,m,k,d;
int x[100005],y[100005],v[100005];
map<int,set<int> > daychallenge;
long long dp[1005][1005],dmax[1005];
long long ans = 0;
int main(){ 
	#ifndef LOCAL
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> m >> k >> d;
		for(int i = 1;i <= n;i++) daychallenge[i].clear();
		for(int i = 1;i <= m;i++){
			cin >> x[i] >> y[i] >> v[i];
			daychallenge[x[i]].insert(i);
		}
		if(c<=9){
			dp[0][0] = 0;
			memset(dmax,0,sizeof(dmax));
			for(int i = 1;i <= n;i++){
				for(int j = 0;j <= min(i,k);j++){
					//dp[i][j] biaoshi di i tian yihou qiahao lianxu j tian daka de zuida nengliangzhi
					if(j>=1) dp[i][j] = dp[i-1][j-1]-d;
					else dp[i][j] = dmax[i-1];
					for(int id:daychallenge[i]){
						if(j>=y[id]) dp[i][j] += v[id];
					}
					//if(daychallenge[i]>=1&&j>=y[daychallenge[i]]) dp[i][j] += v[daychallenge[i]];
					
					ans = max(ans,dp[i][j]);
					dmax[i] = max(dmax[i],dp[i][j]);
				}
			}
		}
		cout << ans << endl;
	}
}