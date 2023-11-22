#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int T, n, m, K, D, x[N], y[N], z[N], lid[N], rid[N], pos[N];
ll f[N], g[N], mx, tree[N<<2], tag[N<<2];
int read() {
	int s = 0; char ch = getchar();
	while (! isdigit(ch)) ch = getchar();
	while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s;
}
void build(int p, int l, int r) {
	tree[p] = tag[p] = 0;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(p<<1, l, mid), build(p<<1|1, mid+1, r);
}
void pushdown(int p) {
	if (tag[p]) {
		tree[p<<1] += tag[p], tag[p<<1] += tag[p];
		tree[p<<1|1] += tag[p], tag[p<<1|1] += tag[p];
		tag[p] = 0;
	}
}
void update(int p, int l, int r, int x, int y, ll z) {
	if (l == x && r == y) return void ((tree[p] += z, tag[p] += z));
	int mid = l + r >> 1; pushdown(p);
	if (y <= mid) update(p<<1, l, mid, x, y, z);
	else if (x > mid) update(p<<1|1, mid+1, r, x, y, z);
	else update(p<<1, l, mid, x, mid, z), update(p<<1|1, mid+1, r, mid+1, y, z);
	tree[p] = max(tree[p<<1], tree[p<<1|1]);
}
ll query(int p, int l, int r, int x, int y) {
	if (l == x && r == y) return tree[p];
	int mid = l + r >> 1; pushdown(p);
	if (y <= mid) return query(p<<1, l, mid, x, y);
	else if (x > mid) return query(p<<1|1, mid+1, r, x, y);
	else return max(query(p<<1, l, mid, x, mid), query(p<<1|1, mid+1, r, mid+1, y));
}
int main() {
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	read(), T = read();
	while (T --) {
		n = read(), m = read(), K = read(), D = read();
		for (int i=1; i<=m; i++)
			x[i] = read(), y[i] = x[i] - read() + 1, swap(x[i], y[i]), z[i] = read(), lid[i] = rid[i] = i;
		sort (lid+1, lid+m+1, [] (const int &i, const int &j) { return x[i] < x[j]; });
		sort (rid+1, rid+m+1, [] (const int &i, const int &j) { return y[i] < y[j]; });
		for (int i=m, j=m; i; i--) {
			while (x[lid[i]] ^ x[lid[j]]) j --;
			pos[lid[i]] = j;
		}
		mx = 0, build(1, 1, m);
		for (int p=1, q=1, l=1, r=0; p<=m || q<=m; )
			if (q > m || p <= m && y[rid[q]] >= x[lid[p]] - 1)
				g[p] = mx + 1ll * D * (x[lid[p]] - 1), p ++;
			else {
				while (l <= m && y[rid[q]] - K >= x[lid[l]])
					l ++;
				while (r < m && x[lid[r+1]] <= y[rid[q]])
					r ++, update(1, 1, m, r, r, g[r]);
				update(1, 1, m, 1, pos[rid[q]], z[rid[q]]);
				mx = max(mx, f[q] = l > r ? 0 : query(1, 1, m, l, r) - 1ll * D * y[rid[q]]);
				q ++;
			}
		printf ("%lld\n", mx);
	}
}
// farewell.