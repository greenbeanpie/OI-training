#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define endl '\n'

char mp[205][205];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("crub.in", "r", stdin);
	freopen("crub.out", "w", stdout);
#endif
	int T;
	cin >> T;

	while (T--)
	{
		int a; // 长
		int b; // 宽
		int c; // 高
		cin >> a >> b >> c;
		fill(mp[0], mp[0] +205*205, 0);
		for (int i = 1; i <= b * 2; i++)
		{
			int len = b * 2 - i + 1;
			for (int j = 1; j <= len; j++)
			{
				mp[i][j - 1] = '.';
			}
			if (i % 2)
			{
				for (int j = 1; j <= a * 2 + 1; j++)
				{
					if (j % 2)
					{
						mp[i][len + j - 1] = '+';
					}
					else
					{
						mp[i][len + j - 1] = '-';
					}
				}
				for (int j = len + a * 2 + 1; j <= (((a + b) << 1) | 1); j++)
				{
					mp[i][j - 1] = (j % 2 ? '+' : '.');
				}
			}
			else
			{
				for (int j = 1; j <= a * 2 + 1; j++)
				{
					if (j % 2)
					{
						mp[i][len + j - 1] = '/';
					}
					else
					{
						mp[i][len + j - 1] = '.';
					}
				}
				for (int j = len + a * 2 + 1; j <= (((b + a) << 1) | 1); j++)
				{
					mp[i][j - 1] = (j % 2 ? '|' : '/');
				}
			}
		}
		for (int i = 1; i <= ((c << 1) | 1); i++)
		{
			for (int j = 1; j <= ((a << 1) | 1); j++)
			{
				if (i % 2)
				{
					if (j % 2)
					{
						mp[i + b * 2][j - 1] = '+';
					}
					else
					{
						mp[i + b * 2][j - 1] = '-';
					}
				}
				else
				{
					if (j % 2)
					{
						mp[i + b * 2][j - 1] = '|';
					}
					else
					{
						mp[i + b * 2][j - 1] = '.';
					}
				}
			}
			for (int j = ((a << 1) | 1) + 1; j <= (((b + a) << 1) | 1); j++)
			{
				if (i % 2)
				{
					mp[i + b * 2][j - 1] = (j % 2 ? '+' : '.');
				}
				else
				{
					mp[i + b * 2][j - 1] = (j % 2 ? '|' : '/');
				}
			}
		}
		for (int i = ((c << 1) | 1); i <= (((b + c) << 1) | 1); i++)
		{
			for (int j = 1; j <= ((((b + c) << 1) | 1) - ((c << 1) | 1)) - ((((b + c) << 1) | 1) - i); j++)
			{
				mp[i][(((a +b) << 1) | 1) - j] = '.';
			}
		}
		for (int i = 1; i <= (((b + c) << 1) | 1); i++)
		{
			cout << mp[i] << endl;
		}
	}

	return 0;
}