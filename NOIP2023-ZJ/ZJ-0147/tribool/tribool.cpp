#include <bits/stdc++.h>
#define fq(i,a,b) for (int i = (a); i <= (b); i++)
#define fnq(i,a,b) for (int i = (a); i < (b); i++)
#define nfq(i,a,b) for (int i = (a); i >= (b); i--)
#define nfnq(i,a,b) for (int i = (a); i > (b); i--)
#define elif else if
using namespace std;

//#define int long long

inline int rd() {
	char ch = getchar ();
	int f = 1;
	while (!isdigit (ch)) {
		if (ch == '-') f *= -1;
		ch = getchar ();
	}
	int num = 0;
	while (isdigit (ch)) {
		num = num * 10 + ch - '0';
		ch = getchar ();
	} return num * f;
}
#define d rd()

const int maxn = 100100;
int f[maxn << 1]; int findf (int x) {
	return x == f[x] ? x : (f[x] = findf (f[x]));
}
int g[maxn << 1];
void merge (int x, int y) {
	x = findf (x), y = findf (y);
	if (x != y) f[x] = y;
}
int n, m;
int _n (int id) {
	if (id > n + 2) return id - n;
	if (id > 2) return id + n;
	if (id == 2) return 1;
	if (id == 1) return 2;
	return 0;
}
int tgs[maxn << 1];
void solve () {
	n = d, m = d;
	fq (i, 0, n * 2 + 2) f[i] = g[i] = i;
	//0 : U; 1 : T; 2 : F; i, i+n : x_i, \lnot x_i;
	while (m--) {
		string op;
		cin >> op;
		if (op[0] == '+') {
			int x = d, y = d;
			int g0 = g[y + 2];
			int g1 = g[_n (y + 2)];
			g[x + 2] = g0;
			g[_n (x + 2)] = g1;
		} elif (op[0] == '-') {
			int x = d, y = d;
			int g0 = g[y + 2];
			int g1 = g[_n (y + 2)];
			g[x + 2] = g1;
			g[_n (x + 2)] = g0;
		} elif (op[0] == 'T') {
			int x = d;
			g[x + 2] = 1;
			g[_n (x + 2)] = 2;
		} elif (op[0] == 'F') {
			int x = d;
			g[x + 2] = 2;
			g[_n (x + 2)] = 1;
		} elif (op[0] == 'U') {
			int x = d;
			g[x + 2] = 0;
			g[_n (x + 2)] = 0;
		} else cerr << "?" << endl;
	}
	fq (i, 0, n * 2 + 2) merge (i, g[i]);
	fq (i, 0, n * 2 + 2) tgs[i] = -1;
	tgs[findf (0)] = 0;
	fq (i, 1, n) if (findf (i + 2) == findf (_n (i + 2))) tgs[findf (i + 2)] = 0;
	int cnt = 0;
	fq (i, 1, n) if (tgs[findf (i + 2)] == 0) ++cnt;
	cout << cnt << endl;
}

signed main () {
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	d;
	int T = d; while (T--) solve ();
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.
// wo shi na xi da de gou.