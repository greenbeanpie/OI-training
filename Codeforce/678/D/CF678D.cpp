#include <bits/stdc++.h>
using namespace std;
#define int long long
#define int128 __int128
int m=1e9+7, a, c, x0, n, g=1e9+7;
#define max_matrix 2
struct matrix
{
	int128 mat[max_matrix + 1][max_matrix + 1];
	matrix(){
		memset(mat,0,sizeof(mat));
	}
	int128 *operator[](const int &x) { return mat[x]; }
	void init()
	{
		for (int i = 0; i <= max_matrix; i++)
		{
			mat[i][i] = 1;
		}
	}
};
matrix operator*(matrix a, matrix b)
{
	matrix c;
	for (int i = 1; i <= max_matrix; i++)
	{
		for (int j = 1; j <= max_matrix; j++)
		{
			for (int k = 1; k <= max_matrix; k++)
			{
				c.mat[i][j] = (c[i][j] % m + (a[i][k] * b[k][j]) % m) % m;
			}
		}
	}
	return c;
}
matrix operator%(matrix a, int b)
{
	for (int i = 1; i <= max_matrix; i++)
	{
		for (int j = 1; j <= max_matrix; j++)
		{
			a.mat[i][j] = a.mat[i][j] % b;
		}
	}
	return a;
}
matrix base, ans;
void mquickpower(int b)
{
	while (b)
	{
		if (b & 1)
		{
			ans = ans * base;
		}
		base = base * base;
		b >>= 1;
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("CF678D.in", "r", stdin);
	freopen("CF678D.out", "w", stdout);
#endif
	cin >>a >> c >> n >> x0;
	if (n == 0)
	{
		cout << x0 % g;
		return 0;
	}

	ans[1][1] = x0, ans[1][2] = 1;
	base[1][1] = a, base[1][2] = 0, base[2][1] = c, base[2][2] = 1;
	mquickpower(n);
	cout << (long long)ans.mat[1][1] % g;
	return 0;
}