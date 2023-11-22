#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e3 + 100;
const int M = 1e5;
ll T, c, n, m, k, d, f[N][N]; 

struct Challenge {
	int x, y, ene;
}cha;

signed main ()
{
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);

	scanf ("%lld %lld", &c, &T);
	while (T --)
	{
		scanf ("%lld %lld %lld %lld", &n, &m, &k, &d);
		for (int i = 1; i <= m; ++ i)
			scanf ("%lld %lld %lld", &cha[i].x, &cha[i].y, &cha[i].ene);
		for (int i = 1; i <= n; ++ i)
		{
			for (int j = 1; j <= n; ++ j)
			{
				for (int q = 1; q <= n; q ++)
				{
					f[i][j] = max (f[i][j], f[i][q] + f[q + 1][j])
				}
			}
		}
	}
	return 0;
}

