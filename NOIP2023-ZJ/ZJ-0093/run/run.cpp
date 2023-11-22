#include<bits/stdc++.h>
using namespace std;

#define Reimu inline void
#define Marisa inline int

typedef long long LL;
typedef unsigned long long ULL;

typedef pair<int, int> Pii;
#define fi first
#define se second

const int N = 100010;

struct Data { int x, y, v; } a[N];

int n, m, K, d;
LL dp[N];

Reimu Sakuya() {
	cin >> n >> m >> K >> d;
	for (int i = 1; i <= m; ++i) cin >> a[i].x >> a[i].y >> a[i].v;
	sort(a + 1, a + m + 1, [&](Data A, Data B) {
		return A.x < B.x;
	});
	LL f = 0, g = 0;
	for (int i = 1; i <= m; ++i) {
		int pr = a[i - 1].x, cr = a[i].x;
		if (pr + 1 > cr - K) dp[pr + 1] = g - d * (cr - pr);
		for (int j = max(cr - K + 1, pr + 2); j <= cr; ++j) dp[j] = f - d * (cr - j + 1);
		for (int j = max(cr - K + 1, 1); j <= pr; ++j) dp[j] -= d * (cr - pr);
		for (int j = max(cr - K + 1, 1); j <= cr - a[i].y + 1; ++j) dp[j] += a[i].v;
		if (cr != pr) g = f;
		for (int j = max(cr - K + 1, 1); j <= cr; ++j) f = max(f, dp[j]);
	}
	cout << f << '\n';
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _, T; cin >> _ >> T; while (T--) Sakuya();
	return 0;
}

