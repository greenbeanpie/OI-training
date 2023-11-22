#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4e5;
const ll N = maxn + 10;
ll o, T, n, m, num, ans, H[N], a[N], fa[N], d[N], D[N], de[N], sz[N], g[N]; // 4e5 + 1: T, 4e5 + 2: F, 4e5 + 3: U, 1~n: var i, -1~-n: not var i
bool z, vis[N], f[N];
struct edg{
	ll t, nxt;
}E[N];
void add_edg(ll x, ll y) {
	++num;
	E[num].t = y;
	E[num].nxt = H[x];
	H[x] = num;
//	cout << "A " << x << ' ' << y << endl;
}
ll get_fa(ll x) {
	if (fa[x] == x) {
		return x;
	}
	else {
		fa[x] = get_fa(fa[x]);
		return fa[x];
	}
}
void mrgefa(ll x, ll y) {
	ll p = get_fa(x), q = get_fa(y);
	if (p == q) {
		return;
	}
	fa[q] = p;
	if (d[p] == maxn + 3 || d[q] == maxn + 3) {
		d[p] = maxn + 3;
	}
	else if (d[p] >= maxn || d[q] >= maxn) {
		d[p] = maxn + 1;
	}
	else {
		d[p] = 0;
	}
}
ll get_D(ll x) {
	if (D[x] == x) {
		return x;
	}
	else {
		D[x] = get_D(D[x]);
		return D[x];
	}
}
void mrgeD(ll x, ll y) {
	ll p = get_D(x), q = get_D(y);
	if (p == q) {
		return;
	}
	D[q] = p;
}
void dfs(ll x, ll fr, ll p) {
	vis[x] = 1;
	de[x] = de[fr] + 1;
	sz[p] += g[x];
	for (ll i = H[x]; i > 0; i = E[i].nxt) {
		ll v = E[i].t;
		if (!vis[v]) {
			dfs(v, x, p);
		}
		else {
			if (abs(de[x] - de[v]) % 2 == 0) {
				f[p] = 1;
			}
		}
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
char rd_ch() {
	char ch = getchar();
	while (ch != 'T' && ch != 'F' && ch != 'U' && ch != '+' && ch != '-') {
		ch = getchar();
	}
	return ch;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	o = rd(); T = rd();
	while (T--) {
		n = rd(); m = rd();
		ans = 0;
		num = 0;
		for (ll i = 1; i <= n; ++i) {
			a[i] = i;
			fa[i] = i;
			d[i] = 0;
			D[i] = i;
			H[i] = 0;
			g[i] = 0;
			vis[i] = 0;
			f[i] = 0;
			sz[i] = 0;
			de[i] = 0;
		}
		{char opt; ll u, v;
		for (ll i = 1; i <= m; ++i) {
			opt = rd_ch();
			if (opt == 'T') {
				u = rd();
				a[u] = maxn + 1;
			}
			else if (opt == 'F') {
				u = rd();
				a[u] = maxn + 2;
			}
			else if (opt == 'U') {
				u = rd();
				a[u] = maxn + 3;
			}
			else if (opt == '+') {
				u = rd(); v = rd();
				a[u] = a[v];
			}
			else {
				u = rd(); v = rd();
				if (a[v] > maxn) {
					if (a[v] == maxn + 1) {
						a[u] = maxn + 2;
					}
					else if (a[v] == maxn + 2) {
						a[u] = maxn + 1;
					}
					else {
						a[u] = maxn + 3;
					}
				}
				else {
					a[u] = -a[v];
				}
			}
		}}
		
		for (ll i = 1; i <= n; ++i) {
			if (a[i] > maxn) {
				if (a[i] == maxn + 3) {
					d[get_fa(i)] = maxn + 3;
				}
				else {
					if (d[get_fa(i)] <= maxn) {
						d[get_fa(i)] = a[i];
					}
				}
//				d[get_fa(i)] = a[i];
			}
			else {
				mrgefa(i, abs(a[i]));
			}
		}
		
		for (ll i = 1; i <= n; ++i) {
			if (d[get_fa(i)] == maxn + 3) {
				++ans;
			}
		}
		
		for (ll i = 1; i <= n; ++i) {
			if (d[get_fa(i)] <= maxn) {
				if (a[i] > 0 && a[i] <= maxn) {
					mrgeD(i, a[i]);
				}
			}
		}
		
		for (ll i = 1; i <= n; ++i) {
			if (d[get_fa(i)] <= maxn) {
				++g[get_D(i)];
				if (a[i] < 0) {
					add_edg(get_D(i), get_D(-a[i]));
					add_edg(get_D(-a[i]), get_D(i));
				}
			}
		}
		
		for (ll i = 1; i <= n; ++i) {
			if (get_D(i) == i) {
				if (!vis[i]) {
					dfs(i, 0, i);
					if (f[i]) {
						ans += sz[i];
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
