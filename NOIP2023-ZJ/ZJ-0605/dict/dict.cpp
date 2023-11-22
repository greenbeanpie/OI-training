#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3202;
int n, m;
int a[MAXN][MAXN];

int read() {
	int x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c ^ 48);
	return x;
}

int readanum() {
	char c = getchar();
	for (; c < 'a' || c > 'z'; c = getchar());
	return c - 96;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	n = read();
	m = read();
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
		a[i][j] = readanum();
	for (int i = 1; i <= n; ++i) {
		sort(a[i] + 1, a[i] + m + 1);
	}
	for (int k = 1; k <= n; ++k) {
		int flag = true;
		for (int i = 1; i <= n; ++i) if (i != k) {
			for (int j = 1; j <= m; ++j) {
				if (a[k][j] == a[i][m - j + 1]) continue;
				if (a[k][j] > a[i][m - j + 1]) flag = false;
				break;
			}
			if (!flag) break;
		}
		putchar(flag ? '1' : '0');
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}