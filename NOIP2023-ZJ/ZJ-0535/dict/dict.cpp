#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
string a[maxn], b[maxn];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sort(a[i].begin(), a[i].end());
		for (int j = 0; j < m; j++) {
			b[i].push_back(a[i][m - j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		bool f = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[i] > b[j]) {
				f = 0;
				break;
			}
		}
		if (f) cout << 1;
		else cout << 0;
	}
	return 0;
}