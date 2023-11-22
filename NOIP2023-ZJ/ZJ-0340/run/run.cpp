#include <vector>
#include <utility>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define N 1005
#define int long long
using namespace std;

inline int read(){
	int ans = 0;
	char ch = getchar();
	while(!isdigit(ch)){
		ch = getchar();
	}
	while(isdigit(ch)){
		ans *= 10;
		ans += ch - 48;
		ch = getchar();
	}
	return ans;
}

int c, t, n, m, maxd, d, give[N][N], dp[2][N];
vector<pair<int, int>> v[N];

signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int x, y, z;
	c = read(), t = read();
	while(t--){
		n = read(), m = read(), maxd = read(), d = read();
		for(int i = 0; i <= 1; i++){
			for(int k = 0; k <= maxd; k++){
				dp[i][k] = -1000000000000000000ll;
			}
		}
		for(int i = 1; i <= n; i++){
			v[i].clear();
		}

		for(int i = 1; i <= m; i++){
			x = read(), y = read(), z = read();
			v[x].emplace_back(make_pair(y, z));
		}

		for(int i = 1; i <= n; i++){
			sort(v[i].begin(), v[i].end());
			int now = 0, pos = 0;
			for(int j = 0; j <= maxd; j++){
				while(pos < v[i].size() && v[i][pos].first == j){
					now += v[i][pos].second;
					pos++;
				}
				give[i][j] = now;
				// printf("%d ", give[i][j]);
			}
			// puts("");
		}

		dp[0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int k = 0; k <= maxd; k++){//lay
				dp[i & 1][0] = max(dp[i & 1][0], dp[(i - 1) & 1][k]);
			}
			for(int k = 1; k <= maxd; k++){//run
				dp[i & 1][k] = dp[(i - 1) & 1][k - 1] - d + give[i][k];
			}
		}

		int ans = 0;
		for(int k = 0; k <= maxd; k++){
			ans = max(ans, dp[n & 1][k]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}