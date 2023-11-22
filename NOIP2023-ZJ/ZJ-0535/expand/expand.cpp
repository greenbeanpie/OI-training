#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], b[maxn], x[maxn], y[maxn];
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, n, m, q, kx, ky, p, v;
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	if (n == 1) {
		if (a[1] != b[1]) cout << 1;
		else cout << 0;
		while (q--) {
			memcpy(x, a, sizeof a);
			memcpy(y, b, sizeof b);
			cin >> kx >> ky;
			while (kx--) {
				cin >> p >> v;
				x[p] = v;
			}
			while (ky--) {
				cin >> p >> v;
				y[p] = v;
			}
			if (x[1] != y[1]) cout << 1;
			else cout << 0;
		}
	}else {
		if (a[1] > b[1] && a[n] > b[m]) cout << 1;
		else if (a[1] < b[1] && a[n] < b[m]) cout << 1;
		else cout << 0;
		while (q--) {
			memcpy(x, a, sizeof a);
			memcpy(y, b, sizeof b);
			cin >> kx >> ky;
			while (kx--) {
				cin >> p >> v;
				x[p] = v;
			}
			while (ky--) {
				cin >> p >> v;
				y[p] = v;
			}
			if (x[1] > y[1] && x[n] > y[m]) cout << 1;
			else if (x[1] < y[1] && x[n] < y[m]) cout << 1;
			else cout << 0;
		}
	}
	return 0;
}