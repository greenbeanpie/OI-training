#include <bits/stdc++.h>

constexpr int N = 20'0005;

int n, m, f[N], v[N];

int find(int x) { return (x == f[x]) ? x : f[x] = find(f[x]); }
void merge(int x, int y) { 
	x = find(x), y = find(y);
	if (x != y) f[x] = y;
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n + n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) v[i] = i;
	int T = n + 1, F = n + 2, U = n + 3;
	for (int t = 1; t <= m ; t++) {
		std::string opt;
		int i, j;
		std::cin >> opt;
		if (opt == "T") std::cin >> i, v[i] = T;
		else if (opt == "F") std::cin >> i, v[i] = F;
		else if (opt == "U") std::cin >> i, v[i] = U;
		else if (opt == "+") std::cin >> i >> j, v[i] = v[j];
		else if (opt == "-") std::cin >> i >> j, v[i] = -v[j];
	}
	for (int i = 1; i <= n; i++)
		if (v[i] >= -n && v[i] <= n) {
			int j = std::abs(v[i]);
			if (v[i] < 0) merge(i, j + n), merge(i + n, j);
			else merge(i, j), merge(i + n, j + n);
		}
		else if (v[i] == U || v[i] == -U) 
			merge(i, i + n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += find(i) == find(i + n);
	std::cout << ans << '\n';
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int t, T;
	std::cin >> t >> T;
	while (T--) solve();
}