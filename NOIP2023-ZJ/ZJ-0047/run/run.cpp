#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N = 4e5 + 10;
ll tab[N];
int cc, len;
int n, m, k, d;
ll g[N];
struct Run {
	int l, r, v;
	inline bool operator<(Run b) const { return r < b.r; }
} p[N];

struct Segtree {
ll tag[N << 2], w[N << 2];
void build(int u, int L, int R) {
	tag[u] = 0;
	if (L == R) return void(w[u] = tab[L] * d);
	int M = L + R >> 1;
	build(u << 1, L, M), build(u << 1 | 1, M + 1, R);
	w[u] = tag[u] + max(w[u << 1], w[u << 1 | 1]);
}
ll query(int u, int L, int R, int l, int r) {
	if (L >= l && R <= r) return w[u];
	if (L > r || R < l) return -0x3f3f3f3f3f3f3f3f;
	int M = L + R >> 1;
	return tag[u] + max(query(u << 1, L, M, l, r), query(u << 1 | 1, M + 1, R, l, r));
}
void updatea(int u, int L, int R, int x, ll v) {
	if (L >= x) return tag[u] += v, void(w[u] += v);
	if (R < x) return;
	int M = L + R >> 1;
	updatea(u << 1, L, M, x, v), updatea(u << 1 | 1, M + 1, R, x, v);
	w[u] = tag[u] + max(w[u << 1], w[u << 1 | 1]);
}
void updateb(int u, int L, int R, int x, ll v) {
	if (R <= x) return tag[u] += v, void(w[u] += v);
	if (L > x) return;
	int M = L + R >> 1;
	updateb(u << 1, L, M, x, v), updateb(u << 1 | 1, M + 1, R, x, v);
	w[u] = tag[u] + max(w[u << 1], w[u << 1 | 1]);
}
} T;

inline void work() {
	n = m = k = d = cc = len = 0;
	memset(tab, 0, sizeof(tab));
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= m; i++) p[i] = {};
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		cin >> x >> y >> v, p[i].l = x - y + 1, p[i].r = x, p[i].v = v;
		tab[++len] = p[i].r + 2, tab[++len] = p[i].l, tab[++len] = p[i].r - k + 1, tab[++len] = p[i].r;
	}
	sort(p + 1, p + m + 1);
	sort(tab + 1, tab + len + 1), len = unique(tab + 1, tab + len + 1) - tab - 1;
	T.build(1, 1, len);
	ll ans = 0;
	int cc = 0;
	for (int l = 1, r; l <= m; l = r) {
		r = l;
		while (r <= m && p[r].r == p[l].r) ++r, ++cc;
		
		for (int j = l; j < r; j++) {
			++cc;
			int pl = lower_bound(tab + 1, tab + len + 1, p[j].l) - tab;
			T.updateb(1, 1, len, pl, p[j].v);
		}
		int pos = lower_bound(tab + 1, tab + len + 1, p[l].r) - tab;
		int pr = lower_bound(tab + 1, tab + len + 1, p[l].r - k + 1) - tab;
		g[pos] = T.query(1, 1, len, pr, pos) - (tab[pos] + 1) * d;
		ll t = g[pos] - ans;
		g[pos] = max(g[pos], ans);
		if (t > 0) T.updatea(1, 1, len, lower_bound(tab + 1, tab + len + 1, p[l].r + 2) - tab, t);
		ans = max(ans, g[pos]);
	}
	// cerr << "solveend" << endl;

	cout << ans << '\n';
}
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) work();
	// cerr << double(clock()) / CLOCKS_PER_SEC << '\n';
	return 0;
}
//g++ run.cpp -o run -fsanitize=undefined,address -D_GLIBCXX_DEBUG -Wall -g -O2 -std=c++14
//g++ run.cpp -o run -O2 -fsanitize=undefined,address  -g -O2 -std=c++14
//g++ run.cpp -o run -O2  -g -O2 -std=c++14