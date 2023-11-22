#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e7;
int x[500005], y[500005];
int n, m, q;
int X[500005], Y[500005];
int f[500005];
inline int read () {
	int res = 0, sym = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			sym = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res<<3) + (res<<1) + c - '0';
		c = getchar();
	}
	return sym * res;
}
bool solve () {
	return (x[1] - y[1]) * (x[n] - y[m]) > 0;
}
int main () {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c = read();
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		x[i] = X[i] = read();
	for (int i = 1; i <= m; i++)
		y[i] = Y[i] = read();
	putchar(solve() ? '1' : '0');
	while (q--) {
		int kx = read(), ky = read();
		for (int i = 1; i <= n; i++)
			x[i] = X[i];
		for (int i = 1; i <= m; i++)
			y[i] = Y[i];
		while (kx--) {
			int p = read(), v = read();
			x[p]= v;
		}
		while (ky--) {
			int p = read(), v = read();
			y[p] = v;
		}
		putchar(solve() ? '1' : '0');
	}
	return 0;
}