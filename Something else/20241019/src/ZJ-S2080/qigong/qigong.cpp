#include <bits/stdc++.h> 
using namespace std;

const int N = 70 + 2;
const int M = 150 + 2;
const int INF = 0x3f3f3f3f;

int n, s;
int a[N];
int dp[N][M * N];
set <int> rg[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	freopen("qigong.in", "r", stdin);
	freopen("qigong.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		s += a[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
//	rg[0].insert(0);
	int mx = 0;
	for(int i = 1; i <= n; i ++){
		int ans = INF;
//		for(int j : rg[i - 1]){
		for(int j = 0; j <= s; j ++){
			for(int k = max(0, a[i] - j); k <= a[i]; k ++){
//				rg[i].insert(k + j >> 1);
				dp[i][k + j >> 1] = min(dp[i][k + j >> 1], dp[i - 1][j] + k);
//				cerr << i << ' ' << j << ' ' << k << ' ' << dp[i][k + j >> 1] << '\n';
				ans = min(ans, dp[i][k + j >> 1]);
			}
			dp[i][j + (a[i] >> 1)] = min(dp[i][j + (a[i] >> 1)], dp[i - 1][j] + a[i]);
//			rg[i].insert(j + (a[i] >> 1));
		}
		cout << ans << ' ';
//		mx = mx + (a[i] >> 1);
//		cerr << ans << ' ';
//		cerr << i << " rg: ";
//		for(int t : rg[i])  cerr << t << ' ';  cerr << '\n';
	}
	
	return 0;
}
