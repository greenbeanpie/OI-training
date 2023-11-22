#include <iostream>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int n, m, f[N], head[N], cnt; bool tmp[N], vis[N], check[N], instk[N];
struct Edge { int nxt, to; } e[N];
void add(int u, int v) { e[++ cnt] = {head[u], v}; head[u] = cnt; }
int rd() {
	int res = 0; bool f = 0; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return f ? -res : res;
}
char lottle_char() {
	char ch = getchar();
	while (ch == ' ' || ch == '\n') ch = getchar();
	return ch;
}
bool dfs(int u, bool num) {
	if (vis[u]) return tmp[u];
	if (instk[u]) return tmp[u] = num ^ check[u];
	instk[u] = true; check[u] = num; 
	tmp[u] = f[u] < 0 ? dfs(-f[u], num ^ 1) : dfs(f[u], num);
	vis[u] = true; return tmp[u];
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c = rd(), T = rd();
	while (T --) {
		n = rd(), m = rd();
		for (int i = 1; i <= n + 3; ++ i) f[i] = i, tmp[i] = vis[i] = check[i] = instk[i] = false, head[i] = 0; cnt = 0;
		while (m --) {
			char opt = lottle_char();
			if (opt == '+' || opt == '-') {
				int i = rd(), j = rd();
				f[i] = (opt == '+' ? 1 : -1) * f[j];
			} else f[rd()] = (opt == 'T' ? n + 1 : (opt == 'F' ? n + 2 : n + 3));
		}
		for (int i = 1; i <= n + 3; ++ i) if (f[i] == n + 3) f[i] = -n - 3;
		for (int i = 1; i <= n; ++ i) dfs(i, 0);
		int ans = 0;
		for (int i = 1; i <= n; ++ i) ans += tmp[i];
		cout << ans << '\n';
	}
	return 0;
}
