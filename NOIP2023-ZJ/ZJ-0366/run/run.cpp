//lyxhsx
#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, k, d;
long long ans;
int main ()
{
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	cin >> c >> t;
	if (c == 1 || c == 2)
	{
		while (t --)
		{
			cin >> n >> m >> k >> d;
			ans = 0;
			int l[107], r[107], v[107];
			for (int i = 1; i <= m; ++ i)
				cin >> l[i] >> r[i] >> v[i];
			for (int i = 0; i < (1 << n); ++ i)
			{
				int a[20] = {0};
				long long s = 0;
				for (int j = 1; j <= n; ++ j)
					if (i & (1 << j - 1))
						a[j] = 1, -- s;
				int p = 0;
				for (int j = 1; j <= n; ++ j)
				{
					if (a[j])
						++ p;
					else
						p = 0;
					if (p == k + 1)
						break;
				}
				if (p == k + 1)
					continue;
				for (int j = 1; j <= n; ++ j)
					a[j] += a[j - 1];
				for (int j = 1; j <= m; ++ j)
					if (a[l[j]] - a[l[j] - r[j]] == r[j])
						s += max (0ll, 1ll * v[j]);
				ans = max (ans, s);
			}
			cout << ans << '\n';
		}
	}
	if (c == 17 || c == 18)
	{
		while (t --)
		{
			cin >> n >> m >> k >> d;
			ans = 0;
			for (int i = 1, l, r, v; i <= m; ++ i)
			{
				cin >> l >> r >> v;
				if (r > k || l - r + 1 <= 0)
					continue;
				if (r * 1ll * d < v)
					ans += v * 1ll - r * 1ll * d;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}