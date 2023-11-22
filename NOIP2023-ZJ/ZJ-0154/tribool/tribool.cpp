#include <bits/stdc++.h>
using namespace std;
int cnt, a[100005], vis[100005];
char b[100005];
char dfs(int now, int tot) {
	if (b[now] != '$') {
		return b[now];
	}
	if (vis[now] != -1) {
		if ((tot - vis[now]) & 1) {
			return b[now] = 'U';
		} else {
			return b[now] = 'T';
		}
	}
	vis[now] = tot;
	if (a[now] < 0) {
		if (a[-a[now]] != 0 && vis[-a[now]] == -1) {
			vis[-a[now]] = tot + 1;
			if (a[-a[now]] < 0) {
				b[-a[now]] = dfs(-a[-a[now]], tot + 2);
				if (b[-a[now]] != 'U') {
					b[-a[now]] = 'T' - b[-a[now]] + 'F';
				}
			} else {
				b[-a[now]] = dfs(a[-a[now]], tot + 1);
			}
			b[now] = b[-a[now]];
			if (b[now] != 'U') {
				b[now] = 'T' - b[now] + 'F';
			}
			return b[now];
		}
		b[now] = dfs(-a[now], tot + 1);
		if (b[now] != 'U') {
			b[now] = 'T' - b[now] + 'F';
		}
		return b[now];
	} else if (a[now] > 0) {
		if (a[a[now]] != 0 && vis[a[now]] == -1) {
			vis[a[now]] = tot;
			if (a[a[now]] < 0) {
				b[a[now]] = dfs(-a[a[now]], tot + 1);
				if (b[a[now]] != 'U') {
					b[a[now]] = 'T' - b[a[now]] + 'F';
				}
			} else {
				b[a[now]] = dfs(a[a[now]], tot);
			}
			b[now] = b[a[now]];
			return b[now];
		}
		b[now] = dfs(a[now], tot);
		return b[now];
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int i, j, n, m, k, p, t, ans;
	char opt;
	scanf("%d%d", &p, &t);
	while (t--) {
		memset(vis, -1, sizeof vis);
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			a[i] = i;
			b[i] = '$';
		}
		for (k = 1; k <= m; k++) {
			cin >> opt;
			scanf("%d", &i);
			if (opt == 'T' || opt == 'F' || opt == 'U') {
				a[i] = 0;
				b[i] = opt;
			} else if (opt == '+') {
				scanf("%d", &j);
				a[i] = a[j];
				if (a[i] == 0) {
					b[i] = b[j];
				} else {
					b[i] = '$';
				}
			} else {
				scanf("%d", &j);
				a[i] = -a[j];
				if (a[i] == 0) {
					if (b[j] != 'U') {
						b[i] = 'T' - b[j] + 'F';
					} else {
						b[i] = 'U';
					}
				} else {
					b[i] = '$';
				}
			}
		}
		for (i = 1; i <= n; i++) {
			if (a[i] == -i) {
				a[i] = 0;
				b[i] = 'U';
			}
			if (a[i] == i) {
				a[i] = 0;
				b[i] = 'T';
			}
		}
		for (i = 1; i <= n; i++) {
			if (b[i] == '$') {
				b[i] = dfs(i, 0);
			}
		}
		ans = 0;
		for (i = 1; i <= n; i++) {
			if (b[i] == 'U') {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
