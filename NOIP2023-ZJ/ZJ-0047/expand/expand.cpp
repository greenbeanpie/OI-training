#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, m, q, a[N], b[N], x[N], y[N], c;
bool f[N][N];
inline int judge() {
	int pn = n, pm = m;
	if (x[1] > y[1]) swap(x, y), swap(pn, pm);
	if (x[pn] >= y[pm]) return 0;
	memset(f, 0, sizeof(f));
	f[1][1] = 1;
	for (int i = 1; i <= pn; i++)
		for (int j = 1; j <= pm; j++)
			if (f[i][j] && x[i] < y[j]) f[i][j + 1] = f[i + 1][j] = f[i + 1][j + 1] = 1;
	return f[pn][pm];
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	memcpy(x, a, sizeof(x)), memcpy(y, b, sizeof(y));
	cout << judge();
	while (q--) {
		int kx, ky;
		cin >> kx >> ky;
		memcpy(x, a, sizeof(x)), memcpy(y, b, sizeof(y));
		for (int j = 1; j <= kx; j++) {
			int oa, ob;
			cin >> oa >> ob, x[oa] = ob;
		}
		for (int j = 1; j <= ky; j++) {
			int oa, ob;
			cin >> oa >> ob, y[oa] = ob;
		}
		cout << judge();
	}
	return 0;
}
// g++ expand.cpp -o expand -fsanitize=undefined,address -g -O2 -std=c++14