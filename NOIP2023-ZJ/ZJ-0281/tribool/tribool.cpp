// You know I'm not alone...
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int c, T;
int n, m;
struct command {
	char op;
	int u, v;
};
vector<command> mp;
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
	int ans;
	vector<int> a;
	vector<int> b;
	int cnt;
	auto check() -> bool {
		b = a;
		for (int i = 0; i < m; ++i) {
			if (mp[i].op == '+' || mp[i].op == '-') {
				b[mp[i].u] = b[mp[i].v] * (mp[i].op == '+' ? 1 : -1);
			}
			else {
				b[mp[i].u] = mp[i].op == 'F' ? -1 : mp[i].op == 'T' ? 1 : 0;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
	void dfs(int dep) {
		if (dep > n) {
			if (check()) {
				ans = min(ans, cnt);
			}
			return;
		}
		a[dep] = -1;
		dfs(dep + 1);
		a[dep] = 1;
		dfs(dep + 1);
		a[dep] = 0;
		++cnt;
		dfs(dep + 1);
		--cnt;
	}
	void solve() override {
		ans = 0x3f3f3f3f;
		cnt = 0;
		a.clear();
		a.resize(n + 1);
		dfs(1);
		cout << ans << "\n";
	}
};
class subtask2 : public subtask {
public:
	vector<int> a;
	void solve() override {
		a.resize(n, 1);
		for (int i = 0; i < m; ++i) {
			a[mp[i].u] = mp[i].op == 'F' ? -1 : mp[i].op == 'T' ? 1 : 0;
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += a[i] == 0 ? 1 : 0;
		}
		cout << res << "\n";
	}
};
class subtask3 : public subtask {
public:
	vector<int> fa;
	auto find(int x) -> int {
		return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
	}
	void solve() override {
		fa.resize(n + 4);
		for (int i = 1; i <= n + 1; ++i) {
			fa[i] = i;
		}
		for (int i = 0; i < m; ++i) {
			if (mp[i].op == 'U') {
				fa[mp[i].u] = n + 1;
			}
			else {
				fa[mp[i].u] = find(mp[i].v);
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += find(i) == n + 1 ? 1 : 0;
		}
		cout << res << "\n";
	}
};
class subtask4 : public subtask {
public:
	void solve() override {
		cout << 0 << "\n";
	}
};
auto getSol() -> subtask* {
	if (c == 1 || c == 2) {
		return (subtask*)(new subtask1);
	}
	if (c == 3 || c == 4) {
		return (subtask*)(new subtask2);
	}
	if (c == 5 || c == 6) {
		return (subtask*)(new subtask3);
	}
	if (c == 7 || c == 8) {
		return (subtask*)(new subtask4);
	}
	return (subtask*)(new subtask0);
}
auto delSol(subtask* sub) {
	if (c == 1 || c == 2) {
		delete (subtask1*)(sub);
		return;
	}
	if (c == 3 || c == 4) {
		delete (subtask2*)(sub);
		return;
	}
	if (c == 5 || c == 6) {
		delete (subtask3*)(sub);
		return;
	}
	if (c == 7 || c == 8) {
		delete (subtask4*)(sub);
		return;
	}
	delete (subtask0*)(sub);
}
auto main() -> int {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	// freopen("tribool.log", "w", stderr);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> T;
	subtask* sub = getSol();
	while ((T--) != 0) {
		cin >> n >> m;
		mp.resize(m + 1);
		for (int i = 0; i < m; ++i) {
			cin >> mp[i].op;
			if (mp[i].op == '+' || mp[i].op == '-') {
				cin >> mp[i].u >> mp[i].v;
			}
			else {
				cin >> mp[i].u;
			}
		}
		sub->solve();
	}
	delSol(sub);
	return 0;
}
