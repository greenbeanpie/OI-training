#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 3010;

ll n, m, maxn[N], ans[N];
ll allmaxin = 27, maxpi = 0;
ll allmax = 0, allmin = 27, maxp = 0, minp = 0;

char s[N][N];

inline ll chr (char c)
{
	return (ll (c) - 96);
}

signed main ()
{
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);

	scanf ("%lld %lld", &n, &m);
	getchar ();
	for (ll i = 1; i <= n; ++ i)
	{
		for (ll j = 1; j <= m; j ++)
			scanf ("%c", &s[i][j]);
		getchar ();
	}
	for (ll i = 1; i <= n; ++ i)
	{
		maxn[i] = 0, minn[i] = 27;
		for (ll j = 1; j <= m; ++ j)
		{
			int ch = chr (s[i][j]);
			if (ch >= maxn[i]) 
				maxn[i] = ch;
		}	
	}
	for (ll i = 1; i <= n; ++ i)
		for (ll j = 1; j <= m; ++ j)
			if (maxn[i] <= allmaxin) 
				allmaxin = maxn[i], maxpi = i;
	for (ll i = 1; i <= n; ++ i)
	{
		if (i != maxpi && minn[i] >= allmaxin)
			ans[i] = 0;				
		else
			ans[i] = 1;
		
	}
	for (ll i = 1; i <= n; ++ i)
		printf ("%lld", ans[i]);
	return 0;
}

