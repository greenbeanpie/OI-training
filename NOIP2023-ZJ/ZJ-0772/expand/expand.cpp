#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, q, x[N], y[N];
int p1[N], p2[N], t1[N], t2[N];
int work() {
	if (x[1] == y[1]) {
		return 0;
	}
	int l = 1, r = 1;
	bool f1 = 1, f2 = 1;
	while ((l != n || r != m) && f1) {
		if (x[n] <= y[m]) {
			f1 = 0;
			break;
		}
		if (x[l] > y[r]) {
			if (l != n) {
				l++;
			}
			if (r != m) {
				r++;
			}
		} else {
			if (x[l] <= y[r]) {
				while (x[l] <= y[r] && l > 1) {
					l--;
				}
				if (l == 1) {
					if (x[1] <= y[r]) {
						f1 = 0;
						break;
					}
				}
			}
		}
	}
	while ((l != n || r != m) && f2) {
		if (x[n] >= y[m]) {
			f2 = 0;
			break;
		}
		if (x[l] < y[r]) {
			if (l != n) {
				l++;
			}
			if (r != m) {
				r++;
			}
		} else {
			if (x[l] >= y[r]) {
				while (x[l] >= y[r] && r > 1) {
					r--;
				}
				if (r == 1) {
					if (x[l] >= y[1]) {
						f2 = 0;
						break;
					}
				}
			}
		}
	}
	if (f1 == 0 && f2 == 0) {
		return 0;
	} else {
		return 1;
	}
}
signed main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> y[i];
	}
	cout << work();
	while (q--) {
		int kx, ky, v;
		cin >> kx >> ky;
		for (int i = 1; i <= kx; ++i) {
			cin >> p1[i] >> v;
			t1[p1[i]] = x[p1[i]];
			x[p1[i]] = v;
		}
		for (int i = 1; i <= ky; ++i) {
			cin >> p2[i] >> v;
			t2[p2[i]] = y[p2[i]];
			y[p2[i]] = v;
		}
		cout << work();
		for (int i = 1; i <= kx; ++i) {
			x[p1[i]] = t1[p1[i]];
		}
		for (int i = 1; i <= ky; ++i) {
			y[p2[i]] = t2[p2[i]];
		}
	}
	return 0;
}


// grade : 10?
