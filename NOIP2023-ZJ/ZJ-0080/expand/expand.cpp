#include <bits/stdc++.h>

#define i64 long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

const int N = 5e5 + 5;

int n, m, q;
int x[N], y[N], s[N], t[N];
bool dp[3005][3005];

bool solve(int *x, int *y) {
	rep(i, 0, n) rep(j, 0, m) dp[i][j] = false;
	
	dp[0][0] = true;
	
	if(x[1] < y[1] && x[n] < y[m]) {
		rep(i, 1, n) rep(j, 1, m) {
			if(x[i] >= y[j]) {
				dp[i][j] = false;
				continue;
			}
			
			dp[i][j] = (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]);
		}
	}
	else if(x[1] > y[1] && x[n] > y[m]) {
		rep(i, 1, n) rep(j, 1, m) {
			if(x[i] <= y[j]) {
				dp[i][j] = false;
				continue;
			}
			
			dp[i][j] = (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]);
		}
	}
	return dp[n][m];
}

int main() {
	
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int o;
	cin >> o >> n >> m >> q;
	rep(i, 1, n) cin >> x[i];
	rep(i, 1, m) cin >> y[i];
	
	cout << solve(x, y);

	while(q--) {
		rep(i, 1, n) s[i] = x[i];
		rep(i, 1, m) t[i] = y[i];
		
		int kx, ky;
		cin >> kx >> ky;
		
		rep(i, 1, kx) {
			int px, vx; cin >> px >> vx;
			s[px] = vx;
		}
		
		rep(i, 1, ky) {
			int py, vy; cin >> py >> vy;
			t[py] = vy;
		}
		
		cout << solve(s, t);
	}
	
	return 0;
}
