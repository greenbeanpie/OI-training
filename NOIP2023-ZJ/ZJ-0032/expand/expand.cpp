#include <bits/stdc++.h>
using namespace std;
int read() {
	int s = 0; char ch = getchar();
	while (! isdigit(ch)) ch = getchar();
	while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s;
}
const int N = 5e5 + 5;
int n, m, q, x[N], y[N], a[N], b[N], ka, kb, p;
int Min[N<<2], Max[N<<2], pos[N], id[N<<2];
void build(int p, int l, int r) {
	id[p] = 0;
	if (l == r) return void ((Min[p] = Max[p] = b[l], pos[l] = p, id[p] = l));
	int mid = l + r >> 1;
	build(p<<1, l, mid), build(p<<1|1, mid+1, r);
	Min[p] = min(Min[p<<1], Min[p<<1|1]), Max[p] = max(Max[p<<1], Max[p<<1|1]);
}
int getnxt(int i, int a) {
	int p = pos[i];
	for (; p>1; p>>=1)
		if (! (p & 1) && Max[p|1] >= a) {
			for (p|=1; !id[p]; p=p<<1|(Max[p<<1]<a)) ;
			return id[p] - 1;
		}
	return m;
}
int getpre(int i, int a) {
	int p = pos[i];
	for (; p>1; p>>=1)
		if ((p & 1) && Min[p^1] < a) {
			for (p^=1; !id[p]; p=p<<1|(Min[p<<1|1]<a)) ;
			return id[p];
		}
	return 0;
}
int num;
int main() {
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);
	num = read(), n = read(), m = read(), q = read();
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
		// if (10 <= num && num <= 14) {
		// 	int amx = - 1, bmn = 1e9 + 1;
		// 	for (int i=1; i<=n; i++) amx = max(amx, a[i]);
		// 	for (int i=1; i<=m; i++) bmn = min(bmn, b[i]);
		// 	putchar((amx < b[m] && a[n] < bmn) + '0');
		// 	continue;
		// }
		bool flag = 0;
		if (a[1] < b[1]) { for (int i=1; i<=max(n,m); i++) swap(a[i], b[i]); swap(n, m), flag = 1; }
		build(1, 1, m);
		int p = getnxt(1, a[1]);
		for (int i=2; i<=n; i++)
			if (a[i] > a[i-1]) p = getnxt(p, a[i]);
			else if (a[i] < a[i-1] && a[i] <= b[p]) if (! (p = getpre(p, a[i]))) break;
		putchar((p == m) + '0');
		if (flag) swap(n, m);
	}
}