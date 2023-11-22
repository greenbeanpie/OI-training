#include <bits/stdc++.h>

constexpr int N = 1005;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m, k;
long long d, f[N][N];
std::vector<std::pair<int, int>> e[N];

void solve() {
	std::cin >> n >> m >> k >> d;
	for (int i = 1; i <= n; i++) { 
		f[0][i] = -INF;
		for (int j = 1; j <= n; j++) f[i][j] = -INF;
	}
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1, x, y, z; i <= m; i++) {
		std::cin >> x >> y >> z;
		e[x].emplace_back(y, z);
	}
	for (int i = 1; i <= n; i++) std::sort(e[i].begin(), e[i].end());
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i - 1][0];
		for (int j = 1; j < i && j <= k; j++)
			f[i][0] = std::max(f[i][0], f[i - 1][j]);
		long long cd = 0;
		int p = 0;
		for (int j = 1; j <= n && j <= k; j++) {
			while (p < (int)e[i].size() && e[i][p].first == j) 
				cd += e[i][p].second, p++;
			f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + cd - d);
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n && i <= k; i++) 
		ans = std::max(ans, f[n][i]);
	std::cout << ans << '\n';
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int T, c;
	std::cin >> c >> T;
	while (T--) solve();
}