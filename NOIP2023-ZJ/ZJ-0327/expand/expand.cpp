#include <bits/stdc++.h>
#define F(i, a, b) for (int i = a; i <= (b); i++)
#define D(i, a, b) for (int i = a; i >= (b); i--)
using namespace std;

const int N = 5e5 + 5;
int c, n, m, q, x[N], y[N];

namespace sol1 {
	void main() {
		cout << (x[1] > y[1]);
		F(i, 1, q) {
			int kx, ky;
			cin >> kx >> ky;
			while (kx--) {
				int px, vx;
				cin >> px >> vx;
				x[px] = vx;
			}
			while (ky--) {
				int py, vy;
				cin >> py >> vy;
				y[py] = vy;
			}
			cout << (x[1] > y[1]);
		}
	}
}

signed main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> q;
	F(i, 1, n) cin >> x[i];
	F(i, 1, m) cin >> y[i];
	sol1::main();
	return 0;
}
