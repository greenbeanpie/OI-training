#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
	return x * f;
}

const int N = 2050, M = 5e5 + 10;

int n, m, q, a[M], b[M];

bool f[N][N];

vector<pii> vecx, vecy;

/*struct SegmentTree {
	int mx[M << 2], mn[M << 2];
	#define ls u << 1
	#define rs u << 1 | 1
	
	inline void pushup(int u) {mn[u] = min(mn[ls], mn[rs]); mx[u] = max(mx[ls], mx[rs]);}
	
	inline void modify(int u, int l, int r, int x, int v) {
		if (l == r) return mx[u] = mn[u] = v, void();
		int mid = l + r >> 1;
		x <= mid ? modify(ls, l, mid, x, v) : modify(rs, mid + 1, r, x, v);
		pushup(u); 
 	}

	inline void build(int u, int l, int r, int op) {
		if (l == r) return op ? mx[u] = mn[u] = b[l] : mx[u] = mn[u] = a[l], void();
		int mid = l + r >> 1;
		build(ls, l, mid, op); build(rs, mid + 1, r, op);
		pushup(u);
	}
	
}tr[2]; */

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int tid = read(); n = read(); m = read(); q = read();
	for (int i = 1; i <= n; ++ i) a[i] = read();
	for (int i = 1; i <= m; ++ i) b[i] = read();
	if (tid <= 7) {
		f[1][1] = 1;
		bool tp = a[1] < b[1];
		if (a[1] == b[1]) {putchar('0');} 
		else {
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= m; ++ j) {
					if (a[i+1] != b[j]) {
						bool flg = a[i+1] < b[j];
						if (tp == flg)
							f[i+1][j] |= f[i][j];
					}
					if (a[i+1] != b[j+1]) {
						bool flg = a[i+1] < b[j+1];
						if (tp == flg)
							f[i+1][j] |= f[i][j];
					}
					if (a[i] != b[j+1]) {
						bool flg = a[i] < b[j+1];
						if (tp == flg)
							f[i][j+1] |= f[i][j];
					}
	 			}
	 			if (f[n][m]) putchar('1');
	 			else putchar('0');
		}
		while (q --) {
			int kx = read(), ky = read();
			for (int i = 1, p, x; i <= kx; ++ i)
				p = read(), x = read(), vecx.pb(mp(p, a[p])), a[p] = x;
			for (int i = 1, p, x; i <= ky; ++ i)
				p = read(), x = read(), vecy.pb(mp(p, b[p])), b[p] = x;
			bool tp = a[1] < b[1];
			if (a[1] == b[1]) {putchar('0');} 
			else {
				memset(f, 0, sizeof f); f[1][1] = 1;
				for (int i = 1; i <= n; ++ i)
					for (int j = 1; j <= m; ++ j) {
						if (i < n && a[i+1] != b[j]) {
							bool flg = a[i+1] < b[j];
							if (tp == flg)
								f[i+1][j] |= f[i][j];
						}
						if (i < n && j < m && a[i+1] != b[j+1]) {
							bool flg = a[i+1] < b[j+1];
							if (tp == flg)
								f[i+1][j] |= f[i][j];
						}
						if (j < m && a[i] != b[j+1]) {
							bool flg = a[i] < b[j+1];
							if (tp == flg)
								f[i][j+1] |= f[i][j];
						}
	 				}
	 			if (f[n][m]) putchar('1');
	 			else putchar('0');
			}
			for (auto it : vecx)
				a[it.fi] = it.se;
			for (auto it : vecy)
				b[it.fi] = it.se;
			vecx.clear(); vecy.clear(); 
		}
	} else if (tid <= 14) {
		
	}
	return 0;
}
