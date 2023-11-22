#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct OPER {
	char op;
	int a, b;
} O[N];

int init[N]; // TFU: 123
int bkup[N];

int n, m;
int ans = 2147483647, cur; // cur: U

void dfs(int);
bool check();

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	int c, t;
	scanf("%d%d", &c, &t);
	
	if (c <= 2) {
		while (t--) {
			ans = 2147483647;
			cur = 0;
			/* init . . . */
			scanf("%d%d", &n, &m);
			for (int i = 1; i <= m; i++) {
				do {
					O[i].op = getchar();
				} while (O[i].op != 'T' && O[i].op != 'F' && O[i].op != 'U' &&
						 O[i].op != '+' && O[i].op != '-');
				if (isalpha(O[i].op)) {
					scanf("%d", &O[i].a);
				} else {
					scanf("%d%d", &O[i].a, &O[i].b);
				}
			}
			dfs(0);
			printf("%d\n", ans);
		}
	} else if (c <= 4) {
		while (t--) {
			ans = 0;
			/* init . . . */
			scanf("%d%d", &n, &m);
			for (int i = 1; i <= m; i++) {
				do {
					O[i].op = getchar();
				} while (O[i].op != 'T' && O[i].op != 'F' && O[i].op != 'U');
				scanf("%d", &O[i].a);
				if (O[i].op == 'T') {
					init[O[i].a] = 1;
				} else if (O[i].op == 'F') {
					init[O[i].a] = 2;
				} else if (O[i].op == 'U') {
					init[O[i].a] = 3;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (init[i] == 3) {
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	} else if (c <= 6) {
		while (t--) {
			ans = 0;
			/* init . . . */
			scanf("%d%d", &n, &m);
			for (int i = 1; i <= m; i++) {
				do {
					O[i].op = getchar();
				} while (O[i].op != 'U' && O[i].op != '+');
				if (isalpha(O[i].op)) {
					scanf("%d", &O[i].a);
					ans++;
				} else {
					scanf("%d%d", &O[i].a, &O[i].b);
				}
			}
			printf("%d\n", ans);
		}
	} else {
		while (t--) {
			printf("%d\n", 0);
		}
	}
	return 0;
}

void dfs(int depth) {
	if (depth == n) {
		if (check()) {
			ans = min(ans, cur);
		}
		return;
	}
	init[depth + 1] = 1;
	dfs(depth + 1);
	init[depth + 1] = 2;
	dfs(depth + 1);
	init[depth + 1] = 3;
	cur++;
	dfs(depth + 1);
	init[depth + 1] = 0;
	cur--;
}

bool check() {
	for (int i = 1; i <= n; i++) {
		bkup[i] = init[i];
	}
	for (int i = 1; i <= m; i++) {
		if (O[i].op == 'T') {
			bkup[O[i].a] = 1;
		} else if (O[i].op == 'F') {
			bkup[O[i].a] = 2;
		} else if (O[i].op == 'U') {
			bkup[O[i].a] = 3;
		} else if (O[i].op == '+') {
			bkup[O[i].a] = bkup[O[i].b];
		} else if (O[i].op == '-') {
			if (bkup[O[i].b] == 1) {
				bkup[O[i].a] = 2;
			} else if (bkup[O[i].b] == 2) {
				bkup[O[i].a] = 1;
			} else {
				bkup[O[i].a] = 3;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (bkup[i] != init[i]) {
			return 0;
		}
	}
	return 1;
}