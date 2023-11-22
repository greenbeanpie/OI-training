#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("expand.in", "w", stdout);
	mt19937 R (random_device {} ());
	int n = R() % 10 + 1, m = R() % 10 + 1, q = 1000;
	cout << 0 << ' ' << n << ' ' << m << ' ' << q << endl;
	for (int i=1; i<=n+m; i++) printf ("0 "); puts ("");
	while (q --) {
		printf ("%d %d\n", n, m);
		for (int i=1; i<=n; i++) printf ("%d %d\n", i, R() % 30);
		for (int i=1; i<=m; i++) printf ("%d %d\n", i, R() % 30);
	}
}