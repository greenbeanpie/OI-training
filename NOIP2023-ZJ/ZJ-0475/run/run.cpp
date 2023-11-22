#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
inline ll read() {
	ll s = 0, w = 1; char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') w = -1; c = getchar();}
	while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	return s * w;
}
const int N = 100010;
int op, t, n, m;
ll k, d, ans;
int s[N], cnt;
int a[21], sum[21];
int px[N], py[N], pv[N];
void calc() {
//	for (int i = 1; i <= n; i++) cout << a[i] << ' '; puts("");
	ll now = -sum[n] * d;
	for (int i = 1; i <= m; i++)
		if (sum[px[i]] - sum[px[i] - py[i]] == py[i]) now += pv[i];
	ans = max(ans, now);
//	cout << "### " << now << '\n';
}
void dfs(int x) {
	if (x > n) {
		calc();
		return ;
	}
	a[x] = 0;
	sum[x] = sum[x - 1] + a[x];
	dfs(x + 1);
	a[x] = 1;
	sum[x] = sum[x - 1] + a[x];
	if (x >= k && sum[x] - sum[x - k] == k) return ;
	dfs(x + 1);
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	op =read(), t = read();
	for (int I = 1; I <= t; I++) {
		n = read(), m = read(), k = read() + 1, d = read();
		for (int i = 1; i <= m; i++) px[i] = read(), py[i] = read(), pv[i] = read();
		if (n <= 18) {
			ans = 0;
			dfs(1);
			printf("%lld\n", ans);
		}
		else puts("0");
	}
	return 0;
}
