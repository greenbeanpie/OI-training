#include<bits/stdc++.h>
using namespace std;
int c, n, m, q;
int x[500005], y[500005];
int px[500005], py[500005], vx[500005], vy[500005];
int dp[2005][2005];
int solve(){
	memset(dp, 0, sizeof(dp));
	if(x[1] < y[1]){
		dp[1][1] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(i == 1 && j == 1)continue;
				if(x[i] < y[j]){
					dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
				}
			}
		}
		return dp[n][m];
	}else if(x[1] > y[1]){
		dp[1][1] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(i == 1 && j == 1)continue;
				if(x[i] > y[j]){
					dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
				}
			}
		}
		return dp[n][m];
	}
	return 0;
}
int solve2(){
	int nowx = 1, nowy = 1;
	int mnx = x[1], mxy = y[1];
	while(1){
		int last_x = nowx, last_y = nowy;
		while(nowy < m){
			if(y[nowy + 1] > mnx)nowy++, mxy = max(mxy, y[nowy]);
			else break;
		}
		while(nowx < n){
			if(x[nowx + 1] < mxy)nowx++, mnx = min(mnx, x[nowx]);
			else break;
		}
		if(last_x == nowx && last_y == nowy){
			break;
		}
	}
	return nowx == n && nowy == m;
}
void go(){
	if(n <= 2000 && m <= 2000){
		printf("%d", solve());
	}else{
		printf("%d", solve2());
	}
}
signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; i++)scanf("%d", &x[i]);
	for(int i = 1; i <= m; i++)scanf("%d", &y[i]);
	go();
	while(q--){
		int kx, ky;
		scanf("%d%d", &kx, &ky);
		for(int i = 1; i <= kx; i++){
			scanf("%d%d", &px[i], &vx[i]);
			swap(vx[i], x[px[i]]);
		}
		for(int i = 1; i <= ky; i++){
			scanf("%d%d", &py[i], &vy[i]);
			swap(vy[i], y[py[i]]);
		}
		go();
		for(int i = 1; i <= kx; i++)swap(vx[i], x[px[i]]);
		for(int i = 1; i <= ky; i++)swap(vy[i], y[py[i]]);
	}
	return 0;
}

