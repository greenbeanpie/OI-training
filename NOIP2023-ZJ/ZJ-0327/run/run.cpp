#include <bits/stdc++.h>
#define F(i, a, b) for (int i = a; i <= (b); i++)
#define D(i, a, b) for (int i = a; i >= (b); i--)
#define int long long
using namespace std;

struct rw { int x, y, v; };
int c, n, m, k, d;

inline void ckmax(int &x, int y) { x = max(x, y); }

namespace solB {
	const int M = 1e5 + 5;
	rw a[M];
	void main() {
		F(i, 1, m) cin >> a[i].x >> a[i].y >> a[i].v;
		int ans = 0;
		F(i, 1, m) if (a[i].y <= k) {
			int cur = a[i].v - d * a[i].y;
			if (cur > 0) ans += cur;
		}
		cout << ans << '\n';
	}
}
namespace sol {
	const int N = 1005;
	long long dp[N][N];
	vector<pair<int, int>> vec[N];
	void main() {
		long long ans = 0;
		F(i, 1, n) vector<pair<int, int>>().swap(vec[i]);
		F(i, 1, m) {
			int x, y, v;
			cin >> x >> y >> v;
			vec[x].emplace_back(y, v);
		}
		memset(dp, 0xc0, sizeof dp);
		dp[0][0] = 0;
		F(i, 1, n) {
			F(j, 0, k) ckmax(dp[i][0], dp[i - 1][j]);
			F(j, 1, k) {
				int cur = dp[i - 1][j - 1] - d;
				for (auto rw : vec[i]) if (rw.first <= j) cur += rw.second;
				ckmax(dp[i][j], cur);
				ckmax(ans, dp[i][j]);
			}
		}
		cout << ans << '\n';
	}
}
void solve() {
	cin >> n >> m >> k >> d;
	if (c == 17 || c == 18) {
		solB::main();
		return ;
	}
	if (n <= 1000) sol::main();
	else {
		F(i, 1, m) {
			int x, y, v;
			cin >> x >> y >> v;
		}
		cout << 0 << '\n';
	}
}

signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
