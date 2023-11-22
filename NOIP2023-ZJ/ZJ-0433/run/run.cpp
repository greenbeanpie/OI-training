#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
typedef long long ll;
struct node {
	ll req, reward;
};
vector<node> G[maxn];
ll ans, n, m, k, d, dp[maxn][maxn], c, t;
void dfs(ll now_day, ll combo_day, ll power) {
	if (now_day == n + 1) {
		ans = max(ans, power);
		return;
	}
	ll run_reward = -d;
	for (auto i : G[now_day]) {
		if (combo_day >= i.req) {
			run_reward += i.reward;
		}
	}
	if (combo_day < k)dfs(now_day + 1, combo_day + 1, power + run_reward);
	dfs(now_day + 1, 0, power + run_reward + d);
}
ll check(ll day, ll combo_day) {
	ll sum = -d;
	for (auto i : G[day]) {
		if (combo_day >= i.req) {
			sum += i.reward;
		}
	}
//	cout << "GenShin Start!" << sum << endl;
	return sum;
}
void solve() {
	cin >> n >> m >> k >> d;
	if (c == 1 || c == 2) {
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		ans = 0;
		for (int i = 1; i <= m; i++) {
			ll u, v, w;
			cin >> u >> v >> w;
			G[u].push_back({v, w});
		}
		dfs(0, 0, 0);
		cout << ans << endl;
	} else if (c == 17 || c == 18) {
		ll anss = 0;
		for (int i = 1; i <= m; i++) {
			ll x, y, z;
			cin >> x >> y >> z;
			if (y * d < z) anss += z - y * d;
		}
		cout << anss << endl;
	} else {
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) dp[i][j] = 0;
		}
		ans = 0;
		for (int i = 1; i <= m; i++) {
			ll u, v, w;
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			//cout << G[u][G[u].size() - 1].req << " " << G[u][G[u].size() - 1].reward << endl;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) dp[i][0] = max(dp[i - 1][j], dp[i][0]);
			for (int j = 1; j <= i && j <= k; j++) {
				dp[i][j] = dp[i - 1][j - 1] + check(i, j);
			}
		}
		ll ans = 0;
		for (ll i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
		cout << ans << endl;
	}
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}