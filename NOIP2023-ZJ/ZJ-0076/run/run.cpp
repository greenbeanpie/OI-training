#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
ll f[N][N], a[N][N];

inline ll rd() {
	char c; ll x = 0;
	do c = getchar(); while (!isdigit(c));
	do x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); while (isdigit(c));
	return x;
}
int n, m, k;
ll d;

void Solve() {
	n = rd(), m = rd(), k = rd(), d = rd();
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			f[i][j] = -1e16, a[i][j] = 0;
	f[0][0] = 0;
	int x, y, v;
	for (int i = 0; i < m; ++i) {
		x = rd(), y = rd(), v = rd();
		a[x][y] += v;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			a[i][j] += a[i][j - 1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j)
			f[i][0] = max(f[i][0], f[i - 1][j]);
		for (int j = 1; j <= k; ++j)
			f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i][j] - d);
	}
	ll ans = -1e16;
	for (int j = 0; j <= k; ++j)
		ans = max(ans, f[n][j]);
	printf("%lld\n", ans);
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, T;
	c = rd(), T = rd();
	while (T--) Solve();
	return 0;
}