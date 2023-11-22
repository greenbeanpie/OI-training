#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, m, c, q, X[N], Y[N], x[N], y[N], rt1[N], rt2[N], f[N << 1], idx1, idx2, dp[2010][2010];
int rd() {
	int res = 0; bool f = 0; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return f ? -res : res;
}
struct SegmentTree { int l, r, val; } t1[N << 6], t2[N << 6];
// t1 is for Max, t2 is for Min
void build1(int &p, int l, int r) {
	t1[p = ++ idx1] = {l, r, 0};
	if (l == r) return ;
	int mid = l + r >> 1;
	build1(t1[p].l, l, mid), build1(t1[p].r, mid + 1, r);
}
void build2(int &p, int l, int r) {
	t2[p = ++ idx2] = {l, r, m + 1};
	if (l == r) return ;
	int mid = l + r >> 1;
	build2(t2[p].l, l, mid), build2(t2[p].r, mid + 1, r);
}
void pushup1(int p) { t1[p].val = max(t1[t1[p].l].val, t1[t1[p].r].val); }
void insert1(int pre, int &p, int l, int r, int x, int k) {
	t1[p = ++ idx1] = t1[pre];
	if (l == r) { t1[p].val = max(t1[p].val, k); return ; }
	int mid = l + r >> 1;
	if (x <= mid) insert1(t1[pre].l, t1[p].l, l, mid, x, k);
	else insert1(t1[pre].r, t1[p].r, mid + 1, r, x, k);
	pushup1(p);
}
void pushup2(int p) { t2[p].val = min(t2[t2[p].l].val, t2[t2[p].r].val); }
void insert2(int pre, int &p, int l, int r, int x, int k) {
	t2[p = ++ idx2] = t2[pre];
	if (l == r) { t2[p].val = min(t2[p].val, k); return ; }
	int mid = l + r >> 1;
	if (x <= mid) insert2(t2[pre].l, t2[p].l, l, mid, x, k);
	else insert2(t2[pre].r, t2[p].r, mid + 1, r, x, k);
	pushup2(p);
}
int query1(int p, int l, int r, int x) {
	if (l == r) return t1[p].val;
	int mid = l + r >> 1;
	if (x <= mid) return query1(t1[p].l, l, mid, x);
	else return max(t1[t1[p].l].val, query1(t1[p].r, mid + 1, r, x));
}
int query2(int p, int l, int r, int x) {
	if (l == r) return t2[p].val;
	int mid = l + r >> 1;
	if (x > mid) return query2(t2[p].r, mid + 1, r, x);
	else return min(t2[t2[p].r].val, query2(t2[p].l, l, mid, x));
}
void lottle_swap(bool pd) {
	if (pd) return ;
	swap(n, m);
	for (int i = 1; i <= max(n, m); ++ i) swap(x[i], y[i]);
}
int lb(int r, int x) {
	int l = 0;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		if (f[mid] >= x) r = mid;
		else l = mid;
	}
	return r;
}
bool check() {
	bool pd = x[1] > y[1];
	lottle_swap(pd); int cnt = 0; idx1 = idx2 = 0;
	for (int i = 1; i <= n; ++ i) f[++ cnt] = x[i];
	for (int i = 1; i <= m; ++ i) f[++ cnt] = y[i];
	sort(f + 1, f + cnt + 1); cnt = unique(f + 1, f + cnt + 1) - f - 1;
	for (int i = 1; i <= n; ++ i) x[i] = lb(cnt + 1, x[i]);
	for (int i = 1; i <= m; ++ i) y[i] = lb(cnt + 1, y[i]);
	build1(rt1[0], 1, cnt); build2(rt2[m + 1], 1, cnt);
	for (int i = 1; i <= m; ++ i) insert1(rt1[i - 1], rt1[i], 1, cnt, y[i], i);
	for (int i = m; i >= 1; -- i) insert2(rt2[i + 1], rt2[i], 1, cnt, y[i], i);
	int cur = query2(rt2[1], 1, cnt, x[1]) - 1;
	for (int i = 2; i <= n; ++ i) {
		cur = query1(rt1[cur], 1, cnt, x[i] - 1); if (cur == 0) { lottle_swap(pd); return false; }
		cur = query2(rt2[cur], 1, cnt, x[i]) - 1;
	}
	lottle_swap(pd);
	return cur == m;
}
bool check_xty() {
	bool c1 = x[1] > y[1], cn = x[n] > y[m];
	if (c1 != cn) return false;
	dp[0][0] = true;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			dp[i][j] = (c1 ? x[i] > y[j] : x[i] < y[j]) && (dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1]);
	return dp[n][m];
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = rd(), n = rd(), m = rd(), q = rd();
	for (int i = 1; i <= n; ++ i) X[i] = x[i] = rd();
	for (int i = 1; i <= m; ++ i) Y[i] = y[i] = rd();
	cout << (max(n, m) <= 2000 ? check_xty() : check());
	while (q --) {
		for (int i = 1; i <= n; ++ i) x[i] = X[i];
		for (int i = 1; i <= m; ++ i) y[i] = Y[i];
		int kx = rd(), ky = rd();
		while (kx --) { int px = rd(), vx = rd(); x[px] = vx; }
		while (ky --) { int py = rd(), vy = rd(); y[py] = vy; }
		cout << (max(n, m) <= 2000 ? check_xty() : check());
	}
	return 0;
}
