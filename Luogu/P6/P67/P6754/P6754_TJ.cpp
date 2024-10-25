#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, f[25][15][15], a[25];

ll dfs(ll pos, bool limit, bool lead, ll pre1, ll pre2)
{
	if (!pos)
	{
		return 1;
	}
	ll ans = 0;
	if (!limit && !lead && f[pos][pre1 + 1][pre2 + 1] != -1)
	{
		return f[pos][pre1 + 1][pre2 + 1];
	}
	ll up = limit ? a[pos] : 9;
	for (ll i = 0; i <= up; ++i)
	{
		if (i != pre1 && i != pre2)
		{
			ans += dfs(pos - 1, limit && i == up, lead && !i, (!lead || i) ? i : -1, pre1);
		}
	}
	if (!limit && !lead)
	{
		f[pos][pre1 + 1][pre2 + 1] = ans;
	}
	return ans;
}

ll solve(ll x)
{
	ll cnt = 0;
	while (x)
	{
		a[++cnt] = x % 10;
		x /= 10;
	}
	memset(f, -1, sizeof(f));
	return dfs(cnt, 1, 1, -1, -1);
}

int main()
{
	scanf("%lld%lld", &l, &r);
	printf("%lld", solve(r) - solve(l - 1));
	return 0;
}
