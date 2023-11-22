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
const int maxn = 500500;
int n, m, q;
int a[maxn], b[maxn], aa[maxn], bb[maxn];
int ansl[77];
bool dp[2020][2020];
int chk() {
	fq (i, 1, n) fq (j, 1, m) dp[i][j] = 0;
	dp[1][1] = 1;
	if (a[1] > b[1]) {
		fq (i, 1, n) fq (j, 1, m) {
			if (a[i] > b[j]) dp[i][j] |= dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
		}
		if (dp[n][m]) return 1;
	}
	if (b[1] > a[1]) {
		fq (i, 1, n) fq (j, 1, m) {
			if (b[j] > a[i]) dp[i][j] |= dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
		}
		if (dp[n][m]) return 1;
	}
	return 0;
}
signed main () {
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);
	d; n = d, m = d, q = d;
	fq (i, 1, n) a[i] = aa[i] = d;
	fq (i, 1, m) b[i] = bb[i] = d;
	ansl[0] = chk();
	fq (k, 1, q) {
		fq (i, 1, n) a[i] = aa[i];
		fq (i, 1, m) b[i] = bb[i];
		int ca = d, cb = d;
		fq (j, 1, ca) {
			int i = d, x = d;
			a[i] = x;
		}
		fq (j, 1, cb) {
			int i = d, x = d;
			b[i] = x;
		}
		ansl[k] = chk();
	}
	fq (k, 0, q) cout << ansl[k];
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.
// wo shi na xi da de gou.