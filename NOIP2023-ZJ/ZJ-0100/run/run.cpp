#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, T;
int n, m, k, d;
vector<pair<int, int> > t[1005];
vector<int> s[1005];
int dp[1005][2];
int jiang[1005][1005];
bool cmp(pair<int, int> x, pair<int, int> y){
	return x.first < y.first;
}
signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; i++){
			int x, y, v;
			scanf("%lld%lld%lld", &x, &y, &v);
			t[x].emplace_back(y, v);
		}
		for(int i = 1; i <= n; i++){
			sort(t[i].begin(), t[i].end(), cmp);
			if(t[i].size() == 0)continue;
			s[i].push_back(t[i][0].second);
			for(int j = 1; j < t[i].size(); j++){
				int last = s[i][j - 1];
				s[i].push_back(last + t[i][j].second);
			}
		}
		for(int len = 1; len <= k; len++){
			for(int l = 1; l + len - 1 <= n; l++){
				int r = l + len - 1;
				jiang[l][r] = jiang[l][r - 1];
				int ll = 0, rr = t[r].size() - 1, ans = -1;
				while(ll <= rr){
					int mid = (ll + rr) / 2;
					if(t[r][mid].first <= r - l + 1){
						ans = mid;
						ll = mid + 1;
					}else{
						rr = mid - 1;
					}
				}
				if(ans >= 0){
					jiang[l][r] += s[r][ans];
				}
			}
		}
		for(int i = 1; i <= n; i++){
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = -1e18;
			for(int j = 1; j <= min(k, i); j++){
				dp[i][1] = max(dp[i][1], jiang[i - j + 1][i] + dp[i - j][0] - d * j);
			}
		}
		printf("%lld\n", max(dp[n][0], dp[n][1]));
		for(int i = 0; i <= n; i++){
			t[i].clear();
			s[i].clear();
			dp[i][0] = dp[i][1] = 0;
			for(int j = 0; j <= n; j++){
				jiang[i][j] = 0;
			}
		}
	}
	return 0;
}

