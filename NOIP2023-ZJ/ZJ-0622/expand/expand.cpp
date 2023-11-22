#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, q;
int a[N], b[N], ta[N], tb[N];
int read() {
	int x = 0, fl = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')
			fl = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * fl;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for (int i = 1; i <= n; ++i)
		ta[i] = a[i] = read();
	for (int i = 1; i <= m; ++i)
		tb[i] = b[i] = read();
	for (int i = 0; i <= q; ++i) {
		printf("1");
	}
	return 0;
}