#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;



namespace Isaunoya {

bool mem_u;

using ll = long long;
using pii = pair <int, int>;
using db = double;

#define fi first
#define se second
#define mp make_pair
#define rep(i, l, r) for(int i = l, i##end = r; i <= i##end; ++ i)
#define per(i, l, r) for(int i = l, i##end = r; i >= i##end; -- i)

char ibuf[1 << 23], *p1 = ibuf, *p2 = ibuf;
#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 23, stdin), p1 == p2) ? EOF : *p1 ++)
inline int read() {
	int res = 0; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar())
		if(ch > 32) return ch;
	for(; ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

template <class T>
void chmax(T &x, T y) {
	if(x < y) x = y;
}
template <class T>
void chmin(T &x, T y) {
	if(y < x) x = y;
}

const int N = 2e5 + 15;

pii a[N];
int b[N], fa[N], mark[N];
int n, m, ans;

bool mem_v;

int find(int x) {
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

pii rev(pii x) {
	if(x.fi >= 0) return mp(x.fi ^ 1, x.se);
	if(x.fi == -3) return mp(-3, 0);
	return mp(-3 - x.fi, 0);
}

void Solve() {
	n = read(); m = read();
	rep(i, 1, n) a[i] = mp(0, i);
	rep(t, 1, m) {
		int opt = read(), i = read();
		if(opt == '+') a[i] = a[read()];
		else if(opt == '-') a[i] = rev(a[read()]);
		else if(opt == 'T') a[i] = mp(-1, 0);
		else if(opt == 'F') a[i] = mp(-2, 0);
		else a[i] = mp(-3, 0);
	}
	rep(i, 1, n + 3) fa[i] = i;
	rep(i, 1, n + 3) mark[i] = 0;
	mark[n + 3] = 1;
	rep(i, 1, n) {
		int to = a[i].fi < 0 ? n - a[i].fi : a[i].se;
		if(find(i) == find(to)) {
			int cnt = a[i].fi;
			for(int u = to; u != i; u = a[u].se)
				cnt += a[u].fi;
			mark[find(i)] = cnt & 1;
		} else fa[find(i)] = find(to);
	}
	ans = 0;
	rep(i, 1, n) ans += mark[find(i)];
	printf("%d\n", ans);
}

void solve() {
	clock_t _st = clock();
//	cerr << (&mem_u - &mem_v) / 1048576.0 << " MB" << endl;
	int c = read(), T = read();
	while(T --) Solve();
//	cerr << (clock() - _st) * 1.0 / CLOCKS_PER_SEC << " s" << endl;
}

} // Isaunoya



int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	Isaunoya :: solve();
	return 0;
}