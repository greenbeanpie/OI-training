#include <iostream>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, m, k, d, ans, x[N], y[N], v[N], g[N]; bool f[N];
int rd() {
	int res = 0; bool f = 0; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return f ? -res : res;
}
void dfs(int pos) {
	if (pos > n) {
		for (int i = 0, j; i <= n; i = j) {
			j = i + 1;
			while (j <= n && f[j]) ++ j;
			if (j - i - 1 > k) return ;
		}
		for (int i = 1; i <= n; ++ i) g[i] = g[i - 1] + f[i];
		int res = -g[n] * d;
		for (int i = 1; i <= m; ++ i)
			if (x[i] >= y[i] && g[x[i]] - g[x[i] - y[i]] == y[i])
				res += v[i];
		ans = max(ans, res);
		return ;
	}
	f[pos] = true; dfs(pos + 1);
	f[pos] = false; dfs(pos + 1);
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c = rd(), T = rd();
	while (T --) {
		n = rd(), m = rd(), k = rd(), d = rd(), ans = 0;
		for (int i = 1; i <= m; ++ i) x[i] = rd(), y[i] = rd(), v[i] = rd();
		if (n <= 20) {
			dfs(1);
			cout << ans << '\n';
		} else cout << "0\n";
	}
	return 0;
}
