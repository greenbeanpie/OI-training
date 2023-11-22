#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, m, a[N], f[N], v[N], u, w, ans; char o[10];
int dfs(int u) {
	if (a[u] <= 0) return a[u];
	else if (v[u]) {
		bool s = f[u];
		for (int i=a[u]; i^u; s^=f[i], i=a[i]) ;
		return a[u] = s ? - 2 : 0;
	} v[u] = 1; int _ = dfs(a[u]);
	return a[u] = v[u] ? _ == - 2 ? - 2 : ~ _ : _;
}
int main() {
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	scanf ("%*d%d", &T);
	while (T --) {
		scanf ("%d%d", &n, &m), ans = 0;
		for (int i=1; i<=n; i++)
			a[i] = i, f[i] = v[i] = 0;
		while (m --) {
			scanf ("%s", o);
			if (isalpha(o[0]))
				scanf ("%d", &u), a[u] = o[0] == 'F' ? 0 : o[0] == 'T' ? - 1 : - 2, f[u] = 0;
			else
				scanf ("%d%d", &u, &w), a[u] = a[w], f[u] = (o[0] == '-') ^ f[w];
		}
		for (int i=1; i<=n; i++)
			ans += dfs(i) == - 2;
		printf ("%d\n", ans);
	}
}