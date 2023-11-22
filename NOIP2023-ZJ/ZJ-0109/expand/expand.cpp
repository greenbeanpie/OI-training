#include <bits/stdc++.h>
#define ll long long
#define RI int
#define W while
#define CI const int
using namespace std;
CI N = 5e5; int c, n, m, q; bool ans[N + 5];
int main () {
	freopen ("expand.in", "r", stdin); freopen ("expand.out", "w", stdout);
	RI i, j; scanf ("%d%d%d%d", &c, &n, &m, &q);
	if (c == 1) {
		int a, b; scanf ("%d%d", &a, &b); if (a == b) ans[0] = 0; else ans[0] = 1;
		for (i = 1; i <= q; ++ i) {
			int c = a, d = b;
			int kx, ky; scanf ("%d%d", &kx, &ky);
			for (j = 1; j <= kx; ++ j) {int x, y; scanf ("%d%d", &x, &y); c = y;}
			for (j = 1; j <= ky; ++ j) {int x, y; scanf ("%d%d", &x, &y); d = y;}
			ans[i] = (c != d);
		} for (i = 0; i <= q; ++ i) printf ("%d", ans[i]); printf ("\n");
	} else {
		printf ("AWA");
	}
	return 0;
}