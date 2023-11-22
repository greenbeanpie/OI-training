// You know I'm not alone...
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int c, T;
int n, m, k, d;
struct node {
	int x, y, z;
};
vector<node> a;
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
	vector<bool> tmp;
	vector<pair<int, int>> t;
	int ans;
	void check() {
		int cnt = 0;
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			cnt = tmp[i] ? cnt + 1 : 0;
			res -= tmp[i] ? d : 0;
			if (cnt > k) {
				return;
			}
			if (cnt >= t[i].first) {
				res += t[i].second;
			}
		}
		ans = max(ans, res);
	}
	void dfs(int dep) {
		if (dep > n) {
			check();
			return;
		}
		tmp[dep] = false;
		dfs(dep + 1);
		tmp[dep] = true;
		dfs(dep + 1);
	}
	void solve() override {
		t.clear();
		t.resize(n + 1, {0x3f3f3f3f, 0});
		tmp.resize(n + 1);
		ans = 0;
		for (int i = 1; i <= m; ++i) {
			t[a[i].x] = {a[i].y, a[i].z};
		}
		dfs(1);
		cout << ans << "\n";
	}
};
auto getSol() -> subtask* {
	if (c == 1) {
		return (subtask*)(new subtask1);
	}
	return (subtask*)(new subtask0);
}
auto delSol(subtask* sub) {
	if (c == 1) {
		delete (subtask1*)(sub);
		return;
	}
	delete (subtask0*)(sub);
}
auto main() -> int {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	// freopen("run.log", "w", stderr);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> T;
	auto *sub = getSol();
	while ((T--) != 0) {
		cin >> n >> m >> k >> d;
		a.resize(m + 1);
		for (int i = 1; i <= m; ++i) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sub->solve();
	}
	delSol(sub);
	return 0;
}
