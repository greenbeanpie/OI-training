#include <bits/stdc++.h>
using namespace std;
long long a[100005], x[100005], y[100005], v[100005], dp[1005][1005];
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	long long i, j, c, t, n, m, k, d, ans;
	scanf("%lld%lld", &c, &t);
	if (c == 17 || c == 18) {
		while (t--) {
			ans = 0;
			scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
			for (i = 1; i <= m; i++) {
				scanf("%lld%lld%lld", &x[i], &y[i], &v[i]);
				ans += max(v[i] - y[i] * d, 0ll);
			}
			printf("%lld\n", ans);
		}
		return 0;
	}
	while (t--) {
		memset(dp, 0, sizeof dp);
		scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
		for (i = 1; i <= m; i++) {
			scanf("%lld%lld%lld", &x[i], &y[i], &v[i]);
			for (j = y[i]; j <= k; j++) {
				dp[x[i]][j] += v[i];
			}
		}
		for (i = 1; i <= n + 1; i++) {
			for (j = 0; j <= k; j++) {
				dp[i][0] = max(dp[i - 1][j], dp[i][0]);
			}
			if (i == n + 1) {
				break;
			}
			for (j = 1; j <= k; j++) {
				dp[i][j] += dp[i - 1][j - 1] - d;
			}
		}
		printf("%lld\n", dp[n + 1][0]);
	}
	return 0;
}
