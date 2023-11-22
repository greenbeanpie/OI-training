#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 2;
const int INF = 0x3f3f3f3f;

int o, T;

namespace bf{
	int n, m, k, d;
	
	int dp[N][N], mx[N], dy[N], c[N], v[N];
	
	void solve(){
		cin >> n >> m >> k >> d;
		k = min(k, n);
		for(int i = 1; i <= m; i ++){
			cin >> dy[i] >> c[i] >> v[i];
		}
		for(int i = 1; i <= k; i ++){
			dp[0][i] = -INF;
		}
		int p = 1;
		for(int i = 1; i <= n; i ++){
			dp[i][0] = mx[i - 1];
			mx[i] = dp[i][0];
			int tmp = 0;
			for(int j = 1; j <= min(i, k); j ++){
				while(p <= m && dy[p] == i && c[p] == j){
					tmp += v[p];
					p ++;
				}
				dp[i][j] = dp[i - 1][j - 1] - d + tmp;
				mx[i] = max(mx[i], dp[i][j]);
			}
		}
		cout << mx[n] << '\n';
	}
}

signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	cin >> o >> T;
	while(T --)  bf::solve();

	return 0;
}
