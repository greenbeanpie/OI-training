#include <bits/stdc++.h>
#define fq(i,a,b) for (int i = (a); i <= (b); i++)
#define fnq(i,a,b) for (int i = (a); i < (b); i++)
#define nfq(i,a,b) for (int i = (a); i >= (b); i--)
#define nfnq(i,a,b) for (int i = (a); i > (b); i--)
#define elif else if
using namespace std;

#define int long long

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
int dp[2][maxn];
set <pair <int, int> > st[maxn];
int sum[maxn];
void solve () {
	int n = d, m = d, k = d, t = d;
	memset (dp, -0x3f, sizeof dp);
	dp[0][0] = 0;
	fq (i, 1, n) st[i].clear ();
	fq (i, 1, m) {
		int x = d, y = d, p = d;
		st[x].insert (make_pair (y, p));
	}
	fq (i, 1, n) {
		fq (j, 0, k) dp[i&1][j] = -1e18;
		fq (j, 0, k) dp[i&1][0] = max (dp[i&1][0], dp[(i-1)&1][j]);
		fq (j, 1, k) dp[i&1][j] = dp[(i-1)&1][j-1] - t;
		fq (j, 0, k) sum[j] = 0;
		for (auto j : st[i]) sum[j.first] += j.second;
		fq (j, 1, k) sum[j] += sum[j - 1];
		fq (j, 0, k) dp[i&1][j] += sum[j];
	}
	int ans = -1e18;
	fq (j, 0, k) ans = max (ans, dp[n&1][j]);
	cout << ans << endl;
}
signed main () {
//	freopen ("run.in", "r", stdin);
//	freopen ("run.out", "w", stdout);
	d;
	int T = d; while (T--) solve ();
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.
// wo shi na xi da de gou.