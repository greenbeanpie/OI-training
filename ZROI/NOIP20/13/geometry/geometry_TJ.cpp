#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int t, n, na, nb;
long long f[N][55], pos, tmp;
char s[N], a[N], b[N];
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("geometry.in", "r", stdin);
		freopen("geometry_TJ.out", "w", stdout);
	#endif
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s%s", s + 1, a + 1, b + 1),
			n = strlen(s + 1), na = strlen(a + 1), nb = strlen(b + 1);
		for (int i = 0; i <= n; i++)
			for (int j = 1; j <= na; j++)
				f[i][j] = 0;
		f[0][na] = 1ll << nb;
		for (int i = 1; i <= n; i++)
		{
			tmp = 0;
			for (int y = 1; y < nb; y++)
				if (s[i] == b[y + 1])
					tmp |= 1ll << y;
			for (int x = 1; x <= na; x++)
			{
				int nx = x < na ? x + 1 : 1;
				if (s[i] == a[nx])
					f[i][nx] |= f[i - 1][x];
				f[i][x] |= (f[i - 1][x] & tmp) << 1;
				if (s[i] == b[1] && (f[i - 1][x] >> nb & 1))
					f[i][x] |= 1 << 1;
			}
		}
		puts(f[n][na] >> nb & 1 ? "Yes" : "No");
	}
	return 0;
}
