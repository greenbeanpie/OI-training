#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

cc_hash_table<int, int> dp[20][20];

int len(int x)
{
	if (!x)
		return x;
	return log10(x) + 1;
}

int getfirst(int x)
{
	if (!x)
		return x;
	int len = log10(x);
	return x / pow(10, len);
}

int gettail(int x)
{
	return x - getfirst(x) * pow(10, len(x) - 1);
}

int fail[20][10];

int reset = 0;

int dfs(int left, int pos, int up, int cnt, string s, bool limit)
{
	if (!limit && dp[left][pos][cnt])
	{
		return dp[left][pos][cnt];
	}
	int res = 0;
	if (pos == s.size())
	{
		pos = reset;
		--cnt;
	}
	if (cnt < 0)
	{
		dp[left][pos][cnt] = 0;
		return 0;
	}
	if (!left)
	{
		if (!cnt)
		{
			return 1;
		}
		return 0;
	}
	for (int i = 0; i <= (limit ? getfirst(up) - 1 : 9); i++)
	{
		if (s[pos] - '0' == i)
		{
			res += dfs(left - 1, pos + 1, -1, cnt, s, 0);
		}
		else
		{
			res += dfs(left - 1, fail[pos][i], -1, cnt, s, 0);
		}
	}
	if (limit)
	{
		if (getfirst(up) == s[pos] - '0')
		{
			res += dfs(left - 1, pos + 1, gettail(up), cnt, s, 1);
		}
		else
		{
			res += dfs(left - 1, fail[pos][getfirst(up)], gettail(up), cnt, s, 1);
		}
	}
	else
	{
		dp[left][pos][cnt] = res;
	}
	return res;
}

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int l, r, k;
	string s;
	cin >> l >> r >> s >> k;

	for (int i = 1; i < s.size(); i++)
	{
		bool flag = 1;
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != s[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			reset = s.size() - i;
		}
	}

	for (int i = 1; i <= s.size(); i++)
	{
		int c = s[i - 1] - '0';
		for (int j = 0; j < 9; j++)
		{
			for (int f = 0; f < i; f++)
			{
				if (s[f] - '0' == j)
				{
					fail[i - 1][j] = f;
				}
			}
		}
	}

	for (int i = 0; i <= k; i++)
	{
		cout << dfs(len(r), 0, r, i, s, 1) - dfs(len(l - 1), 0, l - 1, i, s, 1) << " ";
	}

	return 0;
}
