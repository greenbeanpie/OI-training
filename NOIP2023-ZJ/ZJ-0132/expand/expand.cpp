#include <bits/stdc++.h>
using namespace std;
const int N = 2005;

int type, n, m, q, nn, mm, a[N], b[N], ta[N], tb[N];
bool dp[N][N];

inline void solve() {
	if (a[1] == b[1] || a[n] == b[m] || (a[1] > b[1]) != (a[n] > b[m])) { putchar('0'); return; }
	if (a[1] < b[1]) swap(n, m), swap(a, b);
//	puts("---");
//	for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
//	for (int i = 1; i <= m; ++i) printf("%d ", b[i]); puts("");
//	puts("---");
	memset(dp, 0, sizeof dp), dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int mx = -1;
			for (int k = j; k >= 0; --k) {
				mx = max(mx, b[k]);
				if (mx < a[i]) dp[i][j] |= dp[i - 1][k] | (k ? dp[i - 1][k - 1] : 0);
			}
		}
	putchar(dp[n][m] ? '1' : '0');
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &type, &nn, &mm, &q), n = nn, m = mm;
	for (int i = 1; i <= n; ++i) scanf("%d", &ta[i]);
	for (int i = 1; i <= m; ++i) scanf("%d", &tb[i]);
	memcpy(a, ta, sizeof ta), memcpy(b, tb, sizeof tb);
	solve();
	while (q--) {
		n = nn, m = mm;
		memcpy(a, ta, sizeof ta), memcpy(b, tb, sizeof tb);
		int kx, ky, x, y; scanf("%d%d", &kx, &ky);
		for (int i = 1; i <= kx; ++i) scanf("%d%d", &x, &y), a[x] = y;
		for (int i = 1; i <= ky; ++i) scanf("%d%d", &x, &y), b[x] = y;
		solve();
	}
	return 0;
}
