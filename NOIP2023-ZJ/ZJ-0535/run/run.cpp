#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node{
	int x, y, v;
}a[maxn];
bool vis[maxn];
int c, t, n, m, k, d, ans;
void dfs(int now, int cnt) {
	if (cnt > k) return;
	if (now == n + 1) {
		int res = 0;
		for (int i = 1; i <= m; i++) {
			bool f = 1;
			for (int j = a[i].x - a[i].y + 1; j <= a[i].x; j++) {
				if (!vis[j]) {
					f = 0;
					break;
				}
			}
			if (f) res += a[i].v;
		}
		for (int i = 1; i <= n; i++) if (vis[i]) res -= d;
		if (res == 2) for (int i = 1; i <= n; i++) cout << vis[i] << " ";
		ans = max(ans, res);
		return;
	}
	vis[now] = 1;
	dfs(now + 1, cnt + 1);
	vis[now] = 0;
	dfs(now + 1, 0);
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m >> k >> d;
		for (int i = 1; i <= m; i++) {
			cin >> a[i].x >> a[i].y >> a[i].v;
		}
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}