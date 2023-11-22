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

const int maxn = 3030;

struct nd {
	map <int, int> mp;
	int ed;
} p[maxn * maxn]; int cnt;
char s[maxn][maxn], t[maxn];
int eds[maxn];
int anss[maxn];
int cp[maxn];
signed main () {
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);
	int n = d, m = d;
	fq (i, 1, n) scanf ("%s", s[i] + 1);
	fq (i, 1, n) {
		fq (j, 1, m) t[j] = s[i][j];
		fq (j, 'a', 'z') cp[j] = 0;
		fq (j, 1, m) ++cp[t[j]];
		{
			int cnt = 0;
			nfq (j, 'z', 'a') while (cp[j]--) t[++cnt] = j;
		}
		int rt = 0;
		fq (j, 1, m) {
			int c = t[j] - 'a';
			if (!p[rt].mp[c]) p[rt].mp[c] = ++cnt;
			rt = p[rt].mp[c];
		} p[rt].ed++; eds[i] = rt;
	}
	
	fq (i, 1, n) {
		anss[i] = -1;
		fq (j, 1, m) t[j] = s[i][j];
		fq (j, 'a', 'z') cp[j] = 0;
		fq (j, 1, m) ++cp[t[j]];
		{
			int cnt = 0;
			fq (j, 'a', 'z') while (cp[j]--) t[++cnt] = j;
		}
		int rt = 0;
		fq (j, 1, m) {
			int c = t[j] - 'a';
			fnq (k, 0, c) if (p[rt].mp.find (k) != p[rt].mp.end () && p[rt].mp[k] != 0) {
				anss[i] = 0; break;
			} if (anss[i] != -1) break;
			rt = p[rt].mp[c];
			if (!rt) {anss[i] = 1; break;}
		} if (anss[i] == -1) {
			if (p[rt].ed > 1) anss[i] = 0;
			else anss[i] = 1;
		}
	}
	fq (i, 1, n) cout << anss[i];
	return 0;
}

// where is my chinese shurufa??
// zhong guo ren bu yong yang wen.

// What you said is right, but wujisalt is the cuttest, obviously.
// I wonder if Nahida will pray for me.
// wo shi na xi da de gou.