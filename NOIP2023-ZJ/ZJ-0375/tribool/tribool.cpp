#include <bits/stdc++.h>
using namespace std; const int N = 1e5 + 5, tt = 1, uu = 2, ff = 3;
#define eb emplace_back
int c, n, m, ans, a[N], b[N], lst[N], vl[N * 5];
int cnt, ver[N * 5], rt[N], fa[N * 5], num[N * 5]; bool vis[N * 5];
struct operations {
	char type; int x, y; 
	operations(char t_ = ' ', int x_ = 0, int y_ = 0) { type = t_; x = x_; y = y_; }
} q[N];
struct edge {
	int v, w; edge(int v_ = 0, int w_ = 0) { v = v_; w = w_; }
}; vector<edge> g[N * 5], ng[N * 5];
void dfs(int u, int f, int val) {
	fa[u] = f; vl[u] = val;
	for (edge i : g[u]) dfs(i.v, f, i.w * val);
}
void color(int u) {
	vis[u] = 1;
	for (edge i : ng[u]) {
		if (vis[i.v]) continue;
		num[i.v] = num[u] * i.w; vis[i.v] = 1;
		color(i.v);
	}
}
void dfs1(int dep, int cnt) {
	if (dep > n) {
		for (int i = 1; i <= n; ++i) b[i] = a[i];
		for (int i = 1; i <= m; ++i) {
			if (q[i].type == '+') b[q[i].x] = b[q[i].y];
			else if (q[i].type == '-') b[q[i].x] = -b[q[i].y];
			else if (q[i].type == 'T') b[q[i].x] = 1;
			else if (q[i].type == 'F') b[q[i].x] = -1;
			else b[q[i].x] = 0;
		}		
		for (int i = 1; i <= n; ++i) if (b[i] != a[i]) return;
		ans = min(ans, cnt);
		return;
	}
	for (int i = -1; i <= 1; ++i) a[dep] = i, dfs1(dep + 1, cnt + (i == 0));
}
void work() {
	cin >> n >> m; ans = N;
	for (int i = 1; i <= m; ++i) {
		cin >> q[i].type >> q[i].x;
		if (q[i].type == '+' || q[i].type == '-') cin >> q[i].y;
	}
	if (n <= 10 && m <= 10) {
		dfs1(1, 0); cout << ans << '\n'; return;
	}
	if (c == 3 || c == 4) {
		ans = 0;
		for (int i = 1; i <= n; ++i) a[i] = 1;
		for (int i = 1; i <= m; ++i) {
			if (q[i].type == 'T') a[q[i].x] = 1;
			if (q[i].type == 'F') a[q[i].x] = -1;
			if (q[i].type == 'U') a[q[i].x] = 0;
		}
		for (int i = 1; i <= n; ++i) ans += (a[i] == 0);
		cout << ans << '\n';
		return;
	}
	ans = 0;
	memset(rt, 0, sizeof rt);
	memset(lst, 0, sizeof lst);
	memset(g, 0, sizeof g);
	memset(ng, 0, sizeof ng);
	memset(ver, 0, sizeof ver);
	memset(fa, 0, sizeof fa);
	memset(num, 0, sizeof num);
	memset(vis, 0, sizeof vis);
	memset(vl, 0, sizeof vl); cnt = 3;
	for (int i = 1; i <= n; ++i) rt[i] = lst[i] = ++cnt; 
	for (int i = 1, tmp; i <= m; ++i) {
		if (q[i].type == 'T') {
			++cnt; g[tt].eb(cnt, 1);
			lst[q[i].x] = cnt; ver[q[i].x] = i;
		} else if (q[i].type == 'F') {
			++cnt; g[ff].eb(cnt, 1);
			lst[q[i].x] = cnt; ver[q[i].x] = i;
		} else if (q[i].type == 'U') {
			++cnt; g[uu].eb(cnt, 1);
			lst[q[i].x] = cnt; ver[q[i].x] = i;
		} else if (q[i].type == '+') {
			if (ver[q[i].y] != i - 1) {
				++cnt; g[lst[q[i].y]].eb(cnt, 1); 
				ver[q[i].y] = i - 1; lst[q[i].y] = cnt;
			}
			++cnt; g[lst[q[i].y]].eb(cnt, 1);
			ver[q[i].x] = i; lst[q[i].x] = cnt;
		} else {
			if (ver[q[i].y] != i - 1) {
				++cnt; g[lst[q[i].y]].eb(cnt, 1); 
				ver[q[i].y] = i - 1; lst[q[i].y] = cnt;
			}
			++cnt; g[lst[q[i].y]].eb(cnt, -1);
			ver[q[i].x] = i; lst[q[i].x] = cnt;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (ver[i] != m) {
			++cnt; g[lst[i]].eb(cnt, 1);
			ver[i] = m; lst[i] = cnt;
		}
	}
	dfs(tt, tt, 1); dfs(ff, ff, 1); dfs(uu, uu, 1);
	for (int i = 1; i <= n; ++i) dfs(rt[i], rt[i], 1);
	for (int i = 1; i <= cnt; ++i) num[i] = -2;
	num[tt] = 1; num[uu] = 0; num[ff] = -1;
	for (int i = 1; i <= n; ++i) {
		ng[fa[lst[i]]].eb(lst[i], vl[lst[i]]);
		ng[lst[i]].eb(fa[lst[i]], vl[lst[i]]);
		ng[rt[i]].eb(lst[i], 1); ng[lst[i]].eb(rt[i], 1);
		if (fa[lst[i]] == rt[i] && vl[lst[i]] == -1) 
			num[lst[i]] = num[rt[i]] = 0;
	}
	if (!vis[tt]) color(tt);
	if (!vis[uu]) color(uu);
	if (!vis[ff]) color(ff);
	for (int i = 1; i <= n; ++i)
		if (num[rt[i]] != -2 && !vis[rt[i]]) color(rt[i]);
	for (int i = 1; i <= n; ++i)
		if (num[lst[i]] != -2 && !vis[lst[i]]) color(lst[i]);
 	for (int i = 1; i <= n; ++i) ans += (num[lst[i]] == 0);
	cout << ans << '\n';
}
int main() {
	freopen("tribool.in", "r", stdin); freopen("tribool.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int testcases; cin >> c >> testcases;
	while (testcases--) work();
	return 0;	
}