#include <bits/stdc++.h>
using namespace std;

namespace solve1 {
	using ll = long long;
	ll f[1010][1010];
	int n, m, k; ll d;
	ll sum[1010]; vector<pair<int, ll> > ch[1010];
	void main() {
		cin >> n >> m >> k >> d;
		memset(f, 0xcf, sizeof f);
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) ch[i].clear();
		for (int i = 1; i <= m; i++) {
			static int x, y, z; cin >> x >> y >> z;
			ch[x].emplace_back(y, z);
		}
		for (int i = 1; i <= n; i++) {
			memset(sum, 0, sizeof sum);
			for (pair<int, ll> x : ch[i])
				sum[x.first] += x.second;
			for (int j = 1; j <= k; j++) sum[j] += sum[j - 1];
			for (int j = 0; j <= k; j++) f[i][0] = max(f[i - 1][j] + sum[0], f[i][0]);
			for (int j = 1; j <= k; j++) {
				f[i][j] = f[i - 1][j - 1] - d + sum[j];
			}
		}
		ll Ans = 0;
		for (int i = 0; i <= k; i++) Ans = max(Ans, f[n][i]);
		cout << Ans << endl;
	}
}

namespace solve2 {
	using ll = long long;
	ll Ans, d; int n, m, k;

	void main() {
		cin >> n >> m >> k >> d; Ans = 0;
		for (int i = 1; i <= m; i++) {
			static ll r, l, v; cin >> r >> l >> v;
			if (l * d < v) Ans += v - l * d;
		}
		cout << Ans << endl;
	}
}

int c, t;

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		if (c == 17 || c == 18) solve2::main();
		else solve1::main(); 
	}
	return 0;
}

// AFOed on 2023.11.18 12:52.
// GoodBye OI. 
// 最后还是这么菜呢。也没有明年了。随缘吧。
// 100 + 60 + 10 + 36. fst 也无所谓了。
