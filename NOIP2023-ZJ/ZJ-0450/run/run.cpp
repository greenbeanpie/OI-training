#include <bits/stdc++.h>
using namespace std;

#define N 1003
int n,m,k,d;
struct activity {
	long long y,v;
	activity() {
		
	}
	activity(long long y, long long v) : y(y), v(v) {
		
	}
};
bool operator < (activity a, activity b) {
	if (a.y == b.y) return a.v < b.v;
	return a.y < b.y;
}
vector<activity> ac[N];
long long dp[N][N];

long long maxi(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	int c,t,xi,yi,vi;
	cin>>c>>t;
	for (int groups = 0; groups < t; groups++) {
		memset(dp, 0, sizeof(dp));	// May optimize
		cin>>n>>m>>k>>d;
		for (int i = 0; i < m; i++) {
			cin>>xi>>yi>>vi;
			ac[xi].push_back(activity(yi,vi));
		}
		for (int i = 1; i <= n; i++) {
			if (ac[i].size()) {
				sort(ac[i].begin(),ac[i].end());
				long long sum = 0;
				for (int j = 0; j < ac[i].size(); j++) {
					sum += ac[i][j].v;
					ac[i][j].v = sum;
				}
				for (int j = 1; j <= m; j++) {
					// Considering boosting,
//					long long maxat = LLONG_MIN;
//					for (int k = 1; k <= m; k++) {
//						if (dp[i-k][k] > maxat) maxat = dp[i-k][k];
//					}
					long long maxat = dp[i-1][j-1];	// ?
					int pos = lower_bound(ac[i].begin(),ac[i].end(),activity(j, -1)) - ac[i].begin();
					if (pos < 0) dp[i][j] = maxi(maxat - k, dp[i-1][j]);
					if (ac[i][pos].y > j) pos--;
					if (pos < 0) dp[i][j] = maxi(maxat - k, dp[i-1][j]);
					else dp[i][j] = maxi(maxat + ac[i][pos].v - k, dp[i-1][j]);
					//dp[i][j] = maxat + 
				}
			} else {
				// The same as the above.
				for (int j = 1; j <= m; j++)  dp[i][j] = maxi(dp[i-1][j], dp[i-1][j-1] - k);
			}
		}
		cout<<dp[n][m]<<'\n';
	}
	cout<<flush;
	
	return 0;
}