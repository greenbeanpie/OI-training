#include<bits/stdc++.h>
using namespace std;

#define Reimu inline void
#define Marisa inline int

typedef long long LL;
typedef unsigned long long ULL;

typedef pair<int, int> Pii;
#define fi first
#define se second

const int N = 100010;

int n, m, ans;
int fa[N], fb[N], vis[N], anc[N << 1], num[100];
vector<int> G[N];

int flg;

Marisa getAnc(int x) { return anc[x] == x ? x : anc[x] = getAnc(anc[x]); }

Reimu dfs(int x, int t) {
	vis[x] = 1;
	if (fb[x]) t *= fb[x];
	ans += !t;
	for (int y: G[x]) dfs(y, t);
}

Reimu Sakuya() {
	cin >> n >> m;
	ans = 0;
	memset(vis + 1, 0, n << 2);
	for (int i = 1; i <= n; ++i) fa[i] = i, fb[i] = 1, G[i].clear();
	for (int i = 1; i <= n << 1; ++i) anc[i] = i;
	for (int i = 1, x, y; i <= m; ++i) {
		char c; cin >> c;
		switch (c) {
		case '+': {
			cin >> x >> y;
			fa[x] = fa[y]; fb[x] = fb[y];
		} break; case '-': {
			cin >> x >> y;
			fa[x] = fa[y]; fb[x] = -fb[y];
		} break; default: {
			cin >> x;
			fa[x] = num[c]; fb[x] = 0;
		}
		}
	}
	for (int i = 1; i <= n; ++i) if (fb[i]) G[fa[i]].emplace_back(i);
	for (int i = 1; i <= n; ++i) if (!fb[i]) dfs(i, fa[i]);
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		if (~fb[i]) anc[getAnc(i)] = getAnc(fa[i]), anc[getAnc(i + n)] = getAnc(fa[i] + n);
		else anc[getAnc(i)] = getAnc(fa[i] + n), anc[getAnc(i + n)] = getAnc(fa[i]);
	}
	for (int i = 1; i <= n; ++i) ans += getAnc(i) == getAnc(i + n);
	cout << ans << '\n';
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	num['T'] = 1; num['F'] = -1; num['U'] = 0;
	int _, T; cin >> _ >> T; while (T--) Sakuya();
	return 0;
}

