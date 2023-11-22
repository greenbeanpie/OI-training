#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 5;
const int M = 1e5 + 5;

struct node {
	int l, r, v;
	friend bool operator < (node x, node y) {
		return (x.l == y.l) ? (x.r < y.r) : (x.l < y.l);
	}
} task[M];

int C, T;
int n, m, k, d, tot;

inline int rd() {
	register char ch = ' ';
	register int x = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	for (C = rd(), T = rd(); T; T --) {
		n = rd(), m = rd(), k = rd(), d = rd();
		for (int i = 1; i <= m; i ++) {
			tot ++;
			task[tot].r = rd();
			task[tot].l = task[i].r - rd() + 1;
			task[tot].v = rd();
			tot += ((task[i].r - task[i].l + 1) <= k) ? 0 : -1;
		}
		sort(task + 1, task + tot + 1);
		m = tot;
	}
}