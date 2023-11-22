#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, k, d, c, t;
int f[1005][1005];
struct node {
	int x, y, v;
}event[N];
inline bool cmp1(node a, node b) {
	return a.v - d * a.y > b.v - d * b.y;
}
inline bool cmp2(node a, node b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int read() {
	int x = 0, fl = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')
			fl = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * fl;
}
void solve() {
	n = read(), m = read(), k = read(), d = read();
	for (int i = 1; i <= m; ++i) {
		event[i].x = read(), event[i].y = read(), event[i].v = read();
	}
	if (c == 17 || c == 18) {
		sort(event + 1, event + m + 1, cmp1);
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			if (event[i].y <= k) {
				ans += max(0ll, event[i].v - d * event[i].y);
			}
		}
		printf("%lld\n", ans);
		return;
	}
	memset(f, 0, sizeof(f));
	sort(event + 1, event + m + 1, cmp2);
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			f[i][0] = max(f[i][0], f[i - 1][j]);
		}
		for (int j = 1; j <= k; ++j) {
			f[i][j] = f[i - 1][j - 1] - d;
			//while (event[p].x == i && event[p].y != j) p++;
			for (int p = 1; p <= m; ++p)
			if (event[p].x == i && event[p].y <= j)
				f[i][j] += event[p].v;
			// printf("%d ", f[i][j]);
		}
		// puts("");
	}
	int ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans = max(ans, f[n][i]);
	}
	printf("%d\n", ans);
}
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	c = read(), t = read();
	while (t--) solve();
	return 0;
}