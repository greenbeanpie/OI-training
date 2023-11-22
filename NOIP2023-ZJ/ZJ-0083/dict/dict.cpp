#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, m, p[N], q[N];
string s;

inline bool check(int i) {
	for (int j = 1; j <= n; ++j) {
		if (j == i) {
			continue;
		}
		if (p[i] >= q[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		p[i] = 25, q[i] = 0;
		for (int j = 0; j < m; ++j) {
			int v = s[j] - 'a';
			p[i] = min(p[i], v);
			q[i] = max(q[i], v);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << check(i);
	}
	return 0;
}
