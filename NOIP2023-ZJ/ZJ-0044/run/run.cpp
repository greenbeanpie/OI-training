#include<bits/stdc++.h>
using namespace std; using ll = long long;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
#define Fol(i, j, k) for ( int i = (j) ; i >= (k) ; i-- )
constexpr ll inf = numeric_limits < ll >::max() / 2;
int n, m, k, d, num[400009], len, id1, idn; ll dp[100009];
struct qwq { int x, y, v; } a[100009];
namespace ST
{
	struct node
	{
		ll v, lz;
		inline void apply(ll x) { v += x, lz += x; }
	}	t[400009 << 2];
	inline int lc(int x) { return x << 1; }
	inline int rc(int x) { return lc(x) | 1; }
	inline int md(int x, int y) { return ( x + y ) >> 1; }
	inline void pd(int p) { if ( t[p].lz ) t[lc(p)].apply(t[p].lz), t[rc(p)].apply(t[p].lz), t[p].lz = 0; }
	inline void pu(int p) { t[p].v = max(t[lc(p)].v, t[rc(p)].v); }
	inline void build(int p, int l, int r)
	{
		t[p].lz = 0;
		if ( l == r ) { t[p].v = ( num[l] - 1ll ) * d; return; }
		build(lc(p), l, md(l, r)), build(rc(p), md(l, r) + 1, r), pu(p);
	}
	inline void add(int p, int l, int r, int lp, int rp, ll v)
	{
		if ( l > rp || r < lp ) return;
		if ( lp <= l && r <= rp ) { t[p].apply(v); return; }
		pd(p), add(lc(p), l, md(l, r), lp, rp, v), add(rc(p), md(l, r) + 1, r, lp, rp, v), pu(p);
	}
	inline ll qry(int p, int l, int r, int lp, int rp)
	{
		if ( l > rp || r < lp ) return -inf;
		if ( lp <= l && r <= rp ) return t[p].v;
		return pd(p), max(qry(lc(p), l, md(l, r), lp, rp), qry(rc(p), md(l, r) + 1, r, lp, rp));
	}
}
inline void D_clear() { len = 0; }
inline void D_push(int x) { num[++len] = x; }
inline void D_build() { sort(num + 1, num + len + 1), len = unique(num + 1, num + len + 1) - num - 1; }
inline int D_id(int x) { return lower_bound(num + 1, num + len + 1, x) - num; }
inline void work()
{
	cin >> n >> m >> k >> d, D_clear(), D_push(1), D_push(n);
	For(i, 1, m)
	{
		cin >> a[i].x >> a[i].y >> a[i].v;
		D_push(a[i].x - a[i].y + 1), D_push(max(1, a[i].x - k + 1)), D_push(a[i].x), D_push(a[i].x + 2);
	}
	D_build(), sort(a + 1, a + m + 1, [&](const qwq &x, const qwq &y) { return x.x < y.x; });
	dp[0] = 0, ST::build(1, 1, len), id1 = D_id(1), idn = D_id(n);
	For(i, 1, m)
	{
		ST::add(1, 1, len, id1, D_id(a[i].x - a[i].y + 1), a[i].v);
		dp[i] = max(dp[i - 1], ST::qry(1, 1, len, D_id(max(1, a[i].x - k + 1)), D_id(a[i].x)) - (ll)a[i].x * d);
		ST::add(1, 1, len, D_id(a[i].x + 2), idn, dp[i] - dp[i - 1]);
	}
	cout << dp[m] << '\n';
}
int main()
{
	freopen("run.in", "r", stdin), freopen("run.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	int _, t; cin >> _ >> t; For(tt, 1, t) work(); return 0;
}
/*
clear && g++ run.cpp -o run -Wno-unused-result -std=c++14 -O2 -fsanitize=address,undefined -g && /usr/bin/time -f "%Us %MKB" ./run < run1.in > run.out && diff run.out run1.ans -Z
*/