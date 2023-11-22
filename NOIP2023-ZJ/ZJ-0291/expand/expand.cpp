#include <bits/stdc++.h>
using namespace std;
int c, n, m, q, f[2][2010][2010], X[2010], Y[2010], SX[2010], SY[2010], D;
struct node
{
	int x, y, v;
}chall[100010];
void Fre()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	return;
}
void Read()
{
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) scanf("%d", &SX[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &SY[i]);
	if (n >= 600) D = 1000;
	else D = 600;
	return;
}
void Revise()
{
	for (int i = 1; i <= n; i++) X[i] = SX[i];
	for (int i = 1; i <= n; i++) Y[i] = SY[i];
	int kx, ky, x, y;
	scanf("%d %d", &kx, &ky);
	for (int i = 1; i <= kx; i++)
	{
		scanf("%d %d", &x, &y);
		X[x] = y;
	}
	for (int i = 1; i <= ky; i++)
	{
		scanf("%d %d", &x, &y);
		Y[x] = y;
	}
	return;
}
bool Work1()
{
	if (X[1] <= Y[1] || X[n] <= Y[n]) return 0;
	memset(f[1], 0, sizeof(f[1]));
	f[1][1][1] = (X[1] > Y[1]);
	for (int i = 2; i <= D; i++)
	{
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (X[j] > Y[k])
					f[i & 1][j][k] = f[i & 1 ^ 1][j][k] | f[i & 1 ^ 1][j - 1][k] | f[i & 1 ^ 1][j][k - 1] | f[i & 1 ^ 1][j - 1][k - 1];
				else f[i & 1][j][k] = 0;
	}
	return f[0][n][n];
}
bool Work2()
{
	if (X[1] >= Y[1] || X[n] >= Y[n]) return 0;
	memset(f[1], 0, sizeof(f[1]));
	f[1][1][1] = (X[1] < Y[1]);
	for (int i = 2; i <= D; i++)
	{
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (X[j] < Y[k])
					f[i & 1][j][k] = f[i & 1 ^ 1][j][k] | f[i & 1 ^ 1][j - 1][k] | f[i & 1 ^ 1][j][k - 1] | f[i & 1 ^ 1][j - 1][k - 1];
				else f[i & 1][j][k] = 0;
	}
	return f[0][n][n];
}
signed main()
{
	Fre();
	Read();
	for (int i = 1; i <= n; i++) X[i] = SX[i];
	for (int i = 1; i <= n; i++) Y[i] = SY[i];
	printf("%d", (Work1() || Work2()));
	for (; q; q--)
	{
		Revise();
		printf("%d", (Work1() || Work2()));
	}
	return 0;
}