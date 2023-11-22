#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, q;
long long X[N], Y[N], a[N], b[N];
map<int, map<int, int> > mp;
int mmp[2005][2005];
bool check(int l1, int l2, bool ck) {
	if (mmp[l1][l2]) return mmp[l1][l2] - 1;
	if (l1 == 1 && l2 == 1) {mmp[l1][l2] = 2; return 1;}
	if (a[l1] == b[l2]) {mmp[l1][l2] = 1; return 0;}
	if (ck && a[l1] < b[l2]) {mmp[l1][l2] = 1; return 0;}
	if ((!ck) && a[l1] > b[l2]) {mmp[l1][l2] = 1; return 0;}
	if (l1 > 1 && check(l1 - 1, l2, ck)) {mmp[l1][l2] = 2; return 1;}
	if (l2 > 1 && check(l1, l2 - 1, ck)) {mmp[l1][l2] = 2; return 1;}
	mmp[l1][l2] = 1;
	return 0;
}
void solve() {
	if (a[1] == b[1] || a[n] == b[m]) {
		putchar ('0');
		return ;
	}
	if ((a[1] - b[1]) * (a[n] - b[m]) < 0) {
		putchar ('0');
		return ;
	}
	memset (mmp, 0, sizeof (mmp));
	mmp[1][1] = 2;
	putchar (check(n, m, (a[1] > b[1])) + '0');
	return ;
}
void modify(int k1, int k2) {
	if (k1 == 0 && k2 == 0) {
		solve ();
		return ;
	}
	int p, v;
	scanf ("%d%d", &p, &v);
	if (k1 > 0) {
		a[p] = v;
		modify (k1 - 1, k2);
		a[p] = X[p];
		return ;
	}
	else if (k2 > 0) {
		b[p] = v;
		modify (k1, k2 - 1);
		b[p] = Y[p];
		return ;
	}
}
bool check1(int l1, int l2, bool ck) {
	if (mp[l1][l2]) return mp[l1][l2] - 1;
	if (l1 == 1 && l2 == 1) {mp[l1][l2] = 2; return 1;}
	if (a[l1] == b[l2]) {mp[l1][l2] = 1; return 0;}
	if (ck && a[l1] < b[l2]) {mp[l1][l2] = 1; return 0;}
	if ((!ck) && a[l1] > b[l2]) {mp[l1][l2] = 1; return 0;}
	if (l1 > 1 && check1(l1 - 1, l2, ck)) {mp[l1][l2] = 2; return 1;}
	if (l2 > 1 && check1(l1, l2 - 1, ck)) {mp[l1][l2] = 2; return 1;}
	mp[l1][l2] = 1;
	return 0;
}
void solve1() {
	if (a[1] == b[1] || a[n] == b[m]) {
		putchar ('0');
		return ;
	}
	if ((a[1] - b[1]) * (a[n] - b[m]) < 0) {
		putchar ('0');
		return ;
	}
	mp.clear();
	mp[1][1] = 2;
	putchar (check1(n, m, (a[1] > b[1])) + '0');
	return ;
}
void modify1(int k1, int k2) {
	if (k1 == 0 && k2 == 0) {
		solve1 ();
		return ;
	}
	int p, v;
	scanf ("%d%d", &p, &v);
	if (k1 > 0) {
		a[p] = v;
		modify1 (k1 - 1, k2);
		a[p] = X[p];
		return ;
	}
	else if (k2 > 0) {
		b[p] = v;
		modify1 (k1, k2 - 1);
		b[p] = Y[p];
		return ;
	}
}
int main() {
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);
	scanf ("%d%d%d%d", &c, &n, &m, &q);
	for (int i = 1;i <= n; ++ i) scanf ("%lld", X + i), a[i] = X[i];
	for (int i = 1;i <= m; ++ i) scanf ("%lld", Y + i), b[i] = Y[i];
	if (c <= 7) {
		solve ();
		while (q --) {
			int k1, k2;
			scanf ("%d%d", &k1, &k2);
			modify(k1, k2);
		}
		return 0;
	}
	solve1 ();
	while (q --) {
		int k1, k2;
		scanf ("%d%d", &k1, &k2);
		modify1(k1, k2);
	}
	return 0;
}

