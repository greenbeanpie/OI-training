#include<iostream>
#include<algorithm>
#include<vector>
int L[100005], R[100005], V[100005];
using ll = long long; ll A[800005], tag[800005];
void pull(int u) { A[u] = std::max(A[u << 1], A[u << 1 | 1]); }
void push(int u) {
	A[u << 1] += tag[u], A[u << 1 | 1] += tag[u];
	tag[u << 1] += tag[u], tag[u << 1 | 1] += tag[u];
	tag[u] = 0;
}
void build(int u, int l, int r) {
	tag[u] = 0, A[u] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void add(int u, int l, int r, int L, int R, ll x) {
	if (l >= L && r <= R) return tag[u] += x, A[u] += x, void();
	int mid = (l + r) >> 1; push(u);
	if (L <= mid) add(u << 1, l, mid, L, R, x);
	if (mid < R) add(u << 1 | 1, mid + 1, r, L, R, x);
	return pull(u);
}
ll ask(int u, int l, int r, int L, int R) {
	if (L > R) return 0;
	if (l >= L && r <= R) return A[u];
	int mid = (l + r) >> 1; push(u);
	if (L > mid) return ask(u << 1 | 1, mid + 1, r, L, R);
	if (R <= mid) return ask(u << 1, l, mid, L, R);
	return std::max(ask(u << 1, l, mid, L, R), ask(u << 1 | 1, mid + 1, r, L, R));
}
void solve() {
	int n, m, k, d, tot;
	static std::vector<int> p; p.clear();
	static std::vector<int> C[200005];
	std::cin >> n >> m >> k >> d;
	for (int i = 1; i <= m; i++) {
		int x, y; std::cin >> x >> y >> V[i];
		L[i] = x - y + 1, R[i] = x;
	}
	if (m == 0) return std::cout << "0\n", void();
	for (int i = 1; i <= m; i++) {
		p.push_back(L[i] - 1), p.push_back(R[i]);
	}
	std::sort(p.begin(), p.end());
	tot = std::unique(p.begin(), p.end()) - p.begin();
	while (p.size() > tot) p.pop_back();
	for (int i = 1; i <= m; i++) {
		L[i] = std::lower_bound(p.begin(), p.end(), L[i] - 1) - p.begin();
		R[i] = std::lower_bound(p.begin(), p.end(), R[i]) - p.begin();
//		std::cerr << L[i] << " " << R[i] << std::endl;
	}
	for (int i = 0; i < tot; i++) C[i].clear();
	for (int i = 1; i <= m; i++) C[R[i]].push_back(i);
	long long ans = 0; build(1, 0, tot - 1);
//	for (int i = 0; i < tot; i++) std::cerr << p[i] << " \n"[i == tot - 1];
	for (int i = 0; i < tot; i++) {
		add(1, 0, tot - 1, i, i, ans + 1ll * p[i] * d);
		for (int j : C[i]) {
			add(1, 0, tot - 1, 0, L[j], V[j]);
		}
		int t = std::lower_bound(p.begin(), p.end(), p[i] - k) - p.begin();
		ans = ask(1, 0, tot - 1, t, i) - 1ll * p[i] * d;
	}
	std::cout << ans << '\n';
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int c, t;
	std::cin >> c >> t;
	while (t--) solve();
}
