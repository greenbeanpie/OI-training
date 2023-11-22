#include <bits/stdc++.h>
#define FL(i, a, b) for(register int i = (a); i <= (b); ++i)
#define FR(i, a, b) for(register int i = (a); i >= (b); --i)
using namespace std;
constexpr int N = 2010;
int n, m, q, x[N], y[N], a[N], b[N], f[N][N];
inline int Dp(){
	f[1][1] = (a[1] < b[1]);
	FL(i, 1, n) FL(j, 1, m) if(i > 1 || j > 1){
		f[i][j] = (a[i] < b[j] && (f[i][j - 1] || f[i - 1][j] || f[i - 1][j - 1]));
	}
	if(f[n][m]) return 1;
	f[1][1] = (a[1] > b[1]);
	FL(i, 1, n) FL(j, 1, m) if(i > 1 || j > 1){
		f[i][j] = (a[i] > b[j] && (f[i][j - 1] || f[i - 1][j] || f[i - 1][j - 1]));
	}
	return f[n][m];
}
inline void Copy(){
	FL(i, 1, n) a[i] = x[i];
	FL(i, 1, m) b[i] = y[i];
}
inline void Solve(){
	scanf("%d%d%d", &n, &m, &q);
	FL(i, 1, n) scanf("%d", &x[i]);
	FL(i, 1, m) scanf("%d", &y[i]);
	Copy(), putchar('0' + Dp());
	while(q--){
		int kx, ky, p, v;
		scanf("%d%d", &kx, &ky), Copy();
		FL(i, 1, kx) scanf("%d%d", &p, &v), a[p] = v;
		FL(i, 1, ky) scanf("%d%d", &p, &v), b[p] = v;
		putchar('0' + Dp());
	}
}
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int C; scanf("%d", &C); Solve();
	return 0;
}