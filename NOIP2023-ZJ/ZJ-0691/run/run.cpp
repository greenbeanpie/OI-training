#include <bits/stdc++.h>
using namespace std;

long long c, t, n, m, k, d;


int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	for (int i = 0; i < t; ++ i) {
		cin >> n >> m >> k >> d;
		long long ans = 0;
		for (int j = 0; j < m; ++j) {
			int x, y, v;
			cin >> x >> y >> v;
			if (y <= k) {
				ans += v - y * d;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
