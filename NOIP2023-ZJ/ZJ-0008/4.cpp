#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
#define vi vector<int>
#define PB emplace_back
#define siz(a) ((int) a.size())

const int N = 4e5;
int a, b, c, d, T, TT, p[N + 5], top, w[N * 4 + 5], f[N + 5], g[N + 5], lzy[N * 4 + 5];
struct pii {
	int x, y, z;
} q[N + 5];

#define ls n << 1
#define rs n << 1 | 1
void upd(int n, int k) {
	w[n] += k;
	lzy[n] += k;
}
void dw(int n) {
	upd(ls, lzy[n]), upd(rs, lzy[n]);
	lzy[n] = 0;
}
void add(int n, int l, int r, int L, int R, int k) {
	if(l >= L && r <= R) return upd(n, k);
	dw(n);
	int mid = (l + r) >> 1;
	if(L <= mid) add(ls, l, mid, L, R, k);
	if(mid < R) add(rs, mid + 1, r, L, R, k);
	w[n] = max(w[ls], w[rs]);
}
int ask(int n, int l, int r, int k) {
	if(p[l] >= k) return w[n];
	dw(n);
	int mid = (l + r) >> 1, res = ask(rs, mid + 1, r, k);
	if(k <= p[mid]) res = max(res, ask(ls, l, mid, k));
	return res;
}

signed main() {
	freopen("run6.in", "r", stdin);
	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> TT >> T; T--; ) {
		top = 0;
		memset(w, 0, sizeof(w));
		memset(lzy, 0, sizeof(lzy));
		cin >> a >> b >> c >> d;
		p[++top] = 1, p[++top] = a;
		int x, y, z;
		rep(i, 1, b) {
			cin >> x >> y >> z;
			y = x - y + 1;
			if(y < 1) z = 0;
			q[i] = pii {y, x, z};
			p[++top] = y;
			p[++top] = y - 1;
			p[++top] = x;
			if(x != a) p[++top] = x + 1;
		}
		sort(p + 1, p + top + 1);
		top = unique(p + 1, p + top + 1) - p - 1;
		sort(q + 1, q + b + 1, [&] (pii x, pii y) {
			return x.y < y.y;
		});
		int j = 1;
		rep(i, 1, top) {
			g[i] = max(g[i - 1], f[i - 1]);
			add(1, 1, top, i, i, p[i] * d + g[i - 1]);
			for(; j <= b && q[j].y == p[i]; ++j) {
				int x = lower_bound(p + 1, p + top + 1, q[j].x) - p, z = q[j].z;
				add(1, 1, top, 1, x, z);
			}
			f[i] = ask(1, 1, top, p[i] - c + 1) - (p[i] + 1) * d;
		}
		cout << max(f[top], g[top]) << '\n';
	}
	// cerr << endl << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}