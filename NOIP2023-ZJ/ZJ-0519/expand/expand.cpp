#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int x[N], y[N], xx[N], yy[N], tc, n, m, q, f[N][N];
inline int cmp(int x, int y) {
	if (x == y)
		return 0;
	return x < y ? -1 : 1;
}
inline void solve(int *x, int *y) {
	memset(f, 0, sizeof f);
	f[1][1] = true;
	int fr = cmp(x[1], y[1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] |= (f[i - 1][j] && (cmp(x[i], y[j]) == fr)) 
			|| (f[i][j - 1] && (cmp(x[i], y[j]) == fr));
		}
	}
	cout << (x[1] == y[1] ? 0 : f[n][m]);
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> tc >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= m; i++)
		cin >> y[i];
	solve(x, y);
	while (q--) {
		int kx, ky, p, v;
		cin >> kx >> ky;
		for (int i = 1; i <= n; i++)
			xx[i] = x[i];
		for (int i = 1; i <= m; i++)
			yy[i] = y[i];
		while (kx--) {
			cin >> p >> v;
			xx[p] = v;
		}
		while (ky--) {
			cin >> p >> v;
			yy[p] = v;
		}
		solve(xx, yy);
	}
	return 0;
}