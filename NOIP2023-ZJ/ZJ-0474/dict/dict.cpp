#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 5;
const int M = 3000 + 5;

int n, m;
int Max[N], Min[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	cin >> n >> m;
	getchar();
	
	for (int i = 1; i <= n; i ++) {
		Max[i] = 0;
		Min[i] = N << 1;
		for (int j = 1; j <= m; j ++) {
			char ch = getchar();
			Max[i] = max(Max[i], ch - 'a');
			Min[i] = min(Min[i], ch - 'a');
		}
		getchar();
	}

	if (n == 1) {
		putchar('1');
		return 0;
	}

	for (int i = 1; i <= n; i ++) {
		bool flag = true;
		for (int j = 1; j <= n; j ++) {
			if (j == i) continue;
			if (Max[j] <= Min[i]) {
				putchar('0');
				flag = false;
				break;
			}
		}
		if (flag) {
			putchar('1');
		}
	}

	putchar('\n');

	return 0;
}