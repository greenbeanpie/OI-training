#include <bits/stdc++.h>
#define F(i, a, b) for (int i = a; i <= (b); i++)
#define D(i, a, b) for (int i = a; i >= (b); i--)
using namespace std;

const int N = 1e5 + 5;
struct opt {
	char c;
	int x, y;
} op[N];
int n, m, fa[N], d[N], to[N][2];
char res[N];
vector<pair<int, int>> e[N];

int find(int x) {
	if (fa[x] == x) return x;
	int fx = fa[x];
	fa[x] = find(fa[x]);
	d[x] ^= d[fx];
	return fa[x];
}

void solve() {
	cin >> n >> m;
	F(i, 1, n) to[i][0] = to[i][1] = -1, res[i] = ' ';
	F(i, 1, n) vector<pair<int, int>>().swap(e[i]);
	F(i, 1, m) {
		cin >> op[i].c;
		if (op[i].c == '+' || op[i].c == '-') {
			cin >> op[i].x >> op[i].y;
		} else {
			cin >> op[i].x;
		}
	}
	D(i, m, 1) {
		if (!~to[op[i].x][0]) {
			if (op[i].c != '+' && op[i].c != '-') {
				to[op[i].x][0] = i;
				to[op[i].x][1] = 2;
				res[op[i].x] = op[i].c;
			} else {
				to[op[i].x][0] = op[i].y;
				to[op[i].x][1] = op[i].c == '+';
				e[op[i].y].emplace_back(op[i].x, op[i].c == '-');
			}
		}
	}
	queue<int> q;
	F(i, 1, n) if (to[i][0] == i) {
		q.emplace(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : e[cur]) {
			int y = i.first, w = i.second;
			if (res[cur] == 'U') {
				res[y] = 'U';
			} else {
				if ((res[cur] == 'T') ^ w) {
					res[y] = 'F';
				} else {
					res[y] = 'T';
				}
			}
			q.emplace(y);
		}
	}
	int ans = n;
	F(i, 1, n) if (to[i][0] == -1 || res[i] != 'U') ans--;
	cout << ans << '\n';
}

namespace sol1 {
	char res[N];
	void main() {
		cin >> n >> m;
		F(i, 1, n) res[i] = ' ';
		F(i, 1, m) {
			cin >> op[i].c >> op[i].x;
			res[op[i].x] = op[i].c;
		}
		int ans = 0;
		F(i, 1, n) if (res[i] == 'U') ans++;
		cout << ans << '\n';
	}
}

namespace sol2 {
	void main() {
		cin >> n >> m;
		F(i, 1, m) {
			cin >> op[i].c;
			if (op[i].c == '+' || op[i].c == '-') {
				cin >> op[i].x >> op[i].y;
			} else {
				cin >> op[i].x;
			}
		}
		F(i, 1, n) fa[i] = i, d[i] = 0, res[i] = ' ';
		F(i, 1, m) {
			int fx = find(op[i].x), fy = find(op[i].y);
			if (op[i].c == '+') {
				if (fx == fy) {
					if (d[op[i].x] != d[op[i].y]) {
						res[fy] = 'U';
					}
				} else {
					if (res[fx] == 'U' || res[fy] == 'U') {
						res[fy] = 'U';
					}
					fa[fx] = fy;
					d[fx] = 0;
				}
			} else if (op[i].c == '-') {
				int fx = find(op[i].x), fy = find(op[i].y);
				if (fx == fy) {
					if (d[op[i].x] == d[op[i].y]) {
						res[fy] = 'U';
					}
				} else {
					if (res[fx] == 'U' || res[fy] == 'U') {
						res[fy] = 'U';
					}
					fa[fx] = fy;
					d[fx] = 1;
				}
			}
		}
		int ans = 0;
		F(i, 1, n) if (res[find(i)] == 'U') ans++;
		cout << ans << '\n';
	}
}

namespace sol3 {
	void main() {
		cin >> n >> m;
		F(i, 1, m) {
			cin >> op[i].c;
			if (op[i].c == 'U') {
				cin >> op[i].x;
			} else {
				cin >> op[i].x >> op[i].y;
			}
		}
		F(i, m, 1) {
			if (!fa[op[i].x]) {
				fa[op[i].x] = op[i].y;
			}
		}
	}
}

signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		if (c == 3 || c == 4) {
			sol1::main();
		} else if (c == 5 || c == 6) {
			sol3::main();
		} else if (c == 7 || c == 8) {
			sol2::main();
		} else {
			solve();
		}
	}
	return 0;
}
