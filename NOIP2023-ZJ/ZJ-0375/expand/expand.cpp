#include <bits/stdc++.h>
using namespace std; const int N = 5e5 + 5, M = 65;
int c, n, m, q, a[N], b[N], e[N], f[N];
struct modifies { 
	int x, y; modifies(int x_ = 0, int y_ = 0) { x = x_; y = y_; }
};
struct queries {
	int kx, ky; vector<modifies> g;
	queries(int kx_ = 0, int ky_ = 0) { kx = kx_; ky = ky_; }
} qr[M];
int main() {
	freopen("expand.in", "r", stdin); freopen("expand.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
	for (int i = 1; i <= q; ++i) {
		cin >> qr[i].kx >> qr[i].ky;
		for (int j = 1, x, v; j <= qr[i].kx + qr[i].ky; ++j) 
			cin >> x >> v, qr[i].g.emplace_back(x, v);
	}
	if (c == 1) {
		cout << bool(a[1] != b[1]);
		for (int i = 1; i <= q; ++i) {
			for (int j = 1; j <= n; ++j) e[j] = a[j], f[j] = b[j];
			for (int j = 0; j < qr[i].g.size(); ++j) {
				if (j < qr[i].kx) e[qr[i].g[j].x] = qr[i].g[j].y;
				else f[qr[i].g[j].x] = qr[i].g[j].y;
			}
			cout << bool(e[1] != f[1]);
		}
	}
}