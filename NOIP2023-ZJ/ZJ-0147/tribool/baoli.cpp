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
int op[maxn], x[maxn], y[maxn];
int ans, p[maxn], q[maxn], r[maxn];
int n, m;
int _n (int id) {
	if (id == 2) return 1;
	if (id == 1) return 2;
	return 0;
}
void chk() {
	fq (i, 1, n) q[i] = p[i];
	fq (i, 1, m) {
		if (op[i] == '+') q[x[i]] = q[y[i]];
		else q[x[i]] = _n (q[y[i]]);
	}
	fq (i, 1, n) if (p[i] != q[i]) return;
	int cnt = 0;fq (i, 1, n) cnt += !q[i];
	if (cnt < ans) {
		ans = cnt;
		fq (i, 1, n) r[i] = p[i];
	}
}
void dfs (int i) {
	if (i == n + 1) {chk(); return;
	}
	fq (j, 0, 2) p[i] = j, dfs (i + 1);
}
void solve () {
	n = d, m = d;
	fq (i, 1, m) {
		string s; cin >> s; op[i] = s[0];
		x[i] = d, y[i] = d;
	}
	ans = n;
	dfs (1);
	cout << ans << endl;
	fq (i, 1, n) cerr << r[i] << ' '; cerr << endl;
}

signed main () {d;
	int T = d; while (T--) solve ();
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.