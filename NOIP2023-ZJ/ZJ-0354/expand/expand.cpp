#include <cstdio>
#include <algorithm>
#include <cstring>
#define Maxn 500000
namespace FASTIO {
	char get_an_opt() {
		char ch = getchar();
		while(ch != '+' && ch != '-' && ch != 'T' && ch != 'F' && ch != 'U') ch = getchar();
		return ch;
	}
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
		while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
		return x * f;
	}
	void write(int x) {
		if(x < 0) putchar('-'), write(-x);
		else if(x <= 9) putchar(x + '0');
		else write(x / 10), putchar(x % 10 + '0');
	}
}
int n, m, q, X[Maxn + 9], Y[Maxn + 9], x[Maxn + 9], y[Maxn + 9], tmp[Maxn + 9];
bool ans, f[2][Maxn + 9];
bool Solve() {
	std::memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 1, j = 0; i <= m; ++ i, ++ j) {
		f[i & 1][0] = 0;
		for(int k = 1; k <= n; ++ k)
			if(x[k] > y[i] && (f[j & 1][k - 1] || f[j & 1][k] || f[i & 1][k - 1])) f[i & 1][k] = 1;
			else f[i & 1][k] = 0;
	}
	return f[m & 1][n];
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c = FASTIO::read();	
	n = FASTIO::read(), m = FASTIO::read(), q = FASTIO::read();
	for(int i = 1; i <= n; ++ i) X[i] = FASTIO::read();
	for(int i = 1; i <= m; ++ i) Y[i] = FASTIO::read();
	ans = 0;
	for(int i = 1; i <= n; ++ i) x[i] = X[i];
	for(int i = 1; i <= m; ++ i) y[i] = Y[i];
	ans |= Solve();
	for(int i = 1; i <= n; ++ i) tmp[i] = x[i];
	for(int i = 1; i <= m; ++ i) x[i] = y[i];
	for(int i = 1; i <= n; ++ i) y[i] = tmp[i];
	std::swap(n, m);
	ans |= Solve();
	std::swap(n, m);
	putchar(ans + '0');
	while(q --) {
		ans = 0;
		for(int i = 1; i <= n; ++ i) x[i] = X[i];
		for(int i = 1; i <= m; ++ i) y[i] = Y[i];
		int kx = FASTIO::read(), ky = FASTIO::read();
		while(kx --) {
			int px = FASTIO::read(), vx = FASTIO::read();
			x[px] = vx;
		}
		while(ky --) {
			int py = FASTIO::read(), vy = FASTIO::read();
			y[py] = vy;
		}
		ans |= Solve();
		for(int i = 1; i <= n; ++ i) tmp[i] = x[i];
		for(int i = 1; i <= m; ++ i) x[i] = y[i];
		for(int i = 1; i <= n; ++ i) y[i] = tmp[i];
		std::swap(n, m);
		ans |= Solve();
		std::swap(n, m);
		putchar(ans + '0');
	}
	puts("");
	return 0;
}