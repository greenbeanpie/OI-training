#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
const int N = 3005;
int n, m;
int mn[N], mx[N], Ans[N];
char a[N];
void Solve() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++) {
		scanf("%s", a + 1);
		mn[i] = 26; mx[i] = 0;
		for (int j = 1; j <= m; j++) {
			mn[i] = min(mn[i], a[j] - 'a');
			mx[i] = max(mx[i], a[j] - 'a');
		}
	}
	for (int i = 1; i <= n; i++) {
		Ans[i] = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int w1 = mn[i], w2 = mx[j];
			if (w1 >= w2) Ans[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) putchar(Ans[i] + '0'); putchar('\n');
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int _ = 1;
	while (_--) Solve();
	return 0;
}