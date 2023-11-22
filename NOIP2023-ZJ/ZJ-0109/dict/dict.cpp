#include <bits/stdc++.h>
#define ll long long
#define RI int
#define W while
#define CI const int
#define gc getchar
using namespace std;
CI N = 3e3; const unsigned ll P = 13331;
int n, m; int a[N + 5][35]; bool ans[N + 5]; int id[N + 5];
bool check (int A, int B) {
	vector <int> x, y; for (int i = 1; i <= 26; ++ i) for (int j = 1; j <= a[A][i]; ++ j) x.push_back (i);
	for (int i = 26; i >= 1; -- i) for (int j = 1; j <= a[B][i]; ++ j) y.push_back (i);
	for (int i = 0; i < m; ++ i) if (x[i] != y[i]) return x[i] < y[i]; return false;
}
bool cmp2 (int A, int B) {
	RI i, j; for (i = 26; i >= 1; -- i) if (a[A][i] != a[B][i]) return a[A][i] < a[B][i]; return true;
}
int main () {
	freopen ("dict.in", "r", stdin); freopen ("dict.out", "w", stdout);
	RI i, j; for (scanf ("%d%d", &n, &m), i = 1; i <= n; ++ i) { id[i] = i;
		char ch; for (j = 1; j <= m; ++ j) {ch = gc (); if (ch == '\n') ch = gc (); ++ a[i][ch - 'a' + 1];}
	} sort (id + 1, id + n + 1, cmp2);
	for (i = 1; i <= n; ++ i) {if (check (i, (id[1] == i ? id[2] : id[1]))) ans[i] = 1; else ans[i] = 0;}
	for (i = 1; i <= n; ++ i) printf ("%d", ans[i]); printf ("\n");
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/