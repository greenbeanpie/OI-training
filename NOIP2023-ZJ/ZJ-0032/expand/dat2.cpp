#include <bits/stdc++.h>
using namespace std;
int a[2333], b[2333];
int main() {
	freopen ("expand.in", "w", stdout);
	mt19937 R (random_device {} ());
	int n = R() % 5 + 1, m = R() % 5 + 1, q = 1000;
	cout << 10 << ' ' << n << ' ' << m << ' ' << q << endl;
	for (int i=1; i<=n+m; i++) printf ("0 "); puts ("");
	while (q --) {
		printf ("%d %d\n", n, m);
		T :
			for (int i=1; i<=n; i++) a[i] = R() % 30;
			for (int i=1; i<=m; i++) b[i] = R() % 30;
			for (int i=1; i<n; i++) if (a[i] < a[n]) swap(a[i], a[n]);
			for (int i=1; i<m; i++) if (b[i] > b[m]) swap(b[i], b[m]);
			if (a[1] >= b[1]) goto T;
		for (int i=1; i<=n; i++) printf ("%d %d\n", i, a[i]); puts ("");
		for (int i=1; i<=m; i++) printf ("%d %d\n", i, b[i]); puts ("");
	}
}