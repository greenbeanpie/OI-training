#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int tc, T, n, m, cnt, ans[N], Ans, ff[N], sum[N], stk[N], ins[N], top, dfn[N], low[N], idx, scc, bel[N], ind[N], cov[N], nt[N], vs[N];
vector<int> h[N];
vector<int> g[N];
struct mdf {
	char opt;
	int i, j;
} q[N];
char t[N], tt[N];
inline char Not(char ch) {
	if (ch == 'U')
		return 'U';
	return ch == 'T' ? 'F' : 'T';
}
inline bool check() {
	for (int i = 1; i <= n; i++)
		tt[i] = t[i];
	for (int i = 1; i <= m; i++) {
		if (q[i].opt == '+')
			tt[q[i].i] = tt[q[i].j];
		else if (q[i].opt == '-')
			tt[q[i].i] = Not(tt[q[i].j]);
		else
			tt[q[i].i] = q[i].opt;
	}
	for (int i = 1; i <= n; i++)
		if (tt[i] != t[i])
			return false;
	return true;
}
inline void tarjan(int u) {
	stk[++top] = u, ins[u] = true;
	dfn[u] = low[u] = ++idx;
	for (int v : g[u]) {
		if (!dfn[v])
			tarjan(v), low[u] = min(low[u], low[v]);
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		scc++;
		while (ins[u]) {
			int v = stk[top--];
			bel[v] = scc, ins[v] = false;
		}
	}
}
inline void dfs(int dep) {
	if (cnt >= Ans)
		return;
	if (dep == n + 1) {
		if (check())
			Ans = cnt;
		return;
	}
	t[dep] = 'T', dfs(dep + 1);
	t[dep] = 'F', dfs(dep + 1);
	cnt++, t[dep] = 'U', dfs(dep + 1), cnt--;
}
inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> q[i].opt >> q[i].i;
		if (q[i].opt == '+' || q[i].opt == '-')
			cin >> q[i].j;
//		assert(q[i].j == 0);
	}
	int xx, yy;
	if (n <= 10) {
		Ans = 1e9;
		dfs(1);
		cout << (xx = Ans) << '\n';
	} else if (tc >= 3 && tc <= 4) {
		for (int i = 1; i <= n; i++)
			t[i] = 'T';
		for (int i = 1; i <= m; i++)
			t[q[i].i] = q[i].opt;
		Ans = 0;
		for (int i = 1; i <= n; i++)
			Ans += (t[i] == 'U');
		cout << Ans << '\n';
	} else if (tc >= 5 && tc <= 6) {
		for (int i = 1; i <= n; i++)
			ff[i] = 0;
		for (int i = 1; i <= m; i++) {
			if (q[i].opt == '+')
				ff[q[i].i] = ff[q[i].j];
			else
				ff[q[i].i] = true;
		}
		Ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				t[j] = ff[j] ? 'U' : 'T';
			if (check())
				break;
			for (int j = 1; j <= n; j++)
				ff[j] = (tt[j] == 'U');
		}
		for (int i = 1; i <= n; i++)
			Ans += ff[i];
		cout << (yy = Ans) << '\n';
	} else if (tc >= 7 && tc <= 8) {
		for (int i = 1; i <= 2 * n; i++)
			bel[i] = low[i] = dfn[i] = ins[i] = stk[i] = 0;
		scc = top = idx = 0;
		for (int i = 1; i <= m; i++) {
			int u = q[i].i, v = q[i].j;
			if (q[i].opt == '+') {
				g[v + n].emplace_back(u + n);
				g[v].emplace_back(u);
			} else {
				g[v].emplace_back(u + n);
				g[v + n].emplace_back(u);
			}
		}
		Ans = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (!dfn[i])
				tarjan(i);
		}
		for (int i = 1; i <= n; i++) {
			if (bel[i] == bel[i + n])
				Ans++;
		}
		cout << (yy = Ans) << '\n';
	}
//	if (xx != yy) {
//		cerr << xx << ' ' << yy << '\n';
//		for (int i = 1; i <= m; i++)
//			cerr << q[i].opt << ' ' << q[i].i << ' ' << q[i].j << '\n';
//		exit(0);
//	}
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> tc >> T;
	while (T--)
		solve();
	return 0;
}