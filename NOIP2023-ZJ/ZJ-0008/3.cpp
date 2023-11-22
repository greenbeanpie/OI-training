#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
#define vi vector<int>
#define PB emplace_back
#define siz(a) ((int) a.size())

const int N = 5e5;
int TT, a, b, T, c[N + 5], d[N + 5], s[N + 5], t[N + 5], mx[N * 4 + 5], mn[N * 4 + 5];

#define ls n << 1
#define rs n << 1 | 1
int F(int x, int y) {
	if(s[x] == t[y]) return 2;
	return s[x] > t[y];
}
void build(int n, int l, int r) {
	if(l == r) return mx[n] = mn[n] = t[l], void();
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	mx[n] = max(mx[ls], mx[rs]);
	mn[n] = min(mn[ls], mn[rs]);
}
int askl(int n, int l, int r, int L, int k) {
	if(mn[n] >= k) return 0;
	int mid = (l + r) >> 1, res = 0;
	if(r <= L) {
		if(l == r) return l;
		if(mn[rs] < k) return askl(rs, mid + 1, r, L, k);
		else return askl(ls, l, mid, L, k);
	}
	if(L > mid) res = askl(rs, mid + 1, r, L, k);
	return res ? res : askl(ls, l, mid, L, k);
}
int askr(int n, int l, int r, int R, int k) {
	if(mx[n] < k) return 0;
	int mid = (l + r) >> 1, res = 0;
	if(l >= R) {
		if(l == r) return l;
		if(mx[ls] >= k) return askr(ls, l, mid, R, k);
		else return askr(rs, mid + 1, r, R, k);
	}
	if(R <= mid) res = askr(ls, l, mid, R, k);
	return res ? res : askr(rs, mid + 1, r, R, k);
}
bool solve() {
	if(F(1, 1) == 2 || F(a, b) == 2 || F(1, 1) != F(a, b)) return 0;
	int c = a, d = b;
	if(!F(1, 1)) swap(s, t), swap(c, d);
	build(1, 1, d);
	int now = 1;
	rep(i, 1, c) {
		if(s[i] <= t[now]) {
			now = askl(1, 1, d, now, s[i]);
			if(!now) return 0;
		}
		else {
			now = askr(1, 1, d, now, s[i]) - 1;
			if(now == -1) now = d;
		}
	}
	return now == d;
}

signed main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> TT >> a >> b >> T;
	rep(i, 1, a) cin >> c[i];
	rep(i, 1, b) cin >> d[i];
	rep(i, 1, a) s[i] = c[i];
	rep(i, 1, b) t[i] = d[i];
	cout << solve();
	int x, y, z, w;
	while(T--) {
		// cerr << T << endl;
		rep(i, 1, a) s[i] = c[i];
		rep(i, 1, b) t[i] = d[i];
		cin >> x >> y;
		rep(i, 1, x) {
			cin >> z >> w;
			s[z] = w;
		}
		rep(i, 1, y) {
			cin >> z >> w;
			t[z] = w;
		}
		cout << solve();
	}
	cerr << endl << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}