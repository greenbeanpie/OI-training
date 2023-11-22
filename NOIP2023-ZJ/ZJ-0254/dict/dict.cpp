#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m;
char a[N][N], b[N][N], c1[N], c2[N];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; ++i) stable_sort(a[i] + 1, a[i] + m + 1);
	for (int i = 1; i <= m; ++i) c1[i] = c2[i] = 'z';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) b[i][j] = a[i][j];
		reverse(b[i] + 1, b[i] + m + 1);
		if (strcmp(c1 + 1, b[i] + 1) > 0) {
			for (int j = 1; j <= m; ++j) c2[j] = c1[j];
			for (int j = 1; j <= m; ++j) c1[j] = b[i][j];
		}
		else if (strcmp(c2 + 1, b[i] + 1) > 0)
			for (int j = 1; j <= m; ++j) c2[j] = b[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		char *tmp;
		if (strcmp(c1 + 1, b[i] + 1) == 0) tmp = c2 + 1;
		else tmp = c1 + 1;
		if (strcmp(tmp, a[i] + 1) > 0) putchar('1');
		else putchar('0');
	}
}
