#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 2;

int o, n, m, q, a[N], b[N];

namespace sub1{
	const int N = 2e3 + 2;
	
	int ta[N], tb[N], p, v, la = 1, lb = 1;
	bool dp[N][N];
	
	void solve1(int ka, int kb){
		for(int i = 1; i <= n; i ++)  ta[i] = a[i];
		for(int i = 1; i <= m; i ++)  tb[i] = b[i];
		for(int i = 1; i <= ka; i ++){
			cin >> p >> v;
			ta[p] = v;
		}
		for(int i = 1; i <= kb; i ++){
			cin >> p >> v;
			tb[p] = v;
		}
		if((ta[1] - tb[1]) * (ta[n] - tb[m]) <= 0){
			cout << "0";
			return ;
		}
		dp[1][1] = 1;
		bool f = (ta[1] < tb[1]);
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(i == 1 && j == 1)  continue;
				dp[i][j] = (ta[i] != tb[j] && (f ^ (ta[i] > tb[j])) && (dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j]));
			}
		}
		cout << dp[n][m];
	}
	
	void solve2(int ka, int kb){
		for(int i = 1; i <= n; i ++)  ta[i] = a[i];
		for(int i = 1; i <= m; i ++)  tb[i] = b[i];
		for(int i = 1; i <= ka; i ++){
			cin >> p >> v;
			ta[p] = v;
		}
		for(int i = 1; i <= kb; i ++){
			cin >> p >> v;
			tb[p] = v;
		}
		if((ta[1] - tb[1]) * (ta[n] - tb[m]) <= 0){
			cout << "0";
			return ;
		}
		dp[1][1] = 1;
		bool f = (ta[1] < tb[1]);
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(i == 1 && j == 1)  continue;
				dp[i][j] = (ta[i] != tb[j] && (f ^ (ta[i] > tb[j])) && (dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j]));
			}
		}
		cout << dp[n][m];
	}
	
	void main(){
		solve1(0, 0);
		for(int i = 1; i <= q; i ++){
			cin >> p >> v;
			solve2(p, v);
		}
	}
}

signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	               
	cin >> o >> n >> m >> q;
	for(int i = 1; i <= n; i ++)  cin >> a[i];
	for(int j = 1; j <= m; j ++)  cin >> b[j];
	sub1::main();

	return 0;
}
