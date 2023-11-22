#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e3 + 100;
ll c, t, n, m, a[N], stk[N][10], f[N], ans; 

char op[N];

inline void solve ()
{
	ll tempa[N], tempb[N];
	scanf ("%lld %lld", &n, &m);
	for (int i = 1; i <= n; ++ i)
		a[i] = 2;
	for (int i = 1; i <= m; ++ i)
	{
		scanf ("%c", &op[i]);
		if (op[i] == '-')
		{
			scanf ("%lld %lld", &tempa[i], &tempb[i]);
		}
		if (op[i] == '+')
		{
			scanf ("%lld %lld", &tempa[i], &tempb[i]);
		}
		if (op[i] == 'T')
		{
			scanf ("%lld", &tempa[i]);
			a[tempa[i]] = 1;
			f[tempa[i]] = 1;
		}
		if (op[i] == 'U')
		{
			scanf ("%lld", &tempa[i]);
			a[tempa[i]] = 0;
			f[tempa[i]] = 0;
		}
		if (op[i] == 'F')
		{
			scanf ("%lld", &tempa[i]);
			a[tempa[i]] = -1;
			f[tempa[i]] = -1;
		}
	}
	for (int i = m; i >= 1; i --)
	{
		if (op[i] == '-')
		{
			if (stk[tempa[i]][0] == 0)
				stk[tempa[i]][++ stk[tempa[i]][0]] = tempb[i];
			else
				stk[tempa[i]][stk[tempa[i]][0]] = -tempb[i];
		}
		if (op[i] == '+')
		{
			if (stk[tempa[i]][0] == 0)
				stk[tempa[i]][++ stk[tempa[i]][0]] = tempb[i];
			else
				stk[tempa[i]][stk[tempa[i]][0]] = tempb[i];
		}
	}
	for (int i = 1; i <= n; ++ i)
	{
		if (stk[tempa[i]][stk[tempa[i]][0]] != 0 && f[i] != 0 && f[i] != stk[tempa[i]][stk[tempa[i]][0]])
			ans ++;
		if (stk[tempa[i]][stk[tempa[i]][0]] == 0)
			ans ++;
	}
	return ;
}

signed main ()
{
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);

	scanf ("%lld %lld", &c, &t);
	while (t --)
		solve ();
	cout << ans;
	return 0;
}

