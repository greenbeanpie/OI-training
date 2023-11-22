#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
	std::vector<int> fa, siz;
	int qwq;
	
	DSU() {}
	DSU(int rick) : fa(rick + 1), siz(rick + 1, 1) {
		std::iota(fa.begin(), fa.end(), 0);
		qwq = rick;
	}
	
	int find (int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge (int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return ;
		siz[x] += siz[y];
		fa[y] = x;
		return ;
	}
	int quesize(int x) {
		return siz[find(x)];
	}
	bool same(int x, int y) {
		return (find(x) == find(y));
	}
};

struct pos {
	bool flag_ok;
	int what; // 1 -> T, 2 -> U, 3 -> F
	int syzorz; // 1 -> +, 2 -> -
	int which;
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<pos> a(n + 5);
	for (int i = 1; i <= n; i++) {
		a[i].flag_ok = false;
		a[i].what = 0;
		a[i].syzorz = 1;
		a[i].which = i;
	}
	
	for (int i = 0; i < m; i++) {
		std::string opt;
		int x, y;
		std::cin >> opt;
		
		if (opt == "T") {
			std::cin >> x;
			a[x].flag_ok = true;
			a[x].what = 1;
		} else if (opt == "U") {
			std::cin >> x;
			a[x].flag_ok = true;
			a[x].what = 2;
		} else if (opt == "F") {
			std::cin >> x;
			a[x].flag_ok = true;
			a[x].what = 3;
		} else if (opt == "+") {
			std::cin >> x >> y;
			a[x] = a[y];
		} else if (opt == "-") {
			std::cin >> x >> y;
			a[x] = a[y];
			if(a[x].flag_ok) {
				a[x].what = 4 - a[x].what;
			} else {
				a[x].syzorz = 3 - a[x].syzorz;
			}
		}
	}
	
	DSU qwq(n + 1), girl(2 * n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i].flag_ok == false) {
			qwq.merge(a[i].which, i);
			
			if (a[i].syzorz == 1) {
				girl.merge(i, a[i].which);
				girl.merge(i + n, a[i].which + n);
			} else if (a[i].syzorz == 2) {
				girl.merge(i, a[i].which + n);
				girl.merge(i + n, a[i].which);
			}
		}
	}
	
	int ans = 0;
	std::vector<int> tag(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		if (girl.same(i, i + n)) {
			if (tag[qwq.find(i)] == 0) {
				tag[qwq.find(i)] = 1;
				ans += qwq.quesize(i);
			}
		}
		if (a[i].flag_ok and a[i].what == 2 and tag[qwq.find(i)] == 0) {
			tag[qwq.find(i)] = 1;
			ans += qwq.quesize(i);
		}
	}
	
	std::cout << ans << std::endl;
	// Can you tell me why it didn't work?
	return ;
} 

signed main() {
	
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	
	std::cin.tie(0); std::cout.tie(0);
	
	int T, c;
	std::cin >> c >> T;
	
	while (T--) {
		solve();
	}
	   
    return 0;
}
