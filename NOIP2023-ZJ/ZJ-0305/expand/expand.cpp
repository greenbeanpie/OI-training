#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int sum = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + (ch ^ 48);
	return sum * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
	return;
}
const int N = 2e3 + 10;
int c, n, m, q, kx, ky, x[N], y[N], a[N], b[N], dp[N][N];
bool check(){
	if(x[1] == y[1]) return 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			dp[i][j] = 0;
	if(x[1] < y[1]){
		dp[1][1] = 1;
		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j){
				if(i == 1 && j == 1) continue;
				if(x[i] < y[j]) dp[i][j] |= dp[i - 1][j - 1];
				if(i != 1 && x[i - 1] < y[j]) dp[i][j] |= dp[i - 1][j];
				if(j != 1 && x[i] < y[j - 1]) dp[i][j] |= dp[i][j - 1];
			}
		}
		return dp[n][m];
	}else if(x[1] > y[1]){	
			for(int j = 1; j <= m; ++ j){
				if(i == 1 && j == 1) continue;
				if(x[i] < y[j]) dp[i][j] |= dp[i - 1][j - 1];
				if(i != 1 && x[i - 1] < y[j]) dp[i][j] |= dp[i - 1][j];
				if(j != 1 && x[i] < y[j - 1]) dp[i][j] |= dp[i][j - 1];
			}
		}
		return dp[n][m];
	}        
	return 1;
}
signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	for(int i = 1; i <= m; ++ i) b[i] = read();
	for(int i = 1; i <= n; ++ i) x[i] = a[i];
	for(int i = 1; i <= m; ++ i) y[i] = b[i];
	putchar(check() ? '1' : '0');
//	cout << "\n";
	while(q --){
		for(int i = 1; i <= n; ++ i) x[i] = a[i];
		for(int i = 1; i <= m; ++ i) y[i] = b[i];
		kx = read(), ky = read();
		for(int i = 1; i <= kx; ++ i)
			x[read()] = read();
		for(int i = 1; i <= ky; ++ i)
			y[read()] = read();
//		for(int i = 1; i <= n; ++ i) cout << x[i] << " ";
//		cout << "\n";
//		for(int i = 1; i <= m; ++ i) cout << y[i] << " ";
//		cout << "\n";
		putchar(check() ? '1' : '0');
//		cout << "\n";
	}
	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7
*/