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
#define rep(i, l, r) for(int i = l, i##end = r; i <= i##end; ++ i)
#define per(i, l, r) for(int i = l, i##end = r; i >= i##end; -- i)

char ibuf[1 << 23], *p1 = ibuf, *p2 = ibuf;
#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 23, stdin), p1 == p2) ? EOF : *p1 ++)
inline int read() {
	int res = 0; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) ;
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

const int N = 4e5 + 15;

int b[N];
int n, m, lim, k;
ll mx[N * 4], tag[N * 4];
ll d;

struct seg {
	int l, r, v;
	bool operator < (const seg &b) const {
		return r < b.r;
	}
} a[N];

#define lc (p << 1)
#define rc (p << 1 | 1)

void add(int p, ll x) {
	mx[p] += x;
	tag[p] += x;
}

void push(int p) {
	if(tag[p]) {
		add(lc, tag[p]);
		add(rc, tag[p]);
		tag[p] = 0;
	}
}

void upd(int p) {
	mx[p] = max(mx[lc], mx[rc]);
}

void build(int p, int l, int r) {
	tag[p] = 0;
	if(l == r) {
		mx[p] = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	upd(p);
}

ll query(int p, int l, int r, int tl, int tr) {
	if(tl > tr) return -1e18;
	if(tl <= l && r <= tr) return mx[p];
	int mid = l + r >> 1;
	ll res = -1e18;
	push(p);
	if(tl <= mid) chmax(res, query(lc, l, mid, tl, tr));
	if(mid < tr) chmax(res, query(rc, mid + 1, r, tl, tr));
	return res;
}

void modify(int p, int l, int r, int i, ll x) {
	if(l == r) {
		chmax(mx[p], x);
		return ;
	}
	int mid = l + r >> 1;
	push(p);
	if(i <= mid) modify(lc, l, mid, i, x);
	else modify(rc, mid + 1, r, i, x);
	upd(p);
}

void modify(int p, int l, int r, int tl, int tr, ll x) {
	//if(l == 1 && r == lim) printf("%d %d %lld\n", tl, tr, x);
	if(tl > tr) return ;
	if(tl <= l && r <= tr) {
		add(p, x); return ;
	}
	int mid = l + r >> 1;
	push(p);
	if(tl <= mid) modify(lc, l, mid, tl, tr, x);
	if(mid < tr) modify(rc, mid + 1, r, tl, tr, x);
	upd(p);
}

bool mem_v;

ll f[N];

void Solve() {
	n = read(); m = read(); k = read(); d = read();
	lim = 0;
	rep(i, 1, m) {
		int x = read(), y = read();
		a[i].l = x - y; a[i].r = x; a[i].v = read();
		b[++ lim] = a[i].l; b[++ lim] = a[i].r + 1;
	}
	sort(a + 1, a + m + 1);
	sort(b + 1, b + lim + 1);
	lim = unique(b + 1, b + lim + 1) - b - 1;
	build(1, 1, lim);
	int qi = 1;
	ll tmx = 0;
	rep(i, 0, lim) f[i] = 0;
//	rep(i, 1, lim) printf("%d ", b[i]); putchar(10);
	rep(i, 1, lim) {
		for(; qi <= m && a[qi].r < b[i]; ++ qi)
			modify(1, 1, lim, 1, ub(b + 1, b + lim + 1, a[qi].l) - b - 1, a[qi].v);
//		for(; qi <= m && a[qi].r < b[i]; ++ qi) {
////			rep(j, 1, lim) if(b[j] <= a[i].l)
//			chmax(tmx, query(1, 1, lim, lb(b + 1, b + lim + 1, a[qi].r - k) - b, lim) - a[qi].r * d);
//		}
		
		f[i] = max(f[i - 1], query(1, 1, lim, lb(b + 1, b + lim + 1, b[i] - k - 1) - b, i) - max(b[i] - 1, 0) * d);
//		printf("%d %lld\n", b[i], f[i]);
		modify(1, 1, lim, i, f[i] + b[i] * d);
//		chmax(tmx, query(1, 1, lim, , b[i])
//		chmax(tmx, query(1, 1, lim, lb(b + 1, b + lim + 1, a[i].r - k) - b, lim) - a[i].r * d);
//		int p = ub(b + 1, b + lim + 1, a[i].r) - b;
//		if(i <= lim) modify(1, 1, lim, i, tmx);
	}             
	printf("%lld\n", f[lim]);
}

void solve() {
//	clock_t _st = clock();
//	cerr << (&mem_u - &mem_v) / 1048576.0 << " MB" << endl;
	int c = read(), T = read();
	while(T --) Solve();
//	cerr << (clock() - _st) * 1.0 / CLOCKS_PER_SEC << " s" << endl;
}

} // Isaunoya



int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	Isaunoya :: solve();
	return 0;
}