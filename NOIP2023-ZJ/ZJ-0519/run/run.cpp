#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
const int N = 1005;
int tc, T, n, m, k, d;
ll f[N][N];
vector<pair<int, ll>> a[N];
map<int, ll> mp;
template<typename T> inline bool chkmax(T &x, const T &y) {
	return (x < y) && (x = y, true);
}
inline void solve() {
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= n; i++)
		a[i].clear();
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		a[x].emplace_back(y, v);
	}
	for (int i = 1; i <= n; i++) {
		mp.clear();
		for (auto [y, v] : a[i])
			mp[y] += v;
		a[i].clear();
		for (auto [y, v] : mp)
			a[i].emplace_back(y, v);
		for (size_t j = 1; j < a[i].size(); j++)
			a[i][j].second += a[i][j - 1].second;
	}
	memset(f, ~0x2f, sizeof f);
	for (int i = 0; i <= k; i++)
		f[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int p = 0; p <= k; p++)
			chkmax(f[i][0], f[i - 1][p]);
		for (int p = 1; p <= k; p++)
			chkmax(f[i][p], f[i - 1][p - 1] - d);
		
		for (auto [y, v] : a[i]) {
			for (int p = y; p <= k; p++) {
				chkmax(f[i][p], f[i - 1][p - 1] - d + v);
			}
		}
		for (int j = 0; j <= k; j++)
			cerr << f[i][j] << ' ';
		cerr << '\n';
	}
	ll ans = 0;
	for (int i = 0; i <= k; i++)
		chkmax(ans, f[n][i]);
	cout << ans << endl;
}
mt19937 rng(1u);
struct wyphs {
	static const int N = 1e6 + 5;
	int ls[N], rs[N], pri[N], siz[N], rt, idx;
	ll mx[N];
	ll val[N], tag[N];
	wyphs() {
		memset(ls, 0, sizeof ls), memset(rs, 0, sizeof rs), memset(mx, 0, sizeof mx), memset(pri, 0, sizeof pri), rt = idx = 0, memset(siz, 0, sizeof siz);
		memset(val, 0, sizeof val), memset(tag, 0, sizeof tag);
	}
	inline int newnode(ll vl) {
		int p = ++idx;
//		cerr << idx << '\n';
		ls[idx] = rs[idx] = 0, pri[idx] = rng(), siz[idx] = 1, val[idx] = mx[idx] = vl, tag[idx] = 0;
		return idx;
	}
	inline void pushup(int p) {
		siz[p] = siz[ls[p]] + siz[rs[p]] + 1;
		mx[p] = val[p];
		if (ls[p])
			chkmax(mx[p], mx[ls[p]]);
		if (rs[p])
			chkmax(mx[p], mx[rs[p]]);
	}
	inline void pushtag(int p, ll k) {
		tag[p] += k, val[p] += k, mx[p] += k;
	}
	inline void pushdown(int p) {
		if (!p)
			return;
		if (ls[p])
			pushtag(ls[p], tag[p]);
		if (rs[p])
			pushtag(rs[p], tag[p]);
		tag[p] = 0;
	}
	inline void split(int p, int k, int &x, int &y) {
//		cerr << p << '\n';
		if (!p) {
			x = y = 0;
			return;
		}
		pushdown(p);
		if (siz[ls[p]] + 1 <= k) {
			x = p;
			split(rs[p], k - siz[ls[p]] - 1, rs[p], y);
		} else {
			y = p;
			split(ls[p], k, x, ls[p]);
		}
		pushup(p);
	}
	inline int merge(int x, int y) {
		pushdown(x), pushdown(y);
		if (!x || !y)
			return x + y;
		if (pri[x] > pri[y]) {
			rs[x] = merge(rs[x], y);
			pushup(x);
			return x;
		} else {
			ls[y] = merge(x, ls[y]);
			pushup(y);
			return y;
		}
	}
	inline void insert(int pos, ll k) {
		int x, y;
		split(rt, pos - 1, x, y);
		rt = merge(merge(x, newnode(k)), y);
	}
	inline void modify(int l, int r, ll k) {
		int x, y, z;
		split(rt, l - 1, x, y);
		split(y, r - l + 1, y, z);
		pushtag(y, k);
		rt = merge(merge(x, y), z);
	}
	inline void pushback(ll k) {
		rt = merge(rt, newnode(k));
	}
	inline void popback() {
		int cur = siz[rt], x;
		split(rt, cur - 1, rt, x);
	}
	inline void print(int p) {
		if (!p)
			return;
		pushdown(p);
		print(ls[p]);
		cout << val[p] << ' ' ;
		print(rs[p]);
		if (p == rt)
			cout << endl;
	}
} S;
inline void solve2() {
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= n; i++)
		a[i].clear();
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		a[x].emplace_back(y, v);
	}
//	memset(f, ~0x2f, sizeof f);
	S = wyphs();
	for (int i = 0; i <= k; i++)
		S.pushback(0);
//	return;
	for (int i = 1; i <= n; i++) {
		ll vl = S.val[S.rt];
		S.insert(1, vl);
		if (S.siz[S.rt] > k + 1)
			S.popback();
		S.modify(2, k + 1, -d);
		for (auto [y, v] : a[i]) {
			S.modify(y + 1, k + 1, v);
		}
	}
	ll ans = S.val[S.rt];
	cout << ans << endl;
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> tc >> T;
	while (T--)
		solve();
	return 0;
}