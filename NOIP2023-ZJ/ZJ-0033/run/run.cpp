#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int M = 1e5 + 5;
int tid, n, m, k, d;
struct Node {
	int l, r, v;
} b[M];
namespace Sub1 {
	const int N = 1005;
	LL f[N], g[N][N];
	void solve() {
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				g[i][j] = 0;
		for (int i = 1; i <= m; i++) g[b[i].l][b[i].r] += b[i].v;
		for (int i = n; i; i--)
			for (int j = i; j <= n; j++)
				g[i][j] += g[i + 1][j] + g[i][j - 1] - g[i + 1][j - 1];
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1];
			for (int j = max(0, i - k); j <= i; j++) {
				LL w;
				if (j) w = f[j - 1];
				else w = 0;
				f[i] = max(f[i], w + g[j + 1][i] - 1LL * (i - j) * d);
			}
		}
		printf("%lld\n", f[n]);
	}
}
void Solve() {
	n = read(); m = read(); k = read(); d = read();
	for (int i = 1; i <= m; i++) {
		b[i].r = read();
		b[i].l = b[i].r - read() + 1;
		b[i].v = read();
	}
	if (tid <= 7) {
		Sub1::solve();
		return;
	}
	LL ans = 0;
	for (int i = 1; i <= m; i++)
		if (b[i].r - b[i].l + 1 <= k)
			ans += max(0LL, b[i].v - 1LL * (b[i].r - b[i].l + 1) * d);
	printf("%lld\n", ans);
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	tid = read(); int _ = read();
	while (_--) Solve();
	return 0;
}