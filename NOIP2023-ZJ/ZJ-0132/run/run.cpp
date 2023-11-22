#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1005;

int n, m, k, d;
LL dp[N][N], sum[N][N];
struct node {
	int x, l, v;
	bool operator < (const node &O) const {
		return x == O.x ? l > O.l : x < O.x;
	}
} a[N];

inline void solve() {
	memset(dp, 0xc0, sizeof dp), memset(sum, 0, sizeof sum);
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i].x, &a[i].l, &a[i].v), sum[a[i].x][a[i].l] += a[i].v, a[i].l = a[i].x - a[i].l + 1;
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j) sum[i][j] += sum[i][j - 1];
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= min(i, k); ++j)
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - d + sum[i][j]);
		for (int j = 0; j <= k; ++j) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
	}
//	for (int i = 1; i <= n; ++i, puts("")) for (int j = 0; j <= n; ++j) printf("%lld ", dp[i][j]);
	LL ans = 0;
	for (int i = 0; i <= k; ++i) ans = max(ans, dp[n][i]);
	printf("%lld\n", ans);
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int type, T; for (scanf("%d%d", &type, &T); T--; solve());
	return 0;
}
