#include <bits/stdc++.h>
using namespace std;
int read() {
	int s = 0; char ch = getchar();
	while (! isdigit(ch)) ch = getchar();
	while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s;
}
const int N = 5e5 + 5;
int n, m, q, x[N], y[N], a[N], b[N], ka, kb, p, f[2005][2005];
int main() {
	read(), n = read(), m = read(), q = read();
	q  =3;
	for (int i=1; i<=n; i++) x[i] = read();
	for (int i=1; i<=m; i++) y[i] = read();
	for (int t=0; t<=q; t++) {
		for (int i=1; i<=n; i++) a[i] = x[i];
		for (int i=1; i<=m; i++) b[i] = y[i];
		if (t) {
			ka = read(), kb = read();
			while (ka --) p = read(), a[p] = read();
			while (kb --) p = read(), b[p] = read();
		}
		for (int i=1; i<=n; i++) cerr << a[i] << ' '; cerr << endl;
		for (int i=1; i<=m; i++) cerr << b[i] << ' '; cerr << endl;
		if (a[1] == b[1]) { putchar('0'); continue; }
		bool flag = 0;
		if (a[1] < b[1]) { for (int i=1; i<=max(n,m); i++) swap(a[i], b[i]); swap(n, m), flag = 1; }
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) f[i][j] = a[i] > b[j];
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (i > 1 || j > 1) f[i][j] &= f[i-1][j] | f[i][j-1];
		putchar(f[n][m] + '0');	
		if (flag) swap(n, m);
	}
}