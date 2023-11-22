#include<bits/stdc++.h>
using namespace std;

int cnt, n, m, id[6010], ans[6010], sum[6010];
string s[6010];

signed main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cnt = 1;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		id[i] = i;
		id[i + n] = i + n;
		s[i + n] = s[i];
		sort(s[i + n].begin(), s[i + n].end());
		s[i] = s[i + n];
		reverse(s[i].begin(), s[i].end());
	}
	sort(id + 1, id + 2 * n + 1, [](int x, int y)
	{
		if (s[x] == s[y])
		return id[x] > id[y];
		return s[x] < s[y];
	});
	for (int i = 2 * n;i >= 1;i--)
	{
		sum[i] = sum[i + 1] + (id[i] <= n);
	}
	for (int i = 1;i <= 2 * n;i++)
	if (id[i] > n)
	{
		if (sum[i] == n)
		{
			ans[id[i] - n] = 1;
		}
	}
	for (int i = 1;i <= n;i++)
	cout << ans[i];
}
