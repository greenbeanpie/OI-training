#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, a[N], b[N];
bool check() {
	if (n == 1) return a[1] != b[1];
	if (n == 2) return (a[1] - b[1]) * (a[2] - b[2]) > 0;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int qcnt;	
	cin >> c >> n >> m >> qcnt;
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", b + i);
	string ans = "";
	ans += check() ? "1" : "0";
	while (qcnt--) {
		int kx, ky;
		scanf("%d%d", &kx, &ky);
		for (int i = 1; i <= kx; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[x] = y;
		}
		for (int i = 1; i <= ky; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			b[x] = y;
		}
		ans += check() ? "1" : "0";
	}
	cout << ans << endl;
}
