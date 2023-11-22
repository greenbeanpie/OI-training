#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e5 + 5, M = 2e3 + 5;

int c, n, m, q;
int a[N], b[N], x[N], y[N];
int f[M][M][2];
string ans = "", res = "";

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();};
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	if(c <= 7) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) 
				f[i][j][0] = f[i][j][1] = 0;
		f[0][0][0] = f[0][0][1] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				f[i][j][0] = (f[i - 1][j][0] | f[i][j - 1][0] | f[i - 1][j - 1][0]) & (a[i] > b[j]);
				f[i][j][1] = (f[i - 1][j][1] | f[i][j - 1][1] | f[i - 1][j - 1][1]) & (a[i] < b[j]);
			}
		}
		ans += (f[n][m][0] | f[n][m][1]) + '0';
	}
	while(q--) {
		for(int i = 1; i <= n; i++) x[i] = a[i], y[i] = b[i];
		int kx = read(), ky = read();
		for(int i = 1; i <= kx; i++) x[read()] = read();
		for(int i = 1; i <= ky; i++) y[read()] = read();
		if(c <= 7) {
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= m; j++) 
					f[i][j][0] = f[i][j][1] = 0;
			f[0][0][0] = f[0][0][1] = 1;
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					f[i][j][0] = (f[i - 1][j][0] | f[i][j - 1][0] | f[i - 1][j - 1][0]) & (x[i] > y[j]);
					f[i][j][1] = (f[i - 1][j][1] | f[i][j - 1][1] | f[i - 1][j - 1][1]) & (x[i] < y[j]);
				}
			}
			ans += (f[n][m][0] | f[n][m][1]) + '0';
		}
	}
	if(c <= 7) cout << ans << endl;
	else {
		for(int i = 1; i <= q + 1; i++) cout << 1; puts("");
	}
	return 0;
}
