#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, _k, d;
struct rec {
	int x, y, v;
} a[N];
ll dp[N], mx[N];
ll calc(int x, int y) {
	ll ans = 0;
	for (int i = 1; i <= m; ++i)
		if (x <= a[i].x && a[i].y <= y) ans += a[i].v;
	return ans;
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int cas, T;
	cin >> cas >> T;
	while (T--) {
		cin >> n >> m >> _k >> d;
		//if (!T) printf("%d %d %d %d\n", n, m, _k, d);
		for (int i = 1, x, y; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &a[i].v);
			a[i].y = x, a[i].x = x - y + 1;
			dp[i] = 0;
		}
		sort(a + 1, a + m + 1, [] (const rec &a, const rec &b) {
			return a.y < b.y;
		});
		int nn = 0;
		ll ans = 0;
		//	if (T != 6) continue;
		for (int i = 1; i <= m; ++i)
			if (a[i].y - a[i].x + 1 <= _k) a[++nn] = a[i];
		m = nn;
		if (cas == 17 || cas == 18) {
			for (int i = 1; i <= m; ++i) {
				ll v = a[i].v - 1ll * (a[i].y - a[i].x + 1) * d;
				if (v > 0) ans += v;
			}
		} else if (1 <= cas && cas <= 4) {
			for (int i = 1; i <= n; ++i) {
				dp[i] = dp[i - 1];
				for (int j = max(0, i - _k); j < i; ++j)
					dp[i] = max(dp[i], dp[max(j - 1, 0)] + calc(j + 1, i) - 1ll * (i - j) * d);
			}
			ans = dp[n];
		} else {
			for (int i = 1; i <= m; ++i) {
				int l = a[i].x, pos = i;
				ll v = a[i].v;
				while (a[pos].y >= l - 1 && pos) --pos;
				dp[i] = 0;
				if (a[i].y - l + 1 <= _k)
					dp[i] = max(dp[i], mx[pos] + v - 1ll * (a[i].y - l + 1) * d);
				for (int j = i - 1; j; --j) {
					if (a[j].y < l) break;
					if (a[j].y >= l) {
						if (a[i].y - a[j].x + 1 > _k) continue;
						v += a[j].v;
						l = min(l, a[j].x);
					}
					while (a[pos].y >= l - 1 && pos) --pos;
				//	assert(a[pos].y < l && a[i].y -  l + 1 <= _k);
					dp[i] = max(dp[i], mx[pos] + v - 1ll * (a[i].y - l + 1) * d);
				}
				mx[i] = max(mx[i - 1], dp[i]);
			}
			ans = mx[m];
		}
		printf("%lld\n", ans);
		//if (ans == 111854682156) printf("%d %d %d %d\n", n, m, _k, d);
	}
}
