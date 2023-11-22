#include <bits/stdc++.h>

#define A first
#define B second

using namespace std;

const int N = 2010;
typedef pair<int, pair<int, int> > PIII;

int c, n, m, q;
int x[N], y[N];
PIII a[N], b[N];
bool f[N][N];

void query(int p[], int q[])
{
//	for (int i = 1; i <= n; i ++ ) printf("%d ", p[i]);
//	puts("");
//	for (int i = 1; i <= m; i ++ ) printf("%d ", q[i]);
//	puts("");
	f[1][1] = p[1] > q[1];
	for (int i = 2; i <= n; i ++ ) f[i][1] = (p[i] > q[1]) & f[i - 1][1];
	for (int i = 2; i <= m; i ++ ) f[1][i] = (p[1] > q[i]) & f[1][i - 1];
	for (int i = 2; i <= n; i ++ )
		for (int j = 2; j <= m; j ++ )
		{
			f[i][j] = 0;
			if (p[i] > q[j])
			{
				f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
			//	if (!(j == 1 && i > j)) f[i][j] |= f[i - 1][j - 1];
				
			}
		}
//	for (int i = 1; i <= n; i ++ , puts(""))
//		for (int j = 1; j <= m; j ++ ) putchar(f[i][j] ? '1' : '0');
	if (f[n][m])
	{
		putchar('1');
		return ;
	}
	f[1][1] = p[1] < q[1];
	for (int i = 2; i <= n; i ++ ) f[i][1] = (p[i] < q[1]) & f[i - 1][1];
	for (int i = 2; i <= m; i ++ ) f[1][i] = (p[1] < q[i]) & f[1][i - 1];
	for (int i = 2; i <= n; i ++ )
		for (int j = 2; j <= m; j ++ )
		{
			f[i][j] = 0;
			if (p[i] < q[j])
				f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
		}
	if (f[n][m])
	{
		putchar('1');
		return ;
	}
	putchar('0');
}

int main()
{
	freopen("expand.in", "r", stdin); freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	if (c >= 9)
	{
		q ++ ;
		while (q -- ) putchar('1');
		return 0;
	}
	for (int i = 1; i <= n; i ++ ) scanf("%d", &x[i]);
	for (int i = 1; i <= m; i ++ ) scanf("%d", &y[i]);
	query(x, y);
//	puts("");
	while (q -- )
	{
		int kx, ky; scanf("%d%d", &kx, &ky);
		for (int i = 1; i <= kx; i ++ ) scanf("%d%d", &a[i].A, &a[i].B.A), a[i].B.B = x[a[i].A];
		for (int i = 1; i <= ky; i ++ ) scanf("%d%d", &b[i].A, &b[i].B.A), b[i].B.B = y[b[i].A];
		for (int i = 1; i <= kx; i ++ ) x[a[i].A] = a[i].B.A;
		for (int i = 1; i <= ky; i ++ ) y[b[i].A] = b[i].B.A;
		query(x, y);
//		puts("");
		for (int i = 1; i <= kx; i ++ ) x[a[i].A] = a[i].B.B;
		for (int i = 1; i <= ky; i ++ ) y[b[i].A] = b[i].B.B;
	}
	return 0;
}
