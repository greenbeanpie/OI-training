#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --) {
		int n, m, k, d;
		cin >> n >> m >> k >> d;
		int ans = 0;
		for(int i = 1, x, y, v; i <= m; ++i) {
			cin >> x >> y >> v;
			ans += max(v - y * d, 0);
		}
		cout << ans << endl;
	}
	return 0;
}