#include<bits/stdc++.h>
using namespace std;
const int N = 205;
int c, n, m, q;
int a[N], b[N], a2[N], b2[N];
int dp[N][N];
bool mwz = 0;
int solve(int x, int y) {
	if (x == n + 1 && y == m + 1) return 1;
	if (x == n + 1 || y == m + 1) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = y; i <= m; i++) {
		if (!mwz) {
			if (a[x] < b[i]) dp[x][y] |= solve(x + 1, i + 1);
			else break;
		} else {
			if (a[x] > b[i]) dp[x][y] |= solve(x + 1, i + 1);
			else break;
		}
	}
	for (int i = x; i <= n; i++) {
		if (!mwz) {
			if (a[i] < b[y]) dp[x][y] |= solve(i + 1, y + 1);
			else break;
		} else {
			if (a[i] > b[y]) dp[x][y] |= solve(i + 1, y + 1);
			else break;
		}
	}
	return dp[x][y];
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a2[i]; a[i] = a2[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b2[i]; b[i] = b2[i];
	}
	if (a[1] == b[1]) cout << "0";
	else {
		memset(dp, -1, sizeof dp);
		mwz = (a[1] > b[1]);
		cout << solve(1, 1);	
	}
	while (q--) {
		int k1, k2; cin >> k1 >> k2;
		for (int i = 1; i <= n; i++) a[i] = a2[i];
		for (int i = 1; i <= m; i++) b[i] = b2[i];
		for (int i = 1; i <= k1; i++) {
			int p, x; cin >> p >> x; a[p] = x;
		}
		for (int i = 1; i <= k2; i++) {
			int p, x; cin >> p >> x; b[p] = x;
		}
		if (a[1] == b[1]) cout << "0";
		else {
			memset(dp, -1, sizeof dp);
			mwz = (a[1] > b[1]);
			cout << solve(1, 1);	
		}
	}
	return 0;
}