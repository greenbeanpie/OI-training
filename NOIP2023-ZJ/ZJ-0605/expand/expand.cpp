#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c ^ 48);
	return x;
}

const int MAXN = 5e5 + 5;
int c, n, m, q;
int xx[MAXN], ex[MAXN], yy[MAXN], ey[MAXN];
bool f[2005][2005];

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	c = read();
	n = read();
	m = read();
	q = read();
	for (int i = 1; i <= n; ++i) ex[i] = read();
	for (int j = 1; j <= m; ++j) ey[j] = read();
	for (int i = 1; i; --i) {
		for (int i = 1; i <= n; ++i) xx[i] = ex[i];
		for (int j = 1; j <= m; ++j) yy[j] = ey[j];
		if (c == 1) {
			putchar(xx[1] == yy[1] ? '0' : '1');
			continue;
		}
		if (c == 2) {
			if (1ll * (xx[1] - yy[1]) * (xx[2] - yy[2]) > 0ll) putchar('1');
			else putchar('0');
			continue;
		}
		if (xx[1] == yy[1] || xx[n] == yy[m]) {
			putchar('0');
			continue;
		}
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) f[i][j] = 0;
		f[1][1] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (j < m && 1ll * (xx[1] - yy[1]) * (xx[i] - yy[j + 1]) > 0ll) f[i][j + 1] |= f[i][j];
				if (i < n && 1ll * (xx[1] - yy[1]) * (xx[i + 1] - yy[j]) > 0ll) f[i + 1][j] |= f[i][j];
			}
		}
//		cout << endl;
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= m; ++j) cout << f[i][j] << ' ';
//			cout << endl;
//		}
		putchar(f[n][m] ? '1' : '0');
	}
	for (; q; --q) {
		for (int i = 1; i <= n; ++i) xx[i] = ex[i];
		for (int j = 1; j <= m; ++j) yy[j] = ey[j];
		int kx = read(), ky = read();
		for (int i = 1; i <= kx; ++i) {
			int px = read(), vx = read();
			xx[px] = vx;
		}
		for (int j = 1; j <= ky; ++j) {
			int py = read(), vy = read();
			yy[py] = vy;
		}
//		for (int i = 1; i <= n; ++i) cout << xx[i] << ' ';
//		cout << endl;
//		for (int j = 1; j <= m; ++j) cout << yy[j] << ' ';
//		cout << endl;
		if (c == 1) {
			putchar(xx[1] == yy[1] ? '0' : '1');
			continue;
		}
		if (c == 2) {
			if (1ll * (xx[1] - yy[1]) * (xx[2] - yy[2]) > 0ll) putchar('1');
			else putchar('0');
			continue;
		}
		if (xx[1] == yy[1] || xx[n] == yy[m]) {
			putchar('0');
			continue;
		}
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) f[i][j] = 0;
		f[1][1] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (j < m && 1ll * (xx[1] - yy[1]) * (xx[i] - yy[j + 1]) > 0ll) f[i][j + 1] |= f[i][j];
				if (i < n && 1ll * (xx[1] - yy[1]) * (xx[i + 1] - yy[j]) > 0ll) f[i + 1][j] |= f[i][j];
			}
		}
//		cout << endl;
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= m; ++j) cout << f[i][j] << ' ';
//			cout << endl;
//		}
		putchar(f[n][m] ? '1' : '0');
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}