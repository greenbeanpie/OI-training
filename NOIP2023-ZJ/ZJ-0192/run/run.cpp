#include <bits/stdc++.h>
#define file(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout); 
#define int long long
using namespace std;
const int N = 100000 + 5, M = 1000 + 5;
struct node{
	int l, r, val;
}a[N];
int n, m, d, k;
namespace sub1{
	int dp[M][M];
	bool cmp(node x, node y){
		return x.r < y.r;
	}
	void solve(){
		sort(a + 1, a + m + 1, cmp);
		memset(dp, 0x80, sizeof(dp));
		int j = 1;
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int t = 0; t <= k; t++){
				dp[i][0] = max(dp[i][0], dp[i - 1][t]);
				if(t == 0) continue;
				dp[i][t] = max(dp[i][t], dp[i - 1][t - 1] - d);
			}
			while(a[j].r == i && j <= m){
				int x = a[j].r - a[j].l + 1;
				for (int t = a[j].r; t >= a[j].l - 1; t--){
					int tmp = a[j].r - t;
					for (int p = x - tmp; p <= k - tmp; p++) {
						dp[i][p + tmp] = max(dp[i][p + tmp], dp[t][p] - tmp * d + a[j].val);
					}
				}
				j++;
			}
		}
		int ans = dp[n][0];
		for (int i = 1; i <= k; i++) ans = max(ans, dp[n][i]); 
		printf("%lld\n", ans);
	}
}
namespace sub2{
	void solve(){
		int ans = 0;
		for (int i = 1; i <= m; i++){
			if(a[i].r - a[i].l + 1 <= k)
				ans += max(0ll, a[i].val - (a[i].r - a[i].l + 1) * d);
		}
		printf("%lld\n", ans);
	}
}
signed main(){
	file("run");
	int id, T;
	scanf("%lld%lld", &id, &T);
	while(T--){
		scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
		for (int i = 1; i <= m; i++) {
			scanf("%lld%lld%lld", &a[i].r, &a[i].l, &a[i].val);
			a[i].l = a[i].r - a[i].l + 1;
		}
		if(id <= 7)sub1::solve();
		else sub2::solve();
	}
	return 0;
}