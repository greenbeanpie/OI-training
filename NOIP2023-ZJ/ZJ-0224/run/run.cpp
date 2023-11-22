#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

const int maxn = 1e3 + 10, maxN = 1e5 + 10;

int n, m, k, d;
int dp[maxn][maxn], x[maxN], y[maxN], v[maxN];
vector<pii> t[maxn];

bool cmp(pii a, pii b) { return a.first < b.first; }

void do36() {
	int ans = 0;
	
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= k; j ++) dp[i][j] = 0;
	
	for (int i = 1; i <= m; i ++)
		scanf("%d %d %d", &x[i], &y[i], &v[i]),
		t[x[i]].emplace_back(make_pair(y[i], v[i]));
	
	for (int i = 1; i <= n; i ++) {
		int p = 0, lim = t[i].size(), val = 0;
		sort(t[i].begin(), t[i].end(), cmp);
		
		for (int j = 0; j <= min(i, k); j ++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
		for (int j = 1; j <= min(i, k); j ++) {
			while (p != lim && t[i][p].first <= j) val += t[i][p].second, p ++;
			dp[i][j] = dp[i - 1][j - 1] - d + val;
			ans = max(ans, dp[i][j]);
		}
		
		ans = max(ans, dp[i][0]);
	}
	
	for (int i = 1; i <= n; i ++) t[i].clear();
	
	printf("%lld\n", ans);
}

void do8() {
	int ans = 0;
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d %d", &x[i], &y[i], &v[i]);
		if (y[i] <= k) ans += max(0ll, v[i] - y[i] * d);
	}
	
	printf("%lld\n", ans);
}

void work() {
	scanf("%lld %lld %lld %lld", &n, &m, &k, &d);
	if (n <= 1e3) do36(); else do8();
}

signed main() {
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	int id, T;
	scanf("%lld %lld", &id, &T);
	while (T --) work();
	
}


// 求求了不要挂分...
// 44 pts (36 + 8)
