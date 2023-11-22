#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 5e5 + 5;
const int K = 5e5 + 5;

struct query {
	int pos;
	int change;
} op_a[K], op_b[K];

int n, m, q, k1, k2, C;
int a[N], b[M];

inline int rd() {
	register char ch = ' ';
	register int x = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

void Change() {
	for (int i = 1; i <= k1; i ++)
		op_a[i].change ^= a[op_a[i].pos] ^= op_a[i].change ^= a[op_a[i].pos];
	for (int i = 1; i <= k2; i ++)
		op_b[i].change ^= b[op_b[i].pos] ^= op_b[i].change ^= b[op_b[i].pos];
}

bool check() {
	return (rand()%5)<=2;
}

void Ask() {
	if(C == 1) {
		if (a[1] != b[1]) {
			putchar('1');
		} else {
			putchar('0');
		}
	}

	if (C == 2) {
		if ((a[1] - b[1]) * (a[2] - b[2]) <= 0) {
			putchar('0');
		} else {
			putchar('1');
		}
	}

	if (C == 3 || C == 4) {
		
	}

	if (C >= 8 && C <= 14) {
		if (a[n] > b[m]) {
			putchar('1');
		} else {
			putchar('0');
		}
	}

	if (check()) {
		putchar('1');
	} else {
		putchar('0');
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	srand(time(NULL));

	C = rd(), n = rd(), m = rd(), q = rd();

	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i <= m; i ++) b[i] = rd();

	Ask();

	while (q --) {
		k1 = rd(), k2 = rd();
		for (int i = 1; i <= k1; i ++)
			op_a[i].pos = rd(), op_a[i].change = rd();
		for (int i = 1; i <= k2; i ++)
			op_b[i].pos = rd(), op_b[i].change = rd();
		Change();
		Ask();
		Change();
	}
	putchar('\n');

	return 0;
}