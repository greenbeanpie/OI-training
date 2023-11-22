#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
	return x * f;
}

const int N = 4e5 + 10;

int T;

int n, m;

int fa[N];

bool vis[N];

vector<int> e[N], g[N], vec[N];

inline void dfs(int u) {
	vis[u] = 1;
	for (auto v : e[u]) 
		if (!vis[v]) dfs(v);
}

queue<int> q;

int deg[N];
int p;

inline void dfs0(int u) {
	if (p) return;
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v]) {p = v; return;}
		dfs0(v);
	}
} 
int cnt; int buc[N], siz[N]; bool flg[N];
inline void dfs1(int u) {
	buc[u] = cnt; siz[cnt] ++;
	for (auto v : e[u]) 
		if (!buc[v]) dfs1(v);
}

inline void solve() {
	n = read(); m = read();
	for (int i = 1, x, y, a, b; i <= m; ++ i) {
		char c; scanf(" %c", &c);
		if (c == 'U') x = read(), fa[x] = fa[n+x] = 2*n+1;
		else if (c == 'T') x = read(), fa[x] = 2*n+2, fa[n+x] = 2*n+3;
		else if (c == 'F') x = read(), fa[x] = 2*n+3, fa[n+x] = 2*n+2;
		else if (c == '+') x = read(), y = read(), a = fa[y], b = fa[n+y], fa[x] = a, fa[n+x] = b;
		else if (c == '-') x = read(), y = read(), a = fa[y], b = fa[n+y], fa[x] = b, fa[n+x] = a;
	}  int ans = 0;
	for (int i = 1; i <= 2*n; ++ i) 
		if (fa[i] != i) e[fa[i]].pb(i), g[i].pb(fa[i]), deg[i] ++;
	cnt = 0;
	for (int i = 1; i <= 2*n+3; ++ i) if (!deg[i]) q.push(i), ++ cnt, buc[i] = cnt;
	memset(siz, 0, sizeof siz);
	while (!q.empty()) {
		int u = q.front(); q.pop(); siz[buc[u]] ++;
		for (auto v : e[u]) {
			buc[v] = buc[u];
			if (!--deg[v]) q.push(v);
		}
	} 
	for (int i = 1; i <= 2*n; ++ i) if (deg[i] && !buc[i]) p = 0, dfs0(i), ++ cnt, dfs1(p); 
	flg[buc[2*n+1]] = 1; q.push(buc[2*n+1]);
	for (int i = 1; i <= n; ++ i) {
		if (buc[i] != buc[i+n]) {
			vec[buc[i]].pb(i), vec[buc[i+n]].pb(i);
		} else {
			if (!flg[buc[i]]) {
				flg[buc[i]] = 1; 
				q.push(buc[i]);
			}
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : vec[u]) {
			if (buc[v+n] != u) {
				if (!flg[buc[v+n]]) {
					flg[buc[v+n]] = 1; 
					q.push(buc[v+n]);
				}
			} else {
				if (!flg[buc[v]]) {
					flg[buc[v]] = 1; 
					q.push(buc[v]);
				}
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= cnt; ++ i)
		if (flg[i]) ans += siz[i];
	printf("%d\n", (ans-1) >> 1);
	memset(vis, 0, sizeof vis); memset(deg, 0, sizeof deg); 
	memset(flg, 0, sizeof flg); memset(siz, 0, sizeof siz); memset(buc, 0, sizeof buc); 
	for (int i = 1; i <= 2*n+3; ++ i) fa[i] = i, e[i].clear(), g[i].clear(), vec[i].clear();
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int tid = read(); T = read();
	for (int i = 1; i < N; ++ i) fa[i] = i;
	while (T --) solve();
	return 0;
}
