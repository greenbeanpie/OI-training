#include <bits/stdc++.h>
using namespace std;


int c, t, n, m;
vector<int> fa;
vector<int> x;

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return (fa[x] = find(fa[x]));
}

void merge(int i, int j) {
	int fai = find(i);
	int faj = find(j);
	fa[fai] = faj;
}


int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	for (int i = 0; i < t; ++i) {
		int cnt = 0;
		cin >> n >> m;
		fa.resize(n * 2 + 1);
		x.resize(n + 1);
		
		for (int j = 1; j <= n; ++j) {
			x[j] = -1;
		}
		
		for (int j = 1; j <= 2 * n; ++j) {
			fa[j] = j;
		}
		for (int j = 0; j < m; ++j) {
			char v;
			int a, b;
			cin >> v;
			if (v == 'T' || v == 'F' || v == 'U') {
				cin >> a;
				if (v == 'T') {
					x[a] = 1;
				} else if (v == 'F') {
					x[a] = 2;
				} else {
					x[a] = 0;
				}
			} else if (v == '+') {
				cin >> a >> b;
				merge(a, b);
				merge(a + n, b + n);
			} else if (v == '-') {
				cin >> a >> b;
				merge(a, b + n);
				merge(a + n, b);
			}
		}
		if (c == 3 || c == 4) {
			for (int j = 1; j <= n; ++j) {
				if (x[j] == 0) {
					++cnt;
				}
			}
			cout << cnt << endl;
			continue;
		}
		for (int j = 1; j <= n; ++j) {
			if (find(fa[j]) == find(fa[j + n])) {
				x[j] = 0;
			}
		}
		for (int j = 1; j <= n; ++j) {
			int fj = find(fa[j]);
			if (fj > n) {
				fj -= n;
			}
			if (x[fj] == 0 || x[j] == 0) {
				x[fj] = x[j] = 0;
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (x[j] == 0) {
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
