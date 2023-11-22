#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("tribool.in", "w", stdout);
	int tc = 7, T = 6, n = 10, m = 10;
	cout << tc << ' ' << T << endl;
	mt19937 rand(19260817);
	while (T--) {
		cout << n << ' ' << m << endl;
		for (int i = 1; i <= m; i++) {
			int opt = rand() % 2;
			int x = rand() % n + 1, y = rand() % n + 1;
			if (opt == 0) {
				cout << "+ " << x << ' ' << y << endl;
			} else {
				cout << "- " << x << ' ' << y << endl;
			}
		}
	}
	return 0;
}