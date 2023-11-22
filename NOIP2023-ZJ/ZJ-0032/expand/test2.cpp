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
		if (a[1] == b[1]) { putchar('0'); continue; }
		bool flag = 0;
		if (a[1] < b[1]) { for (int i=1; i<=max(n,m); i++) swap(a[i], b[i]); swap(n, m), flag = 1; }
		int p = 1;
		while (p < m && b[p+1] < a[1])
			p ++;
		for (int i=2; i<=n; i++)
			if (a[i] >= a[i-1])
				while (p < m && b[p+1] < a[i])
					p ++;
			else {
				while (p && b[p] >= a[i])
					p --;
				if (! p) break;
			}
		putchar((p == m) + '0');
		if (flag) swap(n, m);
	}
}