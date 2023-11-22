#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int M = 5e5 + 5;

int c, n, m, q, a[N], b[N], a0[N], b0[N];
bool dp[N][N];

inline bool solve() {
	if (a[1] == b[1]) {
		return false;
	}
	if (a[n] == b[m]) {
		return false;
	}
	if (a[1] < b[1] && a[n] > b[m]) {
		return false;
	}
	if (a[1] > b[1] && a[n] < b[m]) {
		return false;
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[1] < b[1] && a[i] >= b[j]) {
				dp[i][j] = false;
				continue;
			}
			if (a[1] > b[1] && a[i] <= b[j]) {
				dp[i][j] = false;
				continue;
			}
			dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
		}
	}
	return dp[n][m];
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a0[i];
		a[i] = a0[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b0[i];
		b[i] = b0[i];
	}
	cout << solve();
	while (q--) {
		for (int i = 1; i <= n; ++i) {
			a[i] = a0[i];
		}
		for (int i = 1; i <= m; ++i) {
			b[i] = b0[i];
		}
		int kx, ky;
		cin >> kx >> ky;
		while (kx--) {
			int x, y;
			cin >> x >> y;
			a[x] = y;
		}
		while (ky--) {
			int x, y;
			cin >> x >> y;
			b[x] = y;
		}
		cout << solve();
	}
	return 0;
}
