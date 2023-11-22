#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int id;
namespace sub2 {
	int T, n, m, a[N], b[N];
	void work () {
		bool ok1 = true, ok2 = true;
		if (n < m) {
			for (int i = 1; i <= n; i++) {
				if (a[i] < b[i]) {
					ok1 = false;
				}
			}
			for (int i = n + 1; i <= m; i++) {
				if (a[n] < b[i]) {
					ok1 = false;
				}
			}
			for (int i = m - n + 1; i <= m; i++) {
				if (a[i] > b[i]) {
					ok2 = false;
				}
			}
			for (int i = 1; i <= m - n; i++) {
				if (a[m - n + 1] > b[i]) {
					ok2 = false;
				}
			}
		} else {
			for (int i = n - m + 1; i <= n; i++) {
				if (a[i] < b[i]) {
					ok1 = false;
				}
			}
			for (int i = 1; i <= n - m; i++) {
				if (a[i] < b[n - m + 1]) {
					ok1 = false;
				}
			}
			for (int i = 1; i <= m; i++) {
				if (a[i] > b[i]) {
					ok2 = false;
				}
			}
			for (int i = m + 1; i <= n; i++) {
				if (a[i] > b[m]) {
					ok2 = false;
				}
			}
		}
		printf ("%d", ok1 || ok2);
	}
	void main () {
		scanf ("%d%d%d", &n, &m, &T);
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &a[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf ("%d", &b[i]);
		}
		work ();
		while (T --> 0) {
			int kx, ky, p, x;
			scanf ("%d%d", &kx, &ky);
			for (int i = 1; i <= kx; i++) {
				scanf ("%d%d", &p, &x);
				a[p] = x;
			}
			for (int i = 1; i <= ky; i++) {
				scanf ("%d%d", &p, &x);
				b[p] = x;
			}
			work ();
		}
		printf ("\n");
	}
}
int main () {
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);
	scanf ("%d", &id);
	sub2::main ();
	return 0;
}