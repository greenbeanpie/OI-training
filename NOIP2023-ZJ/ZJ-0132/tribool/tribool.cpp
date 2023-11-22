#include <bits/stdc++.h>
using namespace std;
//bool be;
const int N = 200010;

int n, m, pos[N], f[N], fa[N];
bool vis[N];
char ss[2];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void Union(int x, int y) { if ((x = find(x)) != (y = find(y))) fa[x] = y; }

inline void solve() {
	scanf("%d%d", &n, &m);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n + n + 6; ++i) pos[i] = i, f[i] = 0, fa[i] = i;
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%s", ss);
		if (ss[0] == '+') scanf("%d%d", &x, &y), pos[x] = pos[y], f[x] = f[y];
		else if (ss[0] == '-') scanf("%d%d", &x, &y), pos[x] = pos[y], f[x] = f[y] ^ 1;
		else scanf("%d", &x), pos[x] = n + (ss[0] != 'T' ? ss[0] != 'F' ? 3 : 2 : 1), f[x] = 0;
	}
	Union(n + 3, n + n + 6), vis[find(n + 3)] = 1;
	for (int i = 1; i <= n; ++i) Union(i, pos[i] + f[i] * (n + 3)), Union(i + n + 3, pos[i] + (!f[i]) * (n + 3))/*, printf("%d %d\n", pos[i], f[i])*/;
	for (int i = 1; i <= n; ++i) if (find(i) == find(i + n + 3)) vis[find(i)] = vis[find(i + n + 3)] = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) if (vis[find(i)]) ++ans;
	printf("%d\n", ans);
}

//bool en;
int main() {
//	printf("%lf\n", abs(&en - &be) / 1024.0 / 1024);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int type, T; for (scanf("%d%d", &type, &T); T--; solve());
	return 0;
}
