#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e9 + 10;
int c, T;
int n, m, k, d;
struct node {
	int x, y, z;
} a[N];
int ans;
bool fl[M];
bool check(int l, int r) {
	for (int i = l - r + 1; i <= l; ++i) {
		if (fl[i] == 0) {
			return 0;
		}
	}
	return 1;
}
int HTJ() {
	int res = 0, ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (fl[i] == 1) {
			ret++;
			res -= d;
		} else {
			if (ret > k) {
				return 0;
			}
			ret = 0;
		}
	}
	if (ret > k) {
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		if (check(a[i].x, a[i].y)) {
			res += a[i].z;
		}
	}
	return res;
}
void dfs(int day) {
	if (day == n + 1) {
		ans = max(ans, HTJ());
		return;
	}
	fl[day] = 1;
	dfs(day + 1);
	fl[day] = 0;
	dfs(day + 1);
}
void work() {
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	ans = 0;
	dfs(1);
	cout << ans;
}
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0);
	cin >> c >> T;
	while (T--) {
		work();
	}
	return 0;
}


// grade : 8?
