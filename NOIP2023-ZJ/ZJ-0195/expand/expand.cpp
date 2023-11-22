// Think twice, code once.
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int type, n, m, q;
int a[500005], b[500005];

namespace BruteForce {
	int dp[2005][2005];

	int query() {
		if (a[1] == b[1]) return 0;
		memset(dp, 0, sizeof(dp));
		int swaped = 0;
		if (a[1] < b[1]) {
			for (int i = 1; i <= max(n, m); i++) swap(a[i], b[i]);
			swap(n, m);
			swaped = 1;
		}
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if ((i != 1 || j != 1) && a[i] > b[j]) {
					if (j > 1) dp[i][j] |= dp[i][j - 1];
					if (i > 1) dp[i][j] |= dp[i - 1][j];
					if (i > 1 && j > 1) dp[i][j] |= dp[i - 1][j - 1];
				}
		int ans = dp[n][m];
		if (swaped) {
			for (int i = 1; i <= max(n, m); i++) swap(a[i], b[i]);
			swap(n, m);
		}
		return ans;
	}

	void main() {
		cout << query();
		while (q--) {
			int kx, ky;
			cin >> kx >> ky;
			vector<pair<int, int>> vx, vy;
			for (int i = 1; i <= kx; i++) {
				int p, x;
				cin >> p >> x;
				vx.emplace_back(p, a[p]);
				a[p] = x;
			}
			for (int i = 1; i <= ky; i++) {
				int p, x;
				cin >> p >> x;
				vy.emplace_back(p, b[p]);
				b[p] = x;
			}
			cout << query();
			for (auto i : vx) a[i.first] = i.second;
			for (auto i : vy) b[i.first] = i.second;
		}
		cout << '\n';
		return ;
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> type >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	if (type <= 7) BruteForce::main();
	return 0;
}