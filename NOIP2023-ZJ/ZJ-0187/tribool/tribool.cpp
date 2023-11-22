#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int c, t, n, m;
int a[maxn], st[maxn], st_e[maxn], head[maxn], Next[maxn * 2], edge[maxn * 2], tot, ver[maxn * 2], top, siz, vis[maxn], loop;
int flag, id;
void add(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z, Next[tot] = head[x]; head[x] = tot;
}
// TF means n+1 and -n-1, U n+2
void init() {
	for (int i = 1; i <= tot; i++) Next[i] = edge[i] = ver[i] = 0;
	for (int i = 1; i <= n; i++) vis[i] = head[i] = st[i] = 0, head[i] = 0;
	tot = 1, top = 0; siz = 0;
	for (int i = 1; i <= n; i++) a[i] = i;
}
void dfs(int x, int fa_edge) {
	vis[x] = 1; siz++; st[++top] = x; st_e[top] = fa_edge;
	if (abs(a[x]) == n + 2) flag = 1;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (i == (fa_edge ^ 1)) continue;
	//	if (x == y && edge[i] == 1) flag = 1;
	//	if (x == y) continue;
		if (vis[y]) {
			if (id) continue;
			id = 1;
		//	cout << x << " " << y << " " << edge[i] << endl;
			while (top > 0 && st[top] != y) {
				loop += edge[st_e[top]]; top--;
			}
			loop += edge[i];
		}else dfs(y, i);
	}
	top--;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		init();
		for (int i = 1; i <= m; i++) {
			char op; int x, y; scanf(" %c", &op);
			if (op == '+' || op == '-') {
				scanf("%d%d", &x, &y); 
				if (op == '+') a[x] = a[y];
				else a[x] = -a[y];
			}else {
				scanf("%d", &x);
				int val = 0;
				if (op == 'T') val = n + 1;
				if (op == 'F') val = -n-1;
				if (op == 'U') val = n+2;
				a[x] = val;
			}
		}
		
		//for (int i = 1; i <= n; i++) cout << a[i] << " ";
	//	cout << endl;
		for (int i = 1; i <= n; i++) {
			int x = i, y = abs(a[i]), val = 0;
		//	cout << a[i] << " ";
			if (a[i] < 0) val = 1;
			if (y <= n) {
			//	cout << t << " " << x << " " << y << " " << val << " edge" << endl;
				add(x, y, val); add(y, x, val);
			}
		}
		int ans = 0;
	//	cout << "work" << endl;
	//	dfs(1, 0);
	//	cout << "work" << endl;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			siz = 0; top = 0; loop = 0; flag = 0; id = 0; dfs(i, 0);
		//	cout << loop << " loop" << endl;
			if (loop % 2 == 1 || flag) ans += siz;// cout << i << " " << loop << endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}