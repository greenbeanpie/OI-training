// You know I'm not alone...
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int c, n, m, q;
vector<int> x, y;
class subtask {
public:
	virtual void solve() = 0;
};
class subtask0 : public subtask {
public:
	void solve() override {
	}
};
class subtask1 : public subtask {
public:
	void solve() override {
		cout << 1;
	}
};
class subtask2 : public subtask {
public:
	void solve() override {
		if (n == 1 && m == 1) {
			cout << 1;
			return;
		}
		if (n == 1) {
			cout << ((y[1] - x[1]) * (y[2] - x[1]) > 0 ? 1 : 0);
			return;
		}
		if (m == 1) {
			cout << ((x[1] - y[1]) * (x[2] - y[1]) > 0 ? 1 : 0);
			return;
		}
		cout << ((x[1] - y[1]) * (x[2] - y[2]) > 0 ? 1 : 0);
	}
};
class subtask3 : public subtask {
public:
	vector<int> a;
	bool res;
	void check() {
		for (int i = 1; i < n; ++i) {
			for (int j = a[i]; j <= a[i + 1]; ++j) {
				if ((x[i] - y[j]) * (x[1] - y[1]) <= 0) {
					return;
				}
			}
		}
		res = true;
	}
	void dfs(int dep, int lst) {
		if (dep > n) {
			check();
			return;
		}
		for (int i = lst; i <= m && !res; ++i) {
			a[dep] = i;
			dfs(dep + 1, i);
		}
	}
	void solve() override {
		bool flg = false;
		if (n > m) {
			swap(x, y);
			swap(n, m);
			flg = true;
		}
		res = false;
		a.resize(n + 1);
		a[1] = 1;
		dfs(2, 1);
		cout << res;
		if (flg) {
			swap(x, y); 
			swap(n, m);
		}
	}
};
class subtask6 : public subtask {
public:
	void solve() override {
		int pos1 = 1;
		int pos2 = 1;
		int lstMn = pos1;
		int lstMx = pos2;
		while (pos1 < n && pos2 < m) {
			if (x[pos1] > y[lstMx] && y[pos2] < x[lstMn]) {
				// cerr << pos1 << " " << x[pos1] << " <-> " 
				// 	<< lstMx << " " << y[lstMx] << "\n";
				cout << 0;
				return;
			}
			++pos1, ++pos2;
			lstMn = x[pos1] < x[lstMn] ? pos1 : lstMn;
			lstMx = y[pos2] > y[lstMx] ? pos2 : lstMx;
		}
		while (pos1 < n) {
			if (x[pos1] > y[m]) {
				cout << 0;
				return;
			}
			++pos1;
		}
		while (pos2 < m) {
			if (y[pos2] < x[n]) {
				cout << 0;
				return;
			}
			++pos2;
		}
		cout << 1;
	}
};
auto getSol() -> subtask* {
	if (c == 1) {
		return (subtask*)(new subtask1);
	}
	if (c == 2) {
		return (subtask*)(new subtask2);
	}
	if (3 <= c && c <= 4) {
		return (subtask*)(new subtask3);
	}
	if (8 <= c && c <= 14) {
		return (subtask*)(new subtask6);
	}
	return (subtask*)(new subtask0);
}
auto delSol(subtask* sub) {
	if (c == 1) {
		delete (subtask1*)(sub);
		return;
	}
	if (c == 2) {
		delete (subtask2*)(sub);
		return;
	}
	if (3 <= c && c <= 4) {
		delete (subtask3*)(sub);
		return;
	}
	if (8 <= c && c <= 14) {
		delete (subtask6*)(sub);
		return;
	}
	delete (subtask0*)(sub);
}
auto main() -> int {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	// freopen("expand.log", "w", stderr);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> q;
	x.resize(n + 1);
	y.resize(m + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> y[i];
	}
	// cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
	auto* sub = getSol();
	sub->solve();
	// cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
	while((q--) != 0) {
		int kx, ky;
		cin >> kx >> ky;
		for (int i = 0; i < kx; ++i) {
			int px, vx;
			cin >> px >> vx;
			x[px] = vx;
		}
		for (int i = 0; i < ky; ++i) {
			int py, vy;
			cin >> py >> vy;
			x[py] = vy;
		}
		sub->solve();
		// cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
	}
	delSol(sub);
	return 0;
}
