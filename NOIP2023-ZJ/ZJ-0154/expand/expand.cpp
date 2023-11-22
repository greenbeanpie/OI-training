#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005], x[500005], y[500005];
int n, m, dp[2005][2005];
int dfsd(int li, int lj) {
	if (li == n && lj == m) {
		return 1;
	}
	if (dp[li][lj] != -1) {
		return dp[li][lj];
	}
	int p = 0;
	if (li < n && lj < m && a[li + 1] > b[lj + 1]) {
		p = dfsd(li + 1, lj + 1);
	}
	if (p) {
		return dp[li][lj] = p;
	}
	if (li < n && a[li + 1] > b[lj]) {
		p = dfsd(li + 1, lj);
	}
	if (p) {
		return dp[li][lj] = p;
	}
	if (lj < m && a[li] > b[lj + 1]) {
		p = dfsd(li, lj + 1);
	}
	return dp[li][lj] = p;
}
int dfsx(int li, int lj) {
	if (li == n && lj == m) {
		return 1;
	}
	if (~dp[li][lj]) {
		return dp[li][lj];
	}
	int p = 0;
	if (li < n && lj < m && a[li + 1] < b[lj + 1]) {
		p = dfsx(li + 1, lj + 1);
	}
	if (p) {
		return dp[li][lj] = p;
	}
	if (li < n && a[li + 1] < b[lj]) {
		p = dfsx(li + 1, lj);
	}
	if (p) {
		return dp[li][lj] = p;
	}
	if (lj < m && a[li] < b[lj + 1]) {
		p = dfsx(li, lj + 1);
	}
	return dp[li][lj] = p;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int i, j, c, q, kx, ky, dx, dy;
	string ans = "";
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		a[i] = x[i];
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &y[i]);
		b[i] = y[i];
	}
	if (a[1] == b[1] || a[n] == b[m]) {
		ans += "0";
	} else {
		if (a[1] > b[1]) {
			if (a[n] < b[m]) {
				ans += "0";
			} else {
				memset(dp, -1, sizeof dp);
				ans += (char)('0' + dfsd(1, 1));
			}
		} else {
			if (a[n] > b[m]) {
				ans += "0";
			} else {
				memset(dp, -1, sizeof dp);
				ans += (char)('0' + dfsx(1, 1));
			}
		}
	}
	while (q--) {
		for (i = 1; i <= n; i++) {
			a[i] = x[i];
		}
		for (i = 1; i <= m; i++) {
			b[i] = y[i];
		}
		scanf("%d%d", &kx, &ky);
		for (i = 1; i <= kx; i++) {
			scanf("%d%d", &dx, &dy);
			a[dx] = dy;
		}
		for (i = 1; i <= ky; i++) {
			scanf("%d%d", &dx, &dy);
			b[dx] = dy;
		}
		if (a[1] == b[1] || a[n] == b[m]) {
			ans += "0";
			continue;
		}
		dp[1][1] = 1;
		if (a[1] > b[1]) {
			if (a[n] < b[m]) {
				ans += "0";
				continue;
			}
			memset(dp, -1, sizeof dp);
			ans += (char)('0' + dfsd(1, 1));
		} else {
			if (a[n] > b[m]) {
				ans += "0";
				continue;
			}
			memset(dp, -1, sizeof dp);
			ans += (char)('0' + dfsx(1, 1));
		}
	}
	cout << ans << endl;
	return 0;
}
