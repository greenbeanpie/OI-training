/*
Time complexity: O(nq)
Estimated score: 0

hui mie ba.

written at 11:33.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

#define int long long

int c, n, m, q, x[N], y[N], xt[N], yt[N];

signed main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; ++ i) cin >> x[i], xt[i] = x[i];
	for(int i = 1; i <= m; ++ i) cin >> y[i], yt[i] = y[i];
	if((x[1] - y[1]) * (x[n] - y[m]) > 0) cout << 1;
	else cout << 0;
	while(q --> 0) {
		for(int i = 1; i <= n; ++ i) x[i] = xt[i];
		for(int i = 1; i <= m; ++ i) y[i] = yt[i];
		int kx, ky; cin >> kx >> ky;
		while(kx --> 0) {
			int p, v; cin >> p >> v;
			x[p] = v;
		}
		while(ky --> 0) {
			int p, v; cin >> p >> v;
			y[p] = v;
		}
		if((x[1] - y[1]) * (x[n] - y[m]) > 0) cout << 1;
		else cout << 0;
	}
	return 0;
}