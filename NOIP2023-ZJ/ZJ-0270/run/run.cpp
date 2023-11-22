#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1e5 + 5;
int C, T, n, m, k, tot;
long long d;
vector< pair<long long, long long> > v[N];
long long dp[N][N];
long long X[N], Y[N], Z[N], f[N], summ[N];
void solve1() {
	while (T--) {
		cin >> n >> m >> k >> d;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= m; i++) {
			long long x, y, z; cin >> x >> y >> z;
			v[x].push_back(make_pair(y, z));
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				dp[i][j] = -3e18;
		dp[0][0] = 0;
		long long lst = 0;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = lst;
			for (int j = 1; j <= min(i, k); j++) {
				int sum = 0;
				for (int pp = 0; pp < (int)(v[i].size()); pp++) {
					pair<long long, long long> val = v[i][pp];
					if (val.first <= j) sum += val.second;
				}
				dp[i][j] = dp[i - 1][j - 1] - d + sum;
				lst = max(lst, dp[i][j]); 
			}
		}
		cout << lst << endl;
	}
	return;
}
void solve2() {
	while (T--) {
		scanf("%d%d%d%lld", &n, &m, &k, &d);
		long long ans = 0; tot = m; m = 0;
		for (int i = 1; i <= tot; i++) {
			scanf("%lld%lld%lld", &X[i], &Y[i], &Z[i]);
			long long tt = X[i] - Y[i] + 1;
			Y[i] = X[i]; X[i] = tt; f[i] = 0;
			if (Z[i] - (Y[i] - X[i] + 1) * d > 0 && Y[i] - X[i] + 1 <= (long long)(k)) {
				X[++m] = X[i]; Y[m] = Y[i]; Z[m] = Z[i];
			}
		}
		for (int i = 1; i <= m; i++) summ[i] = summ[i - 1] + Z[i];
		Y[0] = -1;
		int now = 0;
		for (int i = 1; i <= m; i++) {
			if (Y[i - 1] + 1 < X[i]) {
				now = i;
				f[i] = f[i - 1] + Z[i] - (Y[i] - X[i] + 1) * d;
			} else {
				while (now < i && (Y[i] - X[now] + 1) > (long long)(k)) now++;
				if (now == 1) f[i] = summ[i] - (Y[i] - X[1] + 1) * d;
				else {
					f[i] = f[i - 1];
					if (Y[now - 1] + 1 == X[now]) f[i] = max(f[i], f[now - 2] + (summ[i] - summ[now - 1]) - (Y[i] - X[now] + 1) * d);
					else f[i] = max(f[i], f[now - 1] + (summ[i] - summ[now - 1]) - (Y[i] - X[now] + 1) * d);
				}
			}
			ans = max(ans, f[i]);
		}
		cout << ans << endl;
	}
	return;
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> C >> T;
	if (C <= 7) solve1();
	else solve2();
	//cout << 1e3 * clock() / CLOCKS_PER_SEC << "ms";
	return 0;
}