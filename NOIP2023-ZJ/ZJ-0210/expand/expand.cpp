#include <bits/stdc++.h>
using namespace std;
int read() {
	char ch;
	
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		;
	
	int res = 0;
	
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		res = (res << 1) + (res << 3) + (ch - 48);
	
	return res;
}

int c, n, m, q, a[600000], b[600000], a1[600000], b1[600000], px[600000], py[600000];
int f[5000][5000];
void solve() {
	if (a[1] > b[1]) {
		memset(f, 0, sizeof(f));
		f[1][1] = 1;
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i] > b[j])
					f[i][j] = f[i][j] || f[i][j - 1] || f[i - 1][j];
		
		if (f[n][m])
			printf("1");
		else
			printf("0");
	}
	
	if (a[1] < b[1]) {
		memset(f, 0, sizeof(f));
		f[1][1] = 1;
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i] < b[j])
					f[i][j] = f[i][j] || f[i][j - 1] || f[i - 1][j];
		
		if (f[n][m])
			printf("1");
		else
			printf("0");
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d %d %d %d", &c, &n, &m, &q);
	
	for (int i = 1; i <= n; i++)
		a[i] = a1[i] = read();
	
	for (int i = 1; i <= m; i++)
		b[i] = b1[i] = read();
	
	solve();
	
	for (int i = 1; i <= q; i++) {
		int kx = read();
		int ky = read();
		
		for (int j = 1; j <= kx; j++) {
			px[j] = read();
			int vx = read();
			a[px[j]] = vx;
		}
		
		for (int j = 1; j <= ky; j++) {
			py[j] = read();
			int vy = read();
			b[py[j]] = vy;
		}
		
		solve();
		
		for (int j = 1; j <= kx; j++)
			a[px[j]] = a1[px[j]];
		
		for (int j = 1; j <= ky; j++)
			b[py[j]] = b1[py[j]];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}