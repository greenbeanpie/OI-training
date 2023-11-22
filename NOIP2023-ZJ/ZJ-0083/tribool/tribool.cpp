#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int c, T, n, m, a[N], b[N], p[N], q[N], res[N], k, ans;
char op[N];
bool vis[N];

inline int get_op(char ch) {
	if (ch == 'T') {
		return 2;
	}
	if (ch == 'F') {
		return 3;
	}
	return 4;
}

struct edge {
	int to, Next, cost;
	edge() {}
	edge(int to, int Next, int cost): to(to), Next(Next), cost(cost) {}
};

edge G[N << 1];
int head[N], cnt;

inline void add_edge(int u, int v, int w) {
	G[++cnt] = edge(v, head[u], w);
	head[u] = cnt;
}

inline void dfs1(int u, bool flg) {
	vis[u] = true;
	ans += flg;
	for (int i = head[u]; i; i = G[i].Next) {
		int v = G[i].to;
		if (!vis[v]) {
			dfs1(v, flg);
		}
	}
}

inline bool dfs2(int u, bool flg) {
	res[u] = flg;
	vis[u] = true;
	++k;
	bool r = true;
	for (int i = head[u]; i; i = G[i].Next) {
		int v = G[i].to, w = G[i].cost;
		if (!vis[v]) {
			r &= dfs2(v, flg ^ w);
		} else {
			if (!w && res[u] != res[v]) {
				r = false;
			}
			if (w && res[u] == res[v]) {
				r = false;
			}
		}
	}
	return r;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			a[i] = i, b[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> op[i];
			if (op[i] == 'T' || op[i] == 'F' || op[i] == 'U') {
				cin >> p[i];
				a[p[i]] = 0;
				b[p[i]] = get_op(op[i]);
			} else {
				cin >> p[i] >> q[i];
				a[p[i]] = a[q[i]];
				if (op[i] == '+') {
					b[p[i]] = b[q[i]];
				} else {
					if (b[q[i]] <= 3) {
						b[p[i]] = b[q[i]] ^ 1;
					} else {
						b[p[i]] = 4;
					}
				}
			}
		}
		memset(head, 0, sizeof(head));
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (b[i] <= 1) {
				add_edge(i, a[i], b[i]);
				add_edge(a[i], i, b[i]);
			}
		}
		ans = 0;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] && b[i] > 1) {
				dfs1(i, b[i] == 4);
			}
		}
		memset(res, 0, sizeof(res));
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				k = 0;
				if (!dfs2(i, 0)) {
					ans += k;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}