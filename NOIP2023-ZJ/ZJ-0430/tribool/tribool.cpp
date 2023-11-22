#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

namespace solve1 {
	char a[14], b[14]; int n, m, Ans;
	struct _ {
		char v; int i, j;
	} op[14];
	char getinv(char c) {
		if (c == 'U') return c;
		if (c == 'T') return 'F';
		if (c == 'F') return 'T';
	}
	bool check() {
		for (int i = 1; i <= n; i++) b[i] = a[i];
		for (int i = 1; i <= m; i++) {
			if (op[i].v == '+') b[op[i].i] = b[op[i].j];
			else if (op[i].v == '-') b[op[i].i] = getinv(b[op[i].j]);
			else b[op[i].i] = op[i].v;
		}
		for (int i = 1; i <= n; i++) if (b[i] != a[i]) return false;
		return true;
	}
	void dfs(int now) {
		if (now == n + 1) {
			if (check()) {
				int res = 0;
				for (int i = 1; i <= n; i++) res += (b[i] == 'U');
				Ans = min(Ans, res);
			}
			return;
		}
		a[now] = 'T'; dfs(now + 1);
		a[now] = 'F'; dfs(now + 1);
		a[now] = 'U'; dfs(now + 1);
	}
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> op[i].v;
			if (op[i].v == '+' || op[i].v == '-') cin >> op[i].i >> op[i].j;
			else cin >> op[i].i;
		}
		Ans = INT_MAX;
		dfs(1);
		cout << Ans << endl;
		return;
	}
}

namespace solve2 {
	int n, m; char a[N];
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) a[i] = '#';
		for (int i = 1; i <= m; i++) {
			static char op; int w;
			cin >> op >> w;
			a[w] = op;
		}
		int res = 0;
		for (int i = 1; i <= n; i++) res += (a[i] == 'U');
		cout << res << endl;
	}
}

namespace solve3 {
	char a[N]; int n, m, deg[N], b[N];
	vector<int> G[N];
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			a[i] = '#'; deg[i] = 0;
			G[i].clear(); b[i] = i;
		}
		G[n + 1].clear(); deg[n + 1] = 0; a[n + 1] = 'U';
		for (int _ = 1; _ <= m; _++) {
			static char op; int i, j;
			cin >> op;
			if (op == 'U') {
				cin >> i;
				b[i] = n + 1;
			} else {
				cin >> i >> j;
				b[i] = b[j];
			}
		}
		for (int i = 1; i <= n; i++) {
			++deg[i]; G[b[i]].push_back(i);
		}
		queue<int> q;
		q.push(n + 1); int res = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int v : G[u]) {
				--deg[v]; if (!deg[v]) {
					res++; q.push(v);
				}
			}
		}
		cout << res << endl;
	}
}

namespace solve4 {
	char a[N], b[N]; int n, m, Ans;
	struct _ {
		char v; int i, j;
	} op[N];
	char getinv(char c) {
		if (c == 'U') return c;
		if (c == 'T') return 'F';
		if (c == 'F') return 'T';
	}
	int res;
	int check() {
		for (int i = 1; i <= n; i++) b[i] = a[i];
		for (int i = 1; i <= m; i++) {
			if (op[i].v == '+') b[op[i].i] = b[op[i].j];
			else if (op[i].v == '-') b[op[i].i] = getinv(b[op[i].j]);
			else b[op[i].i] = op[i].v;
		}
		res = 0;
		for (int i = 1; i <= n; i++) { if (b[i] != a[i]) return -1; res += (b[i] == 'U'); }
		return res;
	}
	void SA() { // 假的 SA
		for (int i = 1; i <= 5000; i++) {
			int x = rand() % 3, p = rand() % n + 1;
			char w = a[p];
			if (x == 0) a[p] = 'T';
			if (x == 1) a[p] = 'F';
			if (x == 2) a[p] = 'U';
			if (check() != -1)
				if (res < Ans) Ans = res;
				else goto End;
			else {
				End:;
				if (rand() % 5 <= 2) a[p] = w;
			}
		}
	}
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> op[i].v;
			if (op[i].v == '+' || op[i].v == '-') cin >> op[i].i >> op[i].j;
			else cin >> op[i].i;
		}
		Ans = n;
		for (int i = 1; i <= 25; i++) {
			for (int i = 1; i <= n; i++) a[i] = 'U';
			SA();
		}
		cout << Ans << endl;
	}
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		if (c == 1 || c == 2) solve1::main();
		else if (c == 3 || c == 4) solve2::main();
		else if (c == 5 || c == 6) solve3::main();
		else solve4::main();
	}
}
