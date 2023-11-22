#include<bits/stdc++.h>
using namespace std;

#define Reimu inline void
#define Marisa inline int

typedef long long LL;
typedef unsigned long long ULL;

typedef pair<int, int> Pii;
#define fi first
#define se second

const int N = 2010;

int n_, m_, n, m, K;
int a_[N], b_[N], a[N], b[N], p1[N], p2[N], x1[N], x2[N];
int dp[N][N];

Marisa prework() {
	if (1LL * (a_[1] - b_[1]) * (a_[n_] - b_[m_]) <= 0) return 1;
	if (a_[1] < b_[1]) memcpy(a + 1, a_ + 1, (n = n_) << 2), memcpy(b + 1, b_ + 1, (m = m_) << 2);
	else memcpy(a + 1, b_ + 1, (n = m_) << 2), memcpy(b + 1, a_ + 1, (m = n_) << 2);
	return 0;
}

Marisa solve() {
	if (prework()) return 0;
	memset(dp, 0, sizeof dp);
	dp[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (dp[i][j]) {
			if (i < n && a[i + 1] < b[j]) dp[i + 1][j] = 1;
			if (j < m && a[i] < b[j + 1]) dp[i][j + 1] = 1;
			if (i < n && j < m && a[i + 1] < b[j + 1]) dp[i + 1][j + 1] = 1;
		}
	}
	return dp[n][m];
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _; cin >> _ >> n_ >> m_ >> K; _ = _ <= 7;
	for (int i = 1; i <= n_; ++i) cin >> a_[i];
	for (int i = 1; i <= m_; ++i) cin >> b_[i];
	cout << solve();
	while (K--) {
		int K1, K2, x; cin >> K1 >> K2;
		for (int i = 1; i <= K1; ++i) cin >> p1[i] >> x1[i], swap(a_[p1[i]], x1[i]);
		for (int i = 1; i <= K2; ++i) cin >> p2[i] >> x2[i], swap(b_[p2[i]], x2[i]);
		cout << solve();
		for (int i = 1; i <= K1; ++i) swap(a_[p1[i]], x1[i]);
		for (int i = 1; i <= K2; ++i) swap(b_[p2[i]], x2[i]);
	}
	cout << '\n';
	return 0;
}

