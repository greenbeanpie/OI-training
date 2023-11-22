#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node{
	int x, y, v;
}clg[100010];

int n, m, k, d, dp[100010][1010];
void close_flow(){
	ios :: sync_with_stdio (false);
	cin.tie(0);
	cout.tie(0);
	return;
}
signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	close_flow();
	int c, t;
	cin >> c >> t;
	while(t--){
//		cin >> n >> m >> k >> d;
//		for(int i = 1; i <= m; ++i){
//			cin >> clg[i].x >> clg[i].y >> clg[i].v;
//		}
//		for(int i = 1; i <= n; ++i){
//			for(int j = 0; j <= k; ++j){
//				if(j == 0){
//					for(int l = 0; l <= k; ++l){
//						dp[i][j] = max(dp[i][j], dp[i-1][l]);
//					}
//					continue;
//				}
//				int reward = 0;
//				for(int l = 1; l <= m; ++l){
//					if(clg[l].x == i && clg[l].y <= j)
//						reward += clg[l].v;
//				}
//				dp[i][j] = max(dp[i][j], dp[i-1][j-1] - d + reward);
//			}
//		}
////		for(int i = 1; i <= n; ++i){
////			for(int j = 1; j <= k; ++j){
////				cout << dp[i][j] << " ";
////			}
////			cout << endl;
////		}
//		int ans = 0;
//		for(int i = 0; i <= k; ++i){
//			ans = max(ans, dp[n][i]);
//		}
		cout << ans << endl;
	}
	
	return 0;
} 