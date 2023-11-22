#include <bits/stdc++.h>

#define i64 long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

const int N = 1e5 + 5;

struct Seg {
	int l, r;
	i64 v;
} seg[N];

int n, m, k;
i64 d;

namespace Subtask1 {

	static const int N = 1e3 + 5;
	static const i64 INF = LLONG_MAX / 4;
	
	i64 dp[N][N], mx[N], S[N];
	vector<pair<int, i64> > ch[N];
	
	void main() {
		
		rep(i, 1, n) rep(j, 0, k) dp[i][j] = -INF;
		rep(i, 1, n) ch[i].clear();
		
		rep(i, 1, m) ch[seg[i].r].push_back(make_pair(seg[i].l, seg[i].v));
		rep(i, 1, n) sort(ch[i].begin(), ch[i].end());
		
		rep(i, 1, n) {
			mx[i] = -INF;
			
			dp[i][0] = mx[i - 1];
			
			rep(j, 0, n) S[j] = 0;
			for(auto c : ch[i]) S[c.first] += c.second;
			rep(j, 1, n) S[j] += S[j - 1];
			
			rep(j, 1, k) {
				if(i - j < 0) break;
				i64 sum = S[i] - S[i - j];
				dp[i][j] = dp[i - 1][j - 1] + sum - d;
			}
			
			rep(j, 0, k) mx[i] = max(mx[i], dp[i][j]);
		}
		
		i64 ans = 0;
		rep(i, 0, k) ans = max(ans, dp[n][i]);
		
		cout << ans << "\n";	
	}
	
};

namespace SubtaskB {
	
	void main() {
		
		i64 ans = 0;
		rep(i, 1, m) {
			int l = seg[i].l, r = seg[i].r; i64 v = seg[i].v;
			if(r - l + 1 <= k) {
				ans += max(0ll, v - 1ll * (r - l + 1) * d);
			}
		}
		
		cout << ans << "\n";
	}
	
};

int main() {
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int o, T;
	cin >> o >> T;
	while(T--) {
		cin >> n >> m >> k >> d;
		rep(i, 1, m) {
			int x, y, v;
			cin >> x >> y >> v;
			seg[i].l = x - y + 1, seg[i].r = x; seg[i].v = v;
		}
		
		bool isSubB = true;
		rep(i, 1, m - 1) if(seg[i].r >= seg[i + 1].l) isSubB = false;
		
		if(isSubB) SubtaskB::main();
		else if(n <= 1000) Subtask1::main();
	}
	              
	return 0;
}
