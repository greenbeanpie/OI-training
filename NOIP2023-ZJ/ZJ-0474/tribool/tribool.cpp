#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
int tong[N];
int wq[30];
int vis[N];

inline int rd() {
	register char ch = ' ';
	register int x = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

void dfs(int x) {
	if(vis[x] == 1) return;
	if (abs(a[x]) > 1e5) return;
	vis[x] = 1;
	dfs(abs(a[x]));
	a[x] = (a[x] / abs(a[x])) * a[abs(a[x])];
	vis[x] = 0;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	wq['T' - 'A'] = 100001;
	wq['F' - 'A'] = 100002;
	wq['U' - 'A'] = 100003;
	int C, T;
	for (cin >> C >> T; T; T --) {
		memset(tong, 0, sizeof(tong));
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			a[i] = i;
		}
		for (int i = 1; i <= m; i ++) {
			char op;
			cin >> op;
			if (op == 'T' || op == 'F' || op == 'U') {
				int x;
				x = rd();
				a[x] = wq[op - 'A'];
			}
			if (op == '+') {
				int x = rd(), y = rd();
				a[x] = a[y];
			}
			if (op == '-') {
				int x = rd(), y = rd();
				a[x] = -a[y];
			}
		}

		for (int i = 1; i <= n; i ++) {
			b[i] = a[i];
		}

		for (int i = 1; i <= n; i ++) {
			if (abs(a[i]) > 1e5) continue;
			dfs(i);
		}

		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (abs(a[i]) == 1e5 + 3) {
				ans ++;
			}
			if (a[i] == -b[i] || a[i] == -i || b[i] == -i) {
				tong[abs(a[i])] = 1;
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (tong[abs(a[i])] == 1) {
				ans ++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}