#include <bits/stdc++.h>
using namespace std;
#define debug(...) fprintf (stderr, __VA_ARGS__)
typedef long long ll;
const int N = 100010;
int id;
namespace sub1 {
	int T, n, m, k, cl[N], cr[N], cll[N], crr[N], div[N], p[N];
	ll d, val[N], vall[N], dp[N];
	bool cmp (int x, int y) {
		return cr[x] == cr[y]? cl[x] < cl[y]: cr[x] < cr[y];
	}
	void main () {
		scanf ("%d", &T);
		while (T --> 0) {
			scanf ("%d%d%d%lld", &n, &m, &k, &d);
			for (int i = 1; i <= m; i++) {
				scanf ("%d%d%lld", &cr[i], &cl[i], &val[i]);
				cl[i] = cr[i] - cl[i] + 1;
				p[i] = i;
			}
			sort (p + 1, p + m + 1, cmp);
			for (int i = 1; i <= m; i++) {
				cll[i] = cl[i];
				crr[i] = cr[i];
				vall[i] = val[i];
			}
			for (int i = 1; i <= m; i++) {
				cl[i] = cll[p[i]];
				cr[i] = crr[p[i]];
				val[i] = vall[p[i]];
			}
			int c = 0;
			for (int i = 1; i <= m; i++) {
				while (cr[i] != c) {
					div[c++] = i - 1;
				}
			}
			while (c <= n) {
				div[c++] = m;
			}
			fill (dp, dp + k + 1, 0);
			for (int i = 1; i <= n; i++) {
				ll tmp = dp[0], awa = 0;
				for (int j = 1; j <= k; j++) {
					tmp = max (tmp, dp[j]);
				}
				for (int j = div[i - 1] + 1; j <= div[i]; j++) {
					awa += val[j];
				}
				int ach = div[i - 1] + 1;
				for (int j = k; j >= 1; j--) {
					dp[j] = dp[j - 1] + awa - d;
					if (ach <= div[i] && i - j + 1 == cl[ach]) {
						awa -= val[ach];
						ach++;
					}
				}
				dp[0] = tmp;
			}
			ll ans = dp[0];
			int fin = 0;
			for (int i = 1; i <= k; i++) {
				if (dp[i] > ans) {
					fin = i;
				}
				ans = max (ans, dp[i]);
			}
			printf ("%lld\n", ans);
		}
	}
}
int main () {
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	scanf ("%d", &id);
	if (id <= 9) {
		sub1::main ();
	}
	return 0;
}