#include <bits/stdc++.h>
using namespace std;

int c, n, m, q, gn, gm, rdx;

int x[500024], y[500024];

int Dx[500024], Dy[500024], Ix[500024], Iy[500024];

int* ga, * gb;

int arr[4096][4096];

inline bool search(int px, int py) {
	if (px == gn && py == gm) {
		return true;
	}
	if (px < 4096 && py < 4096) {
		if (arr[px][py] == rdx) {
			return false;
		}
		arr[px][py] = rdx;
	}
	if (px + 1 <= gn) if (ga[px + 1] < gb[py]) {
		if (search(px + 1, py)) {
			return true;
		}
	}
	if (py + 1 > gm) return false;
	return ga[px] < gb[py + 1] ? search(px, py + 1) : false;
}

inline bool ssolve(int* a, int* b) {
	if (a[1] >= b[1]) {
		return false;
	}
	ga = a;
	gb = b;
	return search(1, 1);
}

inline void solve() {
	gn = n;
	gm = m;
	if (ssolve(x, y)) {
		putchar('1');
		return;
	}
	gn = m;
	gm = n;
	if (ssolve(y, x)) {
		putchar('1');
		return;
	}
	putchar('0');
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d %d %d %d", &c, &n, &m, &q);
	rdx = q + 10;
	for (int i = 1; i <= n; i++) {
		scanf("%d", x + i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", y + i);
	}
	solve();
	int kX, kY, d, v;
	while (q--) {
		rdx = q + 1;
		scanf("%d %d", &kX, &kY);
		for (int i = 0; i < kX; i++) {
			scanf("%d %d", &d, &v);
			Dx[i] = d;
			Ix[i] = x[d];
			x[d] = v;
		}
		for (int i = 0; i < kY; i++) {
			scanf("%d %d", &d, &v);
			Dy[i] = d;
			Iy[i] = y[d];
			y[d] = v;
		}
		solve();
		for (int i = 0; i < kX; i++) {
			x[Dx[i]] = Ix[i];
		}
		for (int i = 0; i < kY; i++) {
			y[Dy[i]] = Iy[i];
		}
	}
	putchar('\n');
}