#include <bits/stdc++.h>
#define int long long
using namespace std;
int lsh[200005], tot;
inline void trans (int &x) {
	x = lower_bound(lsh + 1, lsh + tot + 1, x) - lsh;
}
int tr[200005], n;
inline int lowbit (int x) {
	return x & (-x);
}
void update (int x, int y) {
	while (x <= n) {
		tr[x] += y;
		x += lowbit(x);
	}
	return;
}
int query (int x) {
	int res = 0;
	while (x) {
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}
int Q (int l, int r) {
	return query(r) - query(l-1);
}
struct Challenge {
	int l, r, w;
	bool operator < (const Challenge &o) const {
		if (r == o.r)
			return l < o.l;
		return r < o.r;
	}
}c[200005];
int f[200005], s[200005], d;
inline int val (int i) {
	if (i == 1)
		return d;
	return f[i-2] - s[i-1] + i * d;
}
int q[200005], h, t;
inline int read () {
	int res = 0, sym = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			sym = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res<<3) + (res<<1) + c - '0';
		c = getchar();
	}
	return sym * res;
}
signed main () {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int Case = read(), T = read();
	while (T--) {
		n = read();
		int m = read(), len = read();
		d = read();
		tot = 0;
		for (int i = 1; i <= m; i++) {
			int x = read(), y = read(), z = read();
			c[i].l = x - y + 1;
			c[i].r = x;
			c[i].w = z;
		}
		sort(c + 1, c + m + 1);
		int ans = 0;
		for (int i = 1, j = 1; i <= n; i++) {
			while (j <= m && c[j].r <= i) {
				update(c[j].l, c[j].w);
				j++;
			}
			f[i] = f[i-1];
			int t = -1;
			for (int j = 1; j <= i; j++) {
				if (j <= i - len)
					continue;
				if (j == 1) {
					f[i] = max(f[i], Q(1, i) - i * d);
					continue;
				}
				if (f[i] < f[j-2] + Q(j, i) - (i-j+1) * d) {
					t = j;
				}
				f[i] = max(f[i], f[j-2] + Q(j, i) - (i-j+1) * d);
			}
			//printf("%lld:%lld %lld\n", i, t, f[i]);
			ans = max(f[i], ans);
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++) {
			tr[i] = 0;
		}
	}
	return 0;
}