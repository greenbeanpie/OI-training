#include <bits/stdc++.h>
using namespace std;

namespace S1 {
	int n, m;
	int a[15], b[15], ans;
	int op[15], p1[15], p2[15];
	void ck() {
		for (int i = 1; i <= n; ++i) b[i] = a[i];
		for (int i = 1; i <= m; ++i) {
			if (op[i] == 1)
				b[p1[i]] = -b[p2[i]];
			if (op[i] == 2)
				b[p1[i]] = b[p2[i]];
			if (op[i] == 3)
				b[p1[i]] = p2[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) return;
			cnt += (a[i] == 0);
		}
		ans = min(ans, cnt);
	}
	void dfs(int x) {
		if (x > n) return ck();
		a[x] = 0;
		dfs(x + 1);
		a[x] = -1;
		dfs(x + 1);
		a[x] = 1;
		dfs(x + 1);
	}
	void main() {
		scanf("%d%d", &n, &m);
		ans = n;
		char c;
		for (int i = 1; i <= m; ++i) {
			do c = getchar(); while (c != '-' && c != '+' && !isalpha(c));
			if (c == '-') op[i] = 1;
			if (c == '+') op[i] = 2;
			if (c == 'T') op[i] = 3, p2[i] = 1;
			if (c == 'F') op[i] = 3, p2[i] = -1;
			if (c == 'U') op[i] = 3, p2[i] = 0;
			scanf("%d", p1 + i);
			if (op[i] < 3) scanf("%d", p2 + i);
		}
		dfs(1);
		printf("%d\n", ans);
	}
}

namespace S2 {
	const int N = 1e5 + 5;
	int a[N], n, m;
	
	void main() {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) a[i] = 2;
		char c; int p;
		for (int i = 1; i <= m; ++i) {
			do c = getchar(); while (!isalpha(c));
			scanf("%d", &p);
			if (c == 'T') a[p] = 1;
			if (c == 'F') a[p] = -1;
			if (c == 'U') a[p] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += (a[i] == 0);
		printf("%d\n", ans);
	}
}

namespace S3 {
	const int N = 1e5 + 5;
	int a[N], f[N], d[N], n, m;
	int find(int x) {
		return x == f[x] ? x : f[x] = find(f[x]);
	}
	vector<int> e[N];
	queue<int> q;
	void main() {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) a[i] = 0, f[i] = i, d[i] = 0, e[i].clear();
		char c; int x, y;
		for (int i = 1; i <= m; ++i) {
			do c = getchar(); while (c != '+' && !isalpha(c));
			if (c == '+') {
				scanf("%d%d", &x, &y);
				if (!a[y])
					f[x] = y, a[x] = 0;
				else 
					f[x] = x, a[x] = 1;
			} else scanf("%d", &x), f[x] = x, a[x] = 1;
		}
		for (int i = 1; i <= n; ++i) 
			if (f[i] != i) ++d[i], e[f[i]].push_back(i);
		for (int i = 1; i <= n; ++i) if (!d[i]) q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : e[u]) {
				--d[v], a[v] |= a[u];
				if (!d[v]) q.push(v);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += a[i];
		printf("%d\n", ans);
	}
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while (T--) {
		if (c == 3 || c == 4) S2::main();
		else if (c == 5 || c ==6) S3::main();
		else S1::main();
	}
	return 0;
}