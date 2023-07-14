#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
ll a[25][25];
map<ll, ll> dict[25][25];
ll ans = 0;

void dfs1(ll x, ll y, ll v)
{
	v ^= a[x][y];
	if (x + y == (n + m + 2) / 2)
	{
		dict[x][y][v]++;
		return;
	}
	if (x < n)
		dfs1(x + 1, y, v);
	if (y < m)
		dfs1(x, y + 1, v);
}
void dfs2(ll x, ll y, ll v)
{
	if (x + y == (n + m + 2) / 2)
	{
		if (dict[x][y].count(v ^ k))
			ans += dict[x][y][v ^ k];
		return;
	}
	v ^= a[x][y];
	if (x > 1)
		dfs2(x - 1, y, v);
	if (y > 1)
		dfs2(x, y - 1, v);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	dfs1(1, 1, 0);
	dfs2(n, m, 0);
	cout << ans << "\n";
	return 0;
}
