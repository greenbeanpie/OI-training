#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 10, maxN = 5e5 + 10;

bool f[maxn][maxn], ans[maxN];
int c, n, m, q, x[maxN], y[maxN], tx[maxn], ty[maxn], p[2][maxN], v[2][maxN];

int calc() {
	bool op = tx[1] > ty[1]; f[1][1] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1 + (i == 1); j <= m; j ++)
			if ((tx[i] ^ ty[j]) && (tx[i] > ty[j]) == op)
				f[i][j] = f[i - 1][j] | f[i][j - 1];
			else f[i][j] = 0;
	return f[n][m];
}

int main() {
	
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	scanf("%d %d %d %d", &c, &n, &m, &q);
	for (int i = 1; i <= n; i ++) scanf("%d", &x[i]), tx[i] = x[i];
	for (int i = 1; i <= m; i ++) scanf("%d", &y[i]), ty[i] = y[i];
	
	ans[0] = calc();
	for (int i = 1; i <= q; i ++) {
		int lx, ly;
		scanf("%d %d", &lx, &ly);
		
		for (int j = 1; j <= lx; j ++)
			scanf("%d %d", &p[0][j], &v[0][j]), 
			tx[p[0][j]] = v[0][j];
		
		for (int j = 1; j <= ly; j ++)
			scanf("%d %d", &p[1][j], &v[1][j]), 
			ty[p[1][j]] = v[1][j];
		
		ans[i] = calc();
		for (int j = 1; j <= lx; j ++) tx[p[0][i]] = x[p[0][i]];
		for (int j = 1; j <= ly; j ++) ty[p[1][i]] = y[p[1][i]];
	}
	
	for (int i = 0; i <= q; i ++) printf("%d", ans[i]);
}


// 求求了不要挂分...
// 25pts
