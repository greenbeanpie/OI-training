//multitest notice clear!!!!!!!
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, c, t, fl[N];
struct node {
	int fa;
	int typ; // typ == 1 : same,  2 : different , 3 : Unknown, 4 : T, 5 : F
}f[N];
bool vis[N];
int dfs_ring(int x, bool issame) {
	if (vis[f[x].fa]) {
		if ((f[x].typ == 1 && !issame) || (f[x].typ == 2 && issame))
			return f[x].typ = 4;
		return f[x].typ = 3;
	}
	vis[x] = 1;
	if (f[x].typ == 2)
		issame ^= 1;
	int fa_val = dfs_ring(f[x].fa, issame);
	if (fa_val == 3)
		f[x].typ = 3;
	else if (f[x].typ == 1)
		f[x].typ = fa_val;
	else if (fa_val == 4)
		f[x].typ = 5;
	else if (fa_val == 5)
		f[x].typ = 4;
	return f[x].typ;
}
int dfs(int x, bool issame) {
	if (f[x].typ != 1 && f[x].typ != 2) {
		return f[x].typ;
	}
	fl[x] = 1;
	if (fl[f[x].fa]) {
		if (f[f[x].fa].typ != 1 && f[f[x].fa].typ != 2) {
			if (f[f[x].fa].typ == 3)
				return f[x].typ = 3;
			if (f[x].typ == 1)
				return f[x].typ = f[f[x].fa].typ;
			if (f[f[x].fa].typ == 4)
				return f[x].typ = 5;
			return f[x].typ = 4;
		}
		return f[x].typ = dfs_ring(x, 0);
	}
	if (f[x].typ == 2)
		issame ^= 1;
	int fa_val = dfs(f[x].fa, issame);
	if (fa_val == 3)
		f[x].typ = 3;
	else if (f[x].typ == 1)
		f[x].typ = fa_val;
	else if (fa_val == 4)
		f[x].typ = 5;
	else if (fa_val == 5)
		f[x].typ = 4;
	return f[x].typ;
}
void solve() {
	cin >> n >> m;
	memset(fl, 0, sizeof(fl));
	memset(vis, 0, sizeof(vis));
	// for (int i = 1; i <= n; ++i) {
	// 	f[i] = i;
	// }
	for (int i = 1; i <= n; ++i)
		f[i] = {i, 0};
	for (int i = 1; i <= m; ++i) {
		char op;
		int x, y;
		cin >> op >> x;
		if (op == '+') {
			cin >> y;
			f[x].fa = y;
			f[x].typ = 1;
		} else if (op == '-') {
			cin >> y;
			f[x].fa = y;
			f[x].typ = 2;
		} else if (op == 'T') {
			f[x].fa = x;
			f[x].typ = 4;
		} else if (op == 'F') {
			f[x].fa = x;
			f[x].typ = 5;
		} else {
			f[x].fa = x;
			f[x].typ = 3;
		}
	}
	// for (int i = 1; i <= n; ++i)
	// 	cout << f[i].fa << " " << f[i].typ << endl;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (dfs(i, 0) == 3) ans++;
	}
	// for (int i = 1; i <= n; ++i)
	// 	cout << f[i].typ << endl;
	cout << ans << endl;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	while (t--) 
		solve();
	return 0;
}