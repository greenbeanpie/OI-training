#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
bitset<N> mp[N];
int prefix[N][N];

signed main()
{
	freopen("wu.in", "r", stdin);
	freopen("wu.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> temp;
			if (temp)
			{
				mp[i][j] = 1;
			}
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mp[i][j];
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mp[i][j])
			{
				continue;
			}
			for (int k = i - 1; k >= 1; k--)
			{
				if (mp[k][j])
				{
					continue;
				}
				for (int f = j - 1; f >= 1; f--)
				{
					if (mp[i][f])
					{
						continue;
					}
					if (!mp[k][f])
					{
						continue;
					}
					int cnt = prefix[i][j] - prefix[i][k - 1] - prefix[j][f - 1] + prefix[k - 1][f - 1];
					int len = sqrt(cnt);
					if (len * len != cnt)
					{
						continue;
					}
					if (prefix[k + cnt - 1][f + cnt - 1] - prefix[k + cnt - 1][f - 1] - prefix[k - 1][f + cnt - 1] + prefix[k - 1][f - 1] == cnt)
					{
						++res;
					}
				}
			}
		}
	}
	cout << res*2-1 << endl;

	return 0;
}
