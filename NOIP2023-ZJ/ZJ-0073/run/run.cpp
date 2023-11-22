#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

#define int long long

using namespace std;

bool bg;

const int N = 1e5 + 5, NINF = 0xcfcfcfcfcfcfcfcf;
int TP;

struct node{
	int x, y, v;
	bool operator < (const node &b) const{
		if(x != b.x) return x < b.x;
		return y < b.y;
	}
}q[N];

int n, m, k, d;

namespace p1{
	const int N = 1e3 + 5;
	
	int dp[N][N];
	
	inline void main() {
		memset(dp, 0xcf, sizeof dp);
		
		dp[0][0] = 0;
		int pos = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j <= k;j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
			int sum = 0;
			while(pos <= m && q[pos].x < i) pos++;
			for(int j = 1;j <= k;j++) {
				while(pos <= m && q[pos].x == i && q[pos].y <= j) sum += q[pos++].v;
				dp[i][j] = dp[i - 1][j - 1] - d + sum;
			}
		}
		int ans = 0;
		for(int i = 0;i <= k;i++) ans = max(ans, dp[n][i]);
		cout << ans << '\n';
	}//O(nk+m)*q
}

namespace p2{
	inline void main() {
		int ans = 0;
		for(int i = 1;i <= m;i++) if(q[i].y <= k) ans += max(q[i].v - q[i].y * d, 0ll);
		cout << ans << '\n';
	}
}

namespace p3{
	int dp[N][2];
	
	inline void main() {
		memset(dp, 0xcf, sizeof dp);
		dp[1][0] = 0;
		if(q[1].y <= k) dp[1][1] = q[1].y * d;
		for(int i = 2;i <= m;i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			if(q[i].y <= k) dp[i][1] = max(dp[i - 1][0] - q[i].y * d, dp[i - 1][1] - min(q[i].x - q[i - 1].x, q[i].y) * d) + q[i].v;
		}
		cout << max(dp[m][0], dp[m][1]) << '\n';
	}
}

inline void solve() {
	cin >> n >> m >> k >> d;
	for(int i = 1;i <= m;i++) cin >> q[i].x >> q[i].y >> q[i].v;
	sort(q + 1, q + m + 1);
	if(n <= 1000 && m <= 100000) return p1::main();//36pts
	if(TP == 17 || TP == 18) return p2::main();//B 44pts
	if(19 <= TP && TP <= 21) return p3::main();//C 56pts
	
}

bool ed;
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int CAS;
	cin >> TP >> CAS;
	while(CAS--) solve();
	return 0;
}//made by luogu:734497 star_of_cloud
