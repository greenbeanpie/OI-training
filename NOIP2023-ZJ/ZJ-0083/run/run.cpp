#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int M = 1005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int c, T, n, m;

ll ans, k, d, x[N], y[N], l[N], r[N], v[N], dp[M][M];

vector <int> t[N];

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m >> k >> d;
		if (c <= 9) {
			for (int i = 1; i <= n; ++i) {
				t[i].clear();
			}
			for (int i = 1; i <= m; ++i) {
				cin >> x[i] >> y[i] >> v[i];
				t[x[i]].emplace_back(i);
			}
			for (int i = 1; i <= n; ++i) {
				sort(t[i].begin(), t[i].end(), [](int p, int q) {
					return y[p] < y[q];
				});
				ll la = 0;
				for (auto x: t[i]) {
					la += v[x];
					v[x] = la;
				}
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= min(k, (ll)i); ++j) {
					if (j) {
						dp[i][j] = dp[i - 1][j - 1] - d;
						if (t[i].empty()) {
							continue;
						}
						if (j < y[t[i][0]]) {
							continue;
						}
						int l = 0, r = t[i].size() - 1;
						while (l <= r) {
							int mid = (l + r) >> 1;
							if (y[t[i][mid]] <= j) {
								l = mid + 1;
							} else {
								r = mid - 1;
							}
						}
						dp[i][j] += v[t[i][r]];
					} else {
						dp[i][j] = -INF;
						for (int s = 0; s <= k; ++s) {
							dp[i][j] = max(dp[i][j], dp[i - 1][s]);
						}
					}
				}
			}
			ll ans = 0;
			for (int i = 0; i <= k; ++i) {
				ans = max(ans, dp[n][i]);
			}
			cout << ans << endl;
		} else if (c == 17 || c == 18) {
			ll ans = 0;
			for (int i = 1; i <= m; ++i) {
				int x, y;
				cin >> x >> y >> v[i];
				l[i] = x - y + 1, r[i] = x;
				if (r[i] - l[i] + 1 > k) {
					continue;
				}
				ans += max(0ll, v[i] - (r[i] - l[i] + 1) * d);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
