#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4e5;
const ll N = maxn + 10;
ll o, T, n, m, p, q, maxx, ans, g[N];
struct edg{
	ll v, w;
};
vector<edg> f[N];
struct nde{
	ll l, r, x, k;
}a[N * 4];
void pushupmySGT(ll x) { // pushup can be used only when x has been pushdowned
	a[x].x = max(a[x * 2].x, a[x * 2 + 1].x);
}
void buildmySGT(ll x, ll l, ll r) {
	a[x].l = l;
	a[x].r = r;
	a[x].x = 0;
	a[x].k = 0;
	if (l == r) {
		return;
	}
	ll mid = (l + r) / 2;
	buildmySGT(x * 2, l, mid);
	buildmySGT(x * 2 + 1, mid + 1, r);
	pushupmySGT(x);
}
void pushdownmySGT(ll x) {
	if (a[x].k != 0) {
		a[x * 2].x += a[x].k;
		a[x * 2].k += a[x].k;
		a[x * 2 + 1].x += a[x].k;
		a[x * 2 + 1].k += a[x].k;
		a[x].k = 0;
	}
}
void updmySGT(ll x, ll u, ll v, ll k) {
	if (a[x].l == u && a[x].r == v) {
		a[x].x += k;
		a[x].k += k;
		return;
	}
	pushdownmySGT(x);
	ll mid = (a[x].l + a[x].r) / 2;
	if (v <= mid) {
		updmySGT(x * 2, u, v, k);
	}
	else if (u > mid) {
		updmySGT(x * 2 + 1, u, v, k);
	}
	else {
		updmySGT(x * 2, u, mid, k);
		updmySGT(x * 2 + 1, mid + 1, v, k);
	}
	pushupmySGT(x);
}
ll qrymySGT(ll x, ll u, ll v) {
	if (a[x].l == u && a[x].r == v) {
		return a[x].x;
	}
	pushdownmySGT(x);
	ll mid = (a[x].l + a[x].r) / 2;
	if (v <= mid) {
		return qrymySGT(x * 2, u, v);
	}
	else if (u > mid) {
		return qrymySGT(x * 2 + 1, u, v);
	}
	else {
		return max(qrymySGT(x * 2, u, mid), qrymySGT(x * 2 + 1, mid + 1, v));
	}
}
ll rd() {
	char ch = getchar();
	ll s = 0, w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (s * w);
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	o = rd(); T = rd();
	while (T--) {
		n = rd(); m = rd(); p = rd(); q = rd();
		g[0] = 0;
		for (ll i = 1; i <= n; ++i) {
			f[i].clear();
			g[i] = 0;
		}
		for (ll i = 1; i <= n * 4; ++i) {
			a[i].l = 0;
			a[i].r = 0;
			a[i].x = 0;
			a[i].k = 0;
		}
		{ll u, v, w;
		for (ll i = 1; i <= m; ++i) {
			u = rd(); v = rd(); w = rd();
			f[u].push_back((edg){u - v + 1, w});
		}}
		buildmySGT(1, 1, n);
		for (ll i = 1; i <= n; ++i) {
			ll u = max((ll)(1ll), i - p + 1);
			if (i >= 3) {
				updmySGT(1, i, i, g[i - 2]);
			}
			updmySGT(1, u, i, -q);
			for (auto j : f[i]) {
				if (j.v >= u) {
					updmySGT(1, u, j.v, j.w);
				}
			}
			g[i] = max(g[i - 1], qrymySGT(1, u, i));
		}
		ans = g[n];
		printf("%lld\n", ans);
	}
	return 0;
}
