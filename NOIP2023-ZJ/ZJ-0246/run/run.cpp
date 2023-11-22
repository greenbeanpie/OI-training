#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
	return x * f;
}

const int N = 2e3 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int n, m, k, d;

int s[N][N], f[N][N];

inline void chmax(int &x, int v) {x = max(x, v);}

inline void solve() {
	n = read(); m = read(); k = read(); d = read();
	memset(s, 0, sizeof s);
	for (int i = 1, x, y, v; i <= m; ++ i) {
		x = read(), y = read(); v = read();
		s[x][y] += v;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			s[i][j] += s[i][j-1];
	memset(f, 0xcf, sizeof f); f[0][0] = 0;
	for (int i = 0; i < n; ++ i) 
		for (int j = 0; j <= i && j <= k; ++ j) {
			if (j + 1 <= k) chmax(f[i+1][j+1], f[i][j] - d + s[i+1][j+1]);
			chmax(f[i+1][0], f[i][j] + s[i+1][0]); 
		} 	
	int ans = -inf;
	for (int i = 0; i <= n && i <= k; ++ i) chmax(ans, f[n][i]);
	printf("%lld\n", ans);
}

signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int tid = read(), T = read();
	while (T --) solve();
	return 0;
}
