#include <bits/stdc++.h>
#define ll long long
#define RI int
#define W while
#define CI const int
#define Mt(a,x) memset(a,x,sizeof(a))
using namespace std;
#define pb push_back
CI N = 2e5, M = 1e3; int c, t, n, m, k, d, l[N + 5], r[N + 5], ls[3 * N + 5]; ll v[N + 5], dp[N + 5];
vector <int> id[N + 5]; bitset <N + 5> Tng; ll mx[N + 5];
void solve1 () {
	RI i, j; scanf ("%d%d%d%d", &n, &m, &k, &d);
	ls[0] = 0; for (i = 1; i <= m; ++ i) {
		int x, y, z; scanf ("%d%d%d", &x, &y, &z); l[i] = x - y + 1; r[i] = x; v[i] = z;
		ls[++ ls[0]] = l[i]; ls[++ ls[0]] = r[i];
	} sort (ls + 1, ls + ls[0] + 1); int cnt = unique (ls + 1, ls + ls[0] + 1) - ls - 1;
	for (i = 1; i <= cnt; ++ i) id[i].clear ();
	for (i = 1; i <= m; ++ i) {
		l[i] = lower_bound (ls + 1, ls + cnt + 1, l[i]) - ls;
		r[i] = lower_bound (ls + 1, ls + cnt + 1, r[i]) - ls;
		id[l[i]].pb (i); id[r[i]].pb (i);
	}ls[0] = -10000; ll ans = 0; Mt (dp, 0); Mt (mx, 0); for (i = 1; i <= cnt; ++ i) {
		ll now = 0; for (j = i; j >= 1; -- j) {
			if (ls[i] - ls[j] + 1 > (ll)(k)) break;
			for (int x : id[j]) {if (Tng[x] == 1) now += v[x]; else Tng[x] = 1;}
			dp[i] = max (dp[i], ((ls[j] - ls[j - 1] == 1) ? mx[j - 2] : mx[j - 1]) + now - (ll)(d) * (ls[i] - ls[j] + 1));
		} Tng = 0; mx[i] = max (mx[i - 1], dp[i]);
	} printf ("%lld\n", mx[cnt]);
}
void solve2 () {
	RI i, j; scanf ("%d%d%d%d", &n, &m, &k, &d); ll ans = 0;
	for (i = 1; i <= m; ++ i) {
		int x, y, z; scanf ("%d%d%d", &x, &y, &z); l[i] = x - y + 1; r[i] = x; v[i] = z;
		if (r[i] - l[i] + 1 <= k && v[i] - (ll)(d) * (r[i] - l[i] + 1) > 0)
		ans += v[i] - (ll)(d) * (r[i] - l[i] + 1);
	} printf ("%lld\n", ans);
}
int main () {
	freopen ("run.in", "r", stdin); freopen ("run.out", "w", stdout);
	scanf ("%d%d", &c, &t);
	if (c == 17 || c == 18) W (t --) {solve2 ();}
	else W (t --) {solve1 ();}
	return 0;                                                   
}     
/*
1 1
3 2 2 1
2 2 4
3 2 3

1 1
5 3 5 2
3 3 4
5 3 4
4 3 4

*/