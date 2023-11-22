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
#define lb lower_bound
#define ub upper_bound
#define pc putchar
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

const int N = 5e5 + 15;

int f[2005][2005];
int g[105][40005];
int a[N], b[N];
int c, n, m, q;

struct Query {
	int x, y;
} qx[N], qy[N];

int cmp(int x, int y) {
	return x < y ? 1 : (x == y ? 0 : -1);
}

void query114514() {
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	int flg = cmp(a[1], b[1]);
//	rep(i, 1, n) printf("%d ", a[i]); pc(10);
//	rep(i, 1, m) printf("%d ", b[i]); pc(10);
int ans = 0;
	if(flg == 0) {
		putchar('0');
		return ;
	}
	rep(i, 1, 100) rep(j, 1, m - 1) {
		g[i][j] = cmp(a[i], b[j]) ? 0 : g[i - 1][j] | g[i][j - 1] | g[i - 1][j - 1];
	}
	rep(i, 1, 100) if(g[i][m - 1]) ans = 1;
	rep(i, 1, 100) rep(j, 1, n - 1) {
		g[i][j] = cmp(b[i], a[j]) ? 0 : g[i - 1][j] | g[i][j - 1] | g[i - 1][j - 1];
	}
	rep(i, 1, 100) if(g[i][n - 1]) ans = 1;
	pc(ans + '0');
}

void query() {
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	int flg = cmp(a[1], b[1]);
//	rep(i, 1, n) printf("%d ", a[i]); pc(10);
//	rep(i, 1, m) printf("%d ", b[i]); pc(10);
	if(flg == 0) {
		putchar('0');
		return ;
	}
	rep(i, 1, n) rep(j, 1, m) {
		if(cmp(a[i], b[j]) != flg) continue;
//		if(abs(i - j) > 1000) continue;
		f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
	}
	putchar(f[n][m] ? '1' : '0');
}

bool mem_v;

void solve() {
//	clock_t _st = clock();
//	cerr << (&mem_u - &mem_v) / 1048576.0 << " MB" << endl;
	c = read(); n = read(); m = read(); q = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) b[i] = read();
	 query();
	while(q --) {
		int kx = read(), ky = read();
		rep(i, 1, kx) {
			qx[i].x = read(); qx[i].y = read();
			swap(a[qx[i].x], qx[i].y);
		}
		rep(i, 1, ky) {
			qy[i].x = read(); qy[i].y = read();
			swap(b[qy[i].x], qy[i].y);
		}
//		if(8 <= c && c <= 14) query114514();
		query();
		rep(i, 1, kx) {
			swap(a[qx[i].x], qx[i].y);
		}
		rep(i, 1, ky) {
			swap(b[qy[i].x], qy[i].y);
		}
	}
	pc(10);
//	cerr << (clock() - _st) * 1.0 / CLOCKS_PER_SEC << " s" << endl;
}

} // Isaunoya



int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	Isaunoya :: solve();
	return 0;
}