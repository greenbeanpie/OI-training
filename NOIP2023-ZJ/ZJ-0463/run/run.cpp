#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e3 + 5;
const int M = 1e3 + 5;

int c, t;
int n, m, k, d;
LL dp[N][M], w[N][M];

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d", &c, &t);
	while (t --){
		memset(w, 0, sizeof w);
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i = 1;i <= m; ++ i){
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			w[x][y] += v;
		}
		
		for (int i = 1;i <= n; ++ i)
			for (int j = 1;j <= k; ++ j)
				w[i][j] += w[i][j - 1];
		
		memset(dp, 0, sizeof dp);
		for (int i = 1;i <= n; ++ i){
			for (int j = 0;j < k && j < i; ++ j){
				dp[i][0] = max(dp[i - 1][j], dp[i][0]);
				dp[i][j + 1] = dp[i - 1][j] - d + w[i][j + 1];
			}dp[i][0] = max(dp[i][0], dp[i - 1][k]);
		}LL ans = 0;
		for (int i = 0;i <= k; ++ i)
			ans = max(ans, dp[n][i]);
		printf("%lld\n", ans);
	}
	return 0;
}