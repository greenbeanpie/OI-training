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
int c, n, m, k, t;
namespace sub1 {
	int dp[2][maxn];
	set <pair <int, int> > st[maxn];
	int sum[maxn];
	void solve () {
		fq (i, 1, n) st[i].clear ();
		fq (i, 1, m) {
			int x = d, y = d, p = d;
			st[x].insert (make_pair (y, p));
		}
		fq (i, 0, 1) fq (j, 0, k) dp[i][j] = -1e18;
		dp[0][0] = 0;
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
}
namespace sub2 {
	map <int, int> ls;
	int num[maxn];
	int lx[maxn], ly[maxn], lp[maxn];
	int dp[2][maxn];
	set <pair <int, int> > st[maxn];
	int sum[maxn];
	void solve () {
		fq (i, 1, m) lx[i] = d, ly[i] = d, lp[i] = d;
		ls.clear ();
		fq (i, 1, m) ls[lx[i]] = 1;
		int pcnt = 0;
		for (auto &i : ls) i.second = ++pcnt, num[pcnt] = i.first;
		fq (i, 1, pcnt) st[i].clear ();
		fq (i, 1, m) st[ls[lx[i]]].insert (make_pair (ly[i], lp[i]));
		fq (i, 0, 1) fq (j, 0, k) dp[i][j] = -1e18;
		dp[0][0] = 0;
		num[0] = 0;
		fq (i, 1, pcnt) {
			fq (j, 0, k) dp[i&1][j] = -1e18;
			int gap = num[i] - num[i - 1];
			int mx = -1e18;
			fq (j, 0, k) mx = max (mx, dp[(i-1)&1][j]);
			fq (j, 0, min (k, gap - 1)) dp[i&1][j] = mx - j * t;
			fq (j, gap, k) dp[i&1][j] = dp[(i-1)&1][j - gap] - gap * t;
			fq (j, 0, k) sum[j] = 0;
			for (auto j : st[i]) sum[j.first] += j.second;
			fq (j, 1, k) sum[j] += sum[j - 1];
			fq (j, 0, k) dp[i&1][j] += sum[j];
		}
		int ans = -1e18;
		fq (j, 0, k) ans = max (ans, dp[pcnt&1][j]);
		cout << ans << endl;
	}
}
namespace sub3 {//0pts
	void solve () {
		int sum = 0;
		fq (i, 1, m) {
			int x = d, y = d, p = d;
			if (y <= k) sum += max ((int)0, p - y * t);
		} cout << sum << endl;
	}
}
void solve () {
	n = d, m = d, k = d, t = d;
	if (c <= 9) {sub1::solve (); return;}
	if (c >= 17 && c <= 18) {sub3::solve (); return;}
//	if (c >= 10 && c <= 11 || c >= 15 && c <= 16)
	{sub2::solve (); return;}
}
signed main () {
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	c = d;
	int T = d; while (T--) solve ();
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.
// wo shi na xi da de gou.