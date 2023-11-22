#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int op[N], val[N], x[N];
int T, n, m, ans;
unordered_set <int> un;
queue <int> de;
int read () {
	int f = 1, x = 0;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ '0');
		ch = getchar ();
	}
	return f * x;
}
namespace dsu {
	int n, fa[N << 1];
	void init (int n_) {
		n = n_;
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	stack <int> stk;
	int find (int x) {
		while (x != fa[x]) {
			stk.push (x);
			x = fa[x];
		}
		while (!stk.empty ()) {
			fa[stk.top ()] = x;
			stk.pop ();
		}
		return x;
	}
	void unionn (int u, int v) {
		int fu = find (u);
		int fv = find (v);
		fa[fu] = fv;
	}
}
int main () {
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	T = read ();
	T = read ();
	while (T --> 0) {
		n = read (), m = read ();
		for (int i = 1; i <= n; i++) {
			op[i] = 1;
			val[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			char ch = getchar ();
			int x, y;
			if (ch == '+' || ch == '-') {
				x = read (), y = read ();
				if (ch == '+') {
					op[x] = op[y];
					val[x] = val[y];
				} else {
					if (op[y] == 0) {
						op[x] = op[y];
						val[x] = (val[y] == 0? 0: 3 - val[y]);
					} else {
						op[x] = 3 - op[y];
						val[x] = val[y];
					}
				}
			} else {
				x = read ();
				int w;
				if (ch == 'T') {
					w = 1;
				} else if (ch == 'F') {
					w = 2;
				} else {
					w = 0;
				}
				op[x] = 0;
				val[x] = w;
			}
		}
		ans = 0;
		fill (x + 1, x + n + 1, 0);
		un = unordered_set <int> ();
		for (int i = 1; i <= n; i++) {
			if (op[i] == 0 || op[i] == 2 && val[i] == i) {
				if (op[i] == 0) {
					x[i] = val[i];
				}
				if (x[i] == 0) {
					ans++;
				}
			} else {
				un.insert (i);
			}
		}
		while (true) {
			int cnt = 0;
			for (auto i : un) {
				if (!un.count (val[i])) {
					if (op[i] == 1) {
						x[i] = x[val[i]];
					} else {
						x[i] = (x[val[i]] == 0? 0: 3 - x[val[i]]);
					}
					if (x[i] == 0) {
						ans++;
					}
					cnt++;
					de.push (i);
				}
			}
			while (!de.empty ()) {
				un.erase (de.front ());
				de.pop ();
			}
			if (cnt == 0) {
				break;
			}
		}
		dsu::init (n << 1);
		for (auto i : un) {
			if (op[i] == 1) {
				dsu::unionn (i, val[i]);
				dsu::unionn (i + n, val[i] + n);
			} else {
				dsu::unionn (i, val[i] + n);
				dsu::unionn (i + n, val[i]);
			}
		}
		for (auto i : un) {
			if (dsu::find (i) == dsu::find (i + n)) {
				ans++;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}