#include <bits/stdc++.h>
#define ll long long
#define RI int
#define W while
#define CI const int
#define gc getchar
using namespace std;
CI N = 1e5, N2 = 3e5; int c, t, n, m, a[N + 5], fa[N2 + 5];
void Readc (char &ch) {W (ch = gc (), (ch == ' ' || ch == '\n'));}
int Find (int x) {return fa[x] == x ? x : fa[x] = Find (fa[x]);}
void unionn (int x, int y) {x = Find (x); y = Find (y); if (x != y) fa[y] = x;}
void solve () {
	RI i, j; scanf ("%d%d", &n, &m); for (i = 1; i <= n; ++ i) a[i] = i; for (i = 1; i <= m; ++ i) {
		char c; Readc (c); int x, y; if (c == 'T') {scanf ("%d", &x); a[x] = 1e5 + 1;}
		else if (c == 'F') {scanf ("%d", &x); a[x] = - 1e5 - 1;}
		else if (c == 'U') {scanf ("%d", &x); a[x] = 0;}
		else if (c == '+') {scanf ("%d%d", &x, &y); a[x] = a[y];}
		else if (c == '-') {scanf ("%d%d", &x, &y); a[x] = -a[y];}
	} for (i = 1; i <= 3 * N; ++ i) fa[i] = i; int T = 2e5 + 1, F = 2e5 + 2;
//	for (i = 1; i <= n; ++ i) printf ("%d %d\n", i, a[i]);
	for (i = 1; i <= n; ++ i) {
		if (a[i] == 1e5 + 1) unionn (T, i);
		else if (a[i] ==  - 1e5 - 1) unionn (F, 1e5 + i);
		else if (a[i] == 0) unionn (i, 1e5 + i);
		else if (a[i] > 0) unionn (i, a[i]), unionn (1e5 + i, 1e5 + a[i]);
		else if (a[i] < 0) unionn (i, 1e5 - a[i]), unionn (1e5 + i, -a[i]);
	}
//	for (i = 1; i <= n; ++ i) printf ("%d %d\n", i, Find (i));
	int ans = 0; for (i = 1; i <= n; ++ i) {
		if (Find (i) == Find (1e5 + i)) ++ ans;
	} printf ("%d\n", ans);
}
int main () {
	freopen ("tribool.in", "r", stdin); freopen ("tribool.out", "w", stdout);
	RI i, j; scanf ("%d%d", &c, &t); W (t --) {solve ();}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2

1 1
10 10
- 1 1
U 1
T 7
U 8
- 9 6
U 3
- 9 3
- 6 3
+ 9 3
- 9 8
*/