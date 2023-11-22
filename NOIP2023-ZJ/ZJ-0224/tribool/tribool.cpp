#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int n, m, tmp, fl, f[maxn], sz[maxn], sx[maxn], a[maxn], v[maxn], col[maxn];
vector<int> g[maxn];

int fnd(int x) { return x == f[x] ? x : f[x] = fnd(f[x]); }

int pr(int x) { return x <= n ? -x : x - n; }
void merg(int x, int y) {
	x = fnd(x), y = fnd(y);
	if (x ^ y) 
		f[x] = y, sz[y] += sz[x],
		sx[y] = max(sx[y], sx[x]);
}

queue<int> q;

void colo(int x) {
	q.push(x);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		tmp += sz[u], col[u] = 1;
		for (int v : g[u]) if (!col[v]) q.push(v);
	}
}

void dfs(int x) {
	while (!q.empty()) q.pop();
	q.push(x);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		tmp += sz[u];
		for (int v : g[u])
			if (!col[v]) col[v] = 3 - col[u], q.push(v);
			else if (col[v] != 3 - col[u]) fl = 1;
	}
}

void work() {
	int ans = 0;
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) a[i] = i;
	for (int i = 1; i <= 2 * n; i ++) 
		v[i] = 0, f[i] = i, sz[i] = 1, sx[i] = -2, col[i] = 0,
		g[i].clear();
	
	for (int i = 1; i <= m; i ++) {
		char op = getchar();
		while (op == '\n' || op == '\r' || op == ' ') op = getchar(); 
		
		int x, y;
		scanf("%d", &x);
		
		if (op == 'T') a[x] = n + 1;
		else if (op == 'U') a[x] = 0;
		else if (op == 'F') a[x] = - (n + 1);
		else if (op == '+') scanf("%d", &y), a[x] = a[y];
		else scanf("%d", &y), a[x] = -a[y];
	}
	
	for (int i = 1; i <= n; i ++)
		if (a[i] == - n - 1) sx[fnd(i + n)] = -1, sx[fnd(i)] = 1;
		else if (a[i] == n + 1) sx[fnd(i + n)] = 1, sx[fnd(i)] = -1;
		else if (!a[i]) sx[fnd(i + n)] = sx[fnd(i)] = 0;
		else merg((a[i] < 0 ? -a[i] : a[i] + n), i + n);
	
	for (int i = 1; i <= n; i ++) {
		int x = fnd(i), y = fnd(i + n);
		g[x].emplace_back(y), g[y].emplace_back(x);
	}
	
	for (int i = 1; i <= 2 * n; i ++) {
		int fa = fnd(i); if (col[fa] || sx[fa] == -2) continue;
		tmp = 0, colo(fa); if (!sx[fa]) ans += tmp / 2;
	} 
	
	for (int i = 1; i <= 2 * n; i ++) {
		int fa = fnd(i); if (col[fa]) continue;
		fl = tmp = 0, col[fa] = 1, dfs(fa);
		if (fl) ans += tmp / 2;
	} 
	
	printf("%d\n", ans);
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	int id, T; 
	
	scanf("%d %d", &id, &T);
	while (T --) work();
}

// 求求了不要挂分...
// 100 pts 
