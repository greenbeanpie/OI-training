#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int c, n, m, q;
int X[N], Y[N], x[N], y[N];
int kx, ky, p, v;

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> X[i]; x[i] = X[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> Y[i]; y[i] = Y[i];
	}
	if (c == 1) {
		if (x[1] - y[1] == 0) printf("0");
		else printf("1");
	}
	else if (c == 2) {
		if ((x[1] - y[1]) * (x[2] - y[2]) <= 0) printf("0");
		else printf("1");
	}
	else {
		bool flag = 0;
		if (x[1] == y[1] || x[n] == y[m]) {
			printf("0");
			flag = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (x[i] > y[i] && x[i + 1] < y[i + 1] || x[i] < y[i] && x[i + 1] > y[i + 1]) {
				printf("0");
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf("1");
		}
	}
	while (q--) {
		for (int i = 1; i <= n; i++) {
			x[i] = X[i];
		}
		for (int i = 1; i <= m; i++) {
			y[i] = Y[i];
		}
		cin >> kx >> ky;
		for (int i = 1; i <= kx; i++) {
			cin >> p >> v;
			x[p] = v;
		}
		for (int i = 1; i <= ky; i++) {
			cin >> p >> v;
			y[p] = v;
		}
		if (c == 1) {
			if (x[1] - y[1] == 0) printf("0");
			else printf("1");
		}
		else if (c == 2) {
			if ((x[1] - y[1]) * (x[2] - y[2]) <= 0) printf("0");
			else printf("1");
		}
		else {
			bool flag = 0;
			if (x[1] == y[1] || x[n] == y[m]) {
				printf("0");
				flag = 1;
			}
			for (int i = 1; i <= n; i++) {
				if (x[i] > y[i] && x[i + 1] < y[i + 1] || x[i] < y[i] && x[i + 1] > y[i + 1]) {
					printf("0");
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				printf("1");
			}
		}
	}	
	printf("\n");
	return 0;
}