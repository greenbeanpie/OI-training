#include<iostream>
int n, m, par[200050];
int x[200050];
int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
void solve() {
	std::cin >> n >> m;
	for (int i = 0; i < 3; i++) x[i] = i;
	for (int i = 1; i <= n; i++) {
		x[2 * i + 2] = 2 * i + 2;
		x[2 * i + 3] = 2 * i + 3;
	}
	while (m--) {
		char v; std::cin >> v;
		if (v == '+' || v == '-') { 
			int i, j; std::cin >> i >> j;
			if (v == '+') {
				x[2 * i + 2] = x[2 * j + 2];
				x[2 * i + 3] = x[2 * j + 3];
			} else {
				int t1 = x[2 * j + 3], t2 = x[2 * j + 2];
				x[2 * i + 2] = t1;
				x[2 * i + 3] = t2;
			}
		} else {
			int i; std::cin >> i;
			if (v == 'T') {
				x[2 * i + 2] = x[1];
				x[2 * i + 3] = x[0];
			}
			if (v == 'F') {
				x[2 * i + 2] = x[0];
				x[2 * i + 3] = x[1];
			}
			if (v == 'U') {
				x[2 * i + 2] = x[2 * i + 3] = x[2];
			}
		}
	}
	m = 2 * n + 3;
	for (int i = 0; i <= m; i++) par[i] = i;
	for (int i = 0; i <= m; i++) {
		if (i == 3) continue;
		par[find(i)] = find(x[i]);
//		std::cerr << i << " " << x[i] << std::endl;
	}
	int ans = 0;
	for (int i = 4; i <= m; i += 2) {
		if (find(i) == find(i ^ 1)) ans++;
	}
	std::cout << ans << '\n';
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int c, t; std::cin >> c >> t;
	while (t--) solve();
}
