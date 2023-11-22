#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N], fac[N];
int n, m, c, t;
bool isu[N];
int ind[N];
bool vis[N];
int q[N], l = 1, r;
void work() {
	memset(ind, 0, sizeof(ind));
	memset(vis, 0, sizeof(vis));
	isu[0] = 1, l = 1, r = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i, fac[i] = 1, isu[i] = 0;
	for (int i = 1; i <= m; i++) {
		char c;
		int x, y;
		cin >> c >> x;
		if (c == 'T' || c == 'F') continue;
		if (c == 'U') {
			fa[x] = 0, fac[x] = 1;
			continue;
		}
		cin >> y;

		fa[x] = fa[y], fac[x] = fac[y] * (c == '+' ? 1 : -1);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) ++ind[fa[i]];
	for (int i = 1; i <= n; i++)
		if (!ind[i]) q[++r] = i;
	while (l <= r) {
		int u = q[l++];
		vis[u] = 1;
		if (!--ind[fa[u]]) q[++r] = fa[u];
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			// cout << "unique:" << i << ' ' << fa[i] << endl;
			int t = i, sum = 1;
			do sum *= fac[t], vis[t] = 1, t = fa[t];
			while (t != i);
			if (sum == -1) {
				do isu[t] = 1, t = fa[t];
				while (t != i);
			}
		}
	// cout << "-----" << endl;
	for (int i = r; i >= 1; i--) isu[q[i]] = isu[fa[q[i]]];
	for (int i = 1; i <= n; i++) res += isu[i];
	cout << res << '\n';
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	while (t--) work();
	return 0;
}
//g++ tribool.cpp -o tribool -fsanitize=undefined,address -std=c++14 -O2