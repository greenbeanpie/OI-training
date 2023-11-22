#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
const int N = 1e5 + 5;
int a[N], c[N], fa[N << 1], Ans[N];
char b[N];
int Test_case, n, m, ans;
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
void Solve() {
	n = read(); m = read(); ans = 0;
	for (int i = 1; i <= n; i++) a[i] = i, c[i] = 0, b[i] = ' ';
	for (int i = 1; i <= n * 2; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) Ans[i] = 0;
	for (int i = 1; i <= m; i++) {
		char ch[5]; scanf("%s", ch);
		if (ch[0] == '+') {
			int x = read(), y = read();
			a[x] = a[y];
			c[x] = c[y];
			b[x] = b[y];
		}
		else if (ch[0] == '-') {
			int x = read(), y = read();
			a[x] = a[y];
			c[x] = c[y] ^ 1;
			if (b[y] == 'T') b[x] = 'F';
			else if (b[y] == 'F') b[x] = 'T';
			else if (b[y] == 'U') b[x] = 'U';
			else b[x] = ' ';
		}
		else {
			int x = read();
			a[x] = 0; c[x] = 0;
			b[x] = ch[0];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			if (c[i]) {
				fa[Find(i)] = Find(a[i] + n);
				fa[Find(i + n)] = Find(a[i]);
			}
			else {
				fa[Find(i)] = Find(a[i]);
				fa[Find(i + n)] = Find(a[i] + n);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = Find(i), y = Find(i + n);
		if ((x == i || x == i + n || y == i || y == i + n) && x == y) Ans[i] = 1;
		if (b[i] == 'U') Ans[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int x = Find(i);
		if (x > n) x -= n;
		Ans[i] = Ans[x];
		ans += Ans[i];
	}
	printf("%d\n", ans);
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	Test_case = read(); int _ = read();
	while (_--) Solve();
	return 0;
}