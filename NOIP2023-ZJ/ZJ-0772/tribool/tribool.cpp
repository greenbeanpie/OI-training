#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c, T;
int fl[N], fl1[N];
char v[N];
int I1[N], J1[N], I2[N], J2[N], I[N], cnt[N];
int n, m, ans;
bool check() {
	for (int i = 1; i <= n; ++i) {
		fl1[i] = fl[i];
	}
	for (int i = 1; i <= m; ++i) {
		if (cnt[i] == 1) {
			if (v[i] == 'T') {
				fl1[I[i]] = 1;
			}
			if (v[i] == 'F') {
				fl1[I[i]] = 2;
			}
			if (v[i] == 'U') {
				fl1[I[i]] = 0;
			}
		}
		if (cnt[i] == 2) {
			fl1[I1[i]] = fl1[J1[i]];
		}
		if (cnt[i] == 3) {
			if (fl1[J2[i]] == 0) {
				fl1[I2[i]] = 0;
			} else {
				if (fl1[J2[i]] == 1) {
					fl1[I2[i]] = 2;
				} else {
					if (fl1[J2[i]] == 2) {
						fl1[I2[i]] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (fl[i] != fl1[i]) {
			return 0;
		}
	}
	return 1;
}
void dfs(int x, int res) {
	if (res > ans) {
		return;
	}
	if (x == n + 1) {
		if (check()) {
			ans = min(ans, res);
			if (T == 0 && ans == 3) {
				for (int i = 1; i <= n; ++i) {
					cout << fl[i];
				}
				cout << "\n";
			}
		}
		return;
	}
	fl[x] = 1;
	dfs(x + 1, res);
	fl[x] = 2;
	dfs(x + 1, res);
	fl[x] = 0;
	dfs(x + 1, res + 1);
}
void work() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		char ch;
		cin >> ch;
		if (ch == '-') {
			cnt[i] = 3;
			cin >> I2[i] >> J2[i];
		}
		if (ch == '+') {
			cnt[i] = 2;
			cin >> I1[i] >> J1[i];
		}
		if (ch == 'T' || ch == 'U' || ch == 'F') {
			cnt[i] = 1;
			v[i] = ch;
			cin >> I[i];
		}
	}
	ans = 1e9;
	dfs(1, 0);
	cout << ans << "\n";
}
int sy[N];
void work1() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		sy[i] = 3;
	}
	for (int i = 1; i <= m; ++i) {
		char ch;
		cin >> ch;
		int k;
		cin >> k;
		if (ch == 'T') {
			sy[k] = 1;
		}
		if (ch == 'F') {
			sy[k] = 2;
		}
		if (ch == 'U') {
			sy[k] = 0;
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (sy[i] == 0) {
			ret++;
		}
	}
	cout << ret << "\n";
}
void work2() {
	cin >> n >> m;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		sy[i] = 3;
	}
	for (int i = 1; i <= m; ++i) {
		char ch;
		cin >> ch;
		if (ch == 'U') {
			cnt[i] = 0;
			cin >> I[i];
			sy[I[i]] = 0;
		}
		if (ch == '+') {
			cnt[i] = 1;
			cin >> I1[i] >> J1[i];
			sy[I1[i]] = sy[J1[i]];
		}
	}
	for (int i = m; i >= 1; --i) {
		if (cnt[i] == 0) {
			sy[I[i]] = 0;
		}
		if (cnt[i] == 1) {
			sy[J1[i]] = sy[I1[i]];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (sy[i] == 0) {
			res++;
		}
	}
	cout << res << "\n";
}
signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0);
	cin >> c >> T;
	if (c == 1 || c == 2) {
		while (T--) {
			work();
		}
	}
	if (c == 3 || c == 4) {
		while (T--) {
			work1();
		}
	}
	if (c == 5 || c == 6) {
		while (T--) {
			work2();
		}
	}
	return 0;
}


// grade : 40


// I don't know what I can do.
// I don't know where I can go.
// And I don't know why I can be here.
// I just know I'm a loser, not a winner.
// I hate myself.
