#include <bits/stdc++.h>
using namespace std;

int c, n, m, q;

namespace solve1 {
	int X, Y;
	void main() {
		cin >> X >> Y;
		cout << (X == Y ? 0 : 1);
		while (q--) {
			int _x = X, _y = Y, kx, ky;
			cin >> kx >> ky;
			while (kx--) { cin >> _x; cin >> _x; }
			while (ky--) { cin >> _y; cin >> _y; }
			cout << (_x == _y ? 0 : 1);
		}
	}
}
namespace solve2 {
	int X[5], Y[5];
	int check(int* x, int* y) {
		if (n == 1) x[2] = x[1];
		if (m == 1) y[2] = y[1];
		return ((x[1] > y[1] && x[2] > y[2]) || (x[1] < y[1] && x[2] < y[2])) ? 1 : 0;
	}
	void main() {
		for (int i = 1; i <= n; i++) cin >> X[i];
		for (int i = 1; i <= m; i++) cin >> Y[i];
		cout << check(X, Y);
		while (q--) {
			int _x[5], _y[5], kx, ky;
			for (int i = 1; i <= n; i++) _x[i] = X[i];
			for (int i = 1; i <= n; i++) _y[i] = Y[i];
			cin >> kx >> ky;
			while (kx--) {
				int p, v; cin >> p >> v; _x[p] = v;
			}
			while (ky--) {
				int p, v; cin >> p >> v; _y[p] = v;
			}
			cout << check(_x, _y);
		}
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> q;
	if (c == 1) solve1::main();
	else solve2::main();
	return 0;
}
