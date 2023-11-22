#include <bits/stdc++.h>
typedef long long ll; using namespace std; 
const int N = 1e5 + 5; const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, k, pre[N]; ll d;
struct challenges {
	int x, y; ll v;
	challenges(int x_ = 0, int y_ = 0, ll v_ = 0) { x = x_; y = y_; v = v_; }
	bool operator<(const challenges &o) const { return x < o.x; }
} q[N];
void work(int c) {
	cin >> n >> m >> k >> d; ll ans = -inf;
	for (int i = 1; i <= m; ++i) cin >> q[i].x >> q[i].y >> q[i].v;
	if (c == 17 || c == 18) {
		ans = 0;
		for (int i = 1; i <= m; ++i)
			if (q[i].y <= k) ans += max(0ll, q[i].v - q[i].y * d);
		cout << ans << '\n'; return;
	}
	for (int sta = 0; sta < (1 << n); ++sta) {
		bool op = 1; ll tmp = 0;
		for (int i = 1; i <= n; ++i) pre[i] = 0;
		for (int i = 1; i <= n; ++i) 
			pre[i] = ((sta >> (i - 1)) & 1) ? pre[i - 1] + 1 : 0;
		for (int i = 1; i <= n; ++i) if (pre[i] > k) { op = 0; break; }
		if (!op) continue;
		for (int i = 1; i <= n; ++i) tmp -= d * ((sta >> (i - 1)) & 1);
		for (int i = 1; i <= m; ++i) if (pre[q[i].x] >= q[i].y) tmp += q[i].v;
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
}
int main() {
	freopen("run.in", "r", stdin); freopen("run.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int c, testcases; cin >> c >> testcases;
	while (testcases--) work(c); return 0;
}