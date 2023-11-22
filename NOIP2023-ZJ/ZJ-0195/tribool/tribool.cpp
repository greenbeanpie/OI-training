// Think twice, code once.
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int type, T, n, m, val[100005], f[200005], cnt[200005];
struct dsu {
	int fa[200005];

	void clear() {for (int i = 0; i < 200005; i++) fa[i] = i; return ;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void merge(int x, int y) {fa[find(x)] = find(y); return ;}
	int query(int x, int y) {return find(x) == find(y);}
} d;

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> type >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) val[i] = i;
		while (m--) {
			char op;
			cin >> op;
			if (op == 'T') {
				int x;
				cin >> x;
				val[x] = n + 1;
			} else if (op == 'F') {
				int x;
				cin >> x;
				val[x] = 2 * n + 2;
			} else if (op == 'U') {
				int x;
				cin >> x;
				val[x] = 0;
			} else if (op == '+') {
				int x, y;
				cin >> x >> y;
				// cout << "+ " << x << ' ' << y << '\n';
				val[x] = val[y];
			} else {
				int x, y;
				cin >> x >> y;
				// cout << "- " << x << ' ' << y << '\n';
				if (!val[y]) val[x] = 0;
				else if (val[y] <= n + 1) val[x] = n + 1 + val[y];
				else val[x] = val[y] - n - 1;
			}
		}
		d.clear();
		for (int i = 1; i <= n; i++) {
			d.merge(i, val[i]);
			if (!val[i]) d.merge(n + 1 + i, 0);
			else if (val[i] <= n + 1) d.merge(n + 1 + i, n + 1 + val[i]);
			else d.merge(n + 1 + i, val[i] - n - 1);
		}
		// eprintf("%d\n", d.query(3, n + 1 + 3));
		memset(f, 0, sizeof(f));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			if (d.query(0, i) || d.query(i, n + 1 + i) || d.query(0, n + 1 + i))
				f[d.find(i)] = f[d.find(n + 1 + i)] = 1;
			cnt[d.find(i)]++;
			cnt[d.find(n + 1 + i)]++;
		}
		int ans = 0;
		for (int i = 0; i <= 2 * n + 2; i++) ans += f[i] * cnt[i];
		cout << ans / 2 << '\n';
		// return 0;
	}
	return 0;
}